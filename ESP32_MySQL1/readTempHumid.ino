void readTempHumid(){
  temp = dht.readTemperature();  //อ่านค่าอุณหภูมิ
  humid = dht.readHumidity();    //อ่านค่าความชื้น
  if(isnan(temp) || isnan(humid)){ 
    Serial.println("Failed to read from DHT sensor!!!");
    return;
  }
}
