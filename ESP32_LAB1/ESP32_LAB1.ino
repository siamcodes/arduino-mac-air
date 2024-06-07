#include <WiFi.h>
#include <HTTPClient.h>

int LED_BUILTIN = 2;

const char WIFI_SSID[] = "A12";
const char WIFI_PASSWORD[] = "42117622";

//String HOST_NAME = "http://192.168.13.191"; // change to your PC's IP address ต้องอยู่ในวงแลนเดียวกันกับ ESP32
//String PATH_NAME   = "/esp32/insert_temp.php";
//String queryString = "?temperature=30.5";

void setup() {
  Serial.begin(9600); 
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String url = "http://192.168.13.191/esp32/insert_temp.php?temp=40.50";
  Serial.println();
  Serial.println("Get content from " + url);

  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode == 200) {
    String content = http.getString();
    Serial.println("Content ---------");
    Serial.println(content);
    Serial.println("-----------------");
  } else {
    Serial.println("Fail. error code " + String(httpCode));
  }
  Serial.println("END");
  
//  HTTPClient http;
//
//  http.begin(HOST_NAME + PATH_NAME + queryString); //HTTP
//  int httpCode = http.GET();
//
//  // httpCode will be negative on error
//  if(httpCode > 0) {
//    // file found at server
//    if(httpCode == HTTP_CODE_OK) {
//      String payload = http.getString();
//      Serial.println(payload);
//    } else {
//      // HTTP header has been send and Server response header has been handled
//      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
//    }
//  } else {
//    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//  }
//
//  http.end();
}

void loop() {

}
