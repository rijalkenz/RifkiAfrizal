#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Data SSID dan Password 
const char* ssid     = "🙃";
const char* password = "abcdefghi";     

// Membuat variable wifiStatus utk menyimpan data status wifi
int wifiStatus; 

// Membuat web server pada port 80
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(200);

  // Mencetak status terkoneksi dengan nama Wifi     
  Serial.println();
  Serial.println();
  Serial.print("Terkoneksi dengan Wifi : ");
  Serial.println(ssid);
    
  WiFi.begin(ssid, password);
      
  // Ketika WiFI.status tidak sama dengan WL_CONNECTED, ulangi sampai terkoneksi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Jika berhasil terkoneksi
  Serial.println("");
  Serial.println("ESP8266 sudah terkoneksi dengan Wifi!");  
  Serial.println("IP address ESP8266 : ");
  Serial.println(WiFi.localIP());  

  // Rute utama untuk menampilkan tulisan Rijal dan Bayu
  server.on("/", []() {
    server.send(200, "text/html", "<h1>Rijal</h1><h2>Bayu</h2>");
  });

  // Memulai server
  server.begin();
  Serial.println("Web server dimulai, akses alamat IP ESP8266 di browser Anda.");
}

void loop() {
  // Mengecek status koneksi WiFi
  wifiStatus = WiFi.status();

  if(wifiStatus == WL_CONNECTED){
    Serial.println("WiFi terkoneksi");
  } else {
    Serial.println("WiFi tidak terkoneksi");
  }
      
  // Menjalankan web server
  server.handleClient();

  delay(1000); // Mengecek koneksi setiap satu detik
}
