#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
HTTPClient http;

const char ssid[] = "A12";
const char password[] = "42117622";

void readSensor();
String HOST_NAME = "http://192.168.221.191"; // REPLACE WITH YOUR PC's IP ADDRESS
String PHP_FILE_NAME   = "/esp32_dht22/insert_temperature.php";  //REPLACE WITH YOUR PHP FILE NAME
String temp = "?temp=" + String(t);
String humi = "&humi=" + String(h);

void setup() {
  dht.begin();  //เริ่มใช้งาน DHT22

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());


  String server = HOST_NAME + PHP_FILE_NAME + temp + humi;
  http.begin(server);
  int httpCode = http.GET();

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.printf("HTTP GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("HTTP GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
}

void loop() {
  readSensor();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } else {
    float hif = dht.computeHeatIndex(f, h);  // Compute heat index in Fahrenheit (the default)
    float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false)
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
  }
  delay(10000);
  http.end();
}
