void handleRoot(){
  readTempHumid();
  delay(200);
  counter++;   //เพิ่มค่า Counter ขึ้นสำหรับทดสอบดูการทำงาน

  //HTML ที่จะแสดงออกให้ Client
  String strHTML = "<!DOCTYPE html><html><head>";
  strHTML += "<meta charset=\"UTF-8\">";
  strHTML += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  strHTML += "<meta http-equiv=\"refresh\" content=\"3\" />";
  strHTML += "<title>ESP32-Webserver</title>";
  strHTML += "</head><body>";
  strHTML += "<h1> ESP32-DHT22-Web Server</h1>";
  
  strHTML += "</body></html>";
  server.send(200,"text/html", strHTML);
}
