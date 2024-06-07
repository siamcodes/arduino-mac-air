#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 23
#define DHTTYPE    DHT22 
DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "A12";      //Access point SSID และ Password
const char *password = "42117622";
WebServer server(80);

int counter = 0;     //ค่าตัวเลขสำหรับทดสอบ
float temp, humid;  //ค่าอุณหภูมิและความชื้นที่อ่านจาก DHT

void setup() {
  Serial.begin(115200);
  dht.begin();  
  Serial.println("DHT begins");  
  delay(1000);
  Serial.print("Config access point...");
  IPAddress myIP = WiFi.softAPIP();
  Serial.println("AP IP Address: ");
  Serial.print(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
