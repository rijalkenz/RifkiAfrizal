#include <ESP8266WiFi.h>
#include <espnow.h>

uint8_t broadcastAddress[] = {0x68, 0xC6, 0x3A, 0xD7, 0x63, 0xA2};  // Alamat MAC Perangkat 2

typedef struct struct_message {
  int nilai = 0;
} struct_message;

struct_message myData;

void onSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Status pengiriman: ");
  Serial.println(sendStatus == 0 ? "Sukses" : "Gagal");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Gagal menginisialisasi ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(onSent);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  // Menampilkan MAC Address perangkat ini
  Serial.print("MAC Address perangkat ini: ");
  Serial.println(WiFi.macAddress());

  // Mengirim data
  myData.nilai++;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

  delay(2000);  // Jeda 2 detik sebelum loop berikutnya
}