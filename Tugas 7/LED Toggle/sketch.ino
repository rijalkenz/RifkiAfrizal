// Import required libraries
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "🙃";
const char* password = "abcdefghi";

const int output = D4;

bool toggleState = false;

const char* PARAM_INPUT = "state";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP Web Server</title>
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 2.3rem;}
    body {max-width: 400px; margin: 0px auto; padding-bottom: 25px;}
    .toggle {position: relative; display: inline-block; width: 60px; height: 34px;}
    .toggle input {opacity: 0; width: 0; height: 0;}
    .slider {position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; transition: .4s;}
    .slider:before {position: absolute; content: ""; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; transition: .4s;}
    input:checked + .slider {background-color: #2196F3;}
    input:checked + .slider:before {transform: translateX(26px);}
    .slider.round {border-radius: 34px;}
    .slider.round:before {border-radius: 50%;}
  </style>
</head>
<body>
  <h2>ESP Web Server</h2>
  <p>Toggle State: <span id="toggleState">%TOGGLESTATE%</span></p>
  <label class="toggle">
    <input type="checkbox" onchange="updateToggleState(this)" id="toggleSwitch" %TOGGLECHECKED%>
    <span class="slider round"></span>
  </label>
<script>
function updateToggleState(element) {
  var toggleState = element.checked ? "1" : "0";
  document.getElementById("toggleState").innerHTML = toggleState == "1" ? "ON" : "OFF";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/toggle?state=" + toggleState, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

// Replaces placeholder with the toggle state in your web page
String processor(const String& var){
  if (var == "TOGGLESTATE"){
    return toggleState ? "ON" : "OFF";
  }
  else if (var == "TOGGLECHECKED") {
    return toggleState ? "checked" : "";
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(output, OUTPUT);
  digitalWrite(output, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Handle toggle state change
  server.on("/toggle", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      toggleState = (inputMessage == "1");
      digitalWrite(output, toggleState ? HIGH : LOW);
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("Toggle State: " + inputMessage);
    request->send(200, "text/plain", "OK");
  });
  
  // Start server
  server.begin();
}
  
void loop() {
  // Empty loop since logic is handled by async server
}