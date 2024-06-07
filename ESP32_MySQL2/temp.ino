void readSensor() {
  h = dht.readHumidity();
  t = dht.readTemperature();      // Read temperature as Celsius (the default)
  f = dht.readTemperature(true); // Read temperature as Fahrenheit (isFahrenheit = true)
}
