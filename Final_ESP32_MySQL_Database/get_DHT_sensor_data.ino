//  Subroutine to read and get data from the DHT11 sensor.
void get_DHT_sensor_data() {
  Serial.println();
  Serial.println("-------------get_DHT_sensor_data()");
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  // Read temperature as Celsius (the default)
  send_Temp = dht_sensor.readTemperature();
  
  // Read Humidity
  send_Humd = dht_sensor.readHumidity();
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float ft = dht_sensor.readTemperature(true);

  // Check if any reads failed.
  if (isnan(send_Temp) || isnan(send_Humd)) {
    Serial.println("Failed to read from DHT sensor!");
    send_Temp = 0.00;
    send_Humd = 0;
    send_Status_Read_DHT = "FAILED";
  } else {
    send_Status_Read_DHT = "SUCCEED";
  }
  
  Serial.printf("Temperature : %.2f °C\n", send_Temp);
  Serial.printf("Humidity : %d %%\n", send_Humd);
  Serial.printf("Status Read DHT Sensor : %s\n", send_Status_Read_DHT);
  Serial.println("-------------");
}
