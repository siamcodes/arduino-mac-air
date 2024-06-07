// Subroutine to control LEDs after successfully fetching data from database.
void control_LEDs() {
  Serial.println();
  Serial.println("-------control_LEDs()");
  JSONVar myObject = JSON.parse(payload);

  // JSON.typeof(jsonVar) can be used to get the type of the var
  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
    Serial.println("--------");
    return;
  }

  if (myObject.hasOwnProperty("LED_01")) {
    Serial.print("myObject[\"LED_01\"] = ");
    Serial.println(myObject["LED_01"]);
  }

  if (myObject.hasOwnProperty("LED_02")) {
    Serial.print("myObject[\"LED_02\"] = ");
    Serial.println(myObject["LED_02"]);
  }

  if(strcmp(myObject["LED_01"], "ON") == 0)   {digitalWrite(LED_01, HIGH);  Serial.println("LED 01 ON"); }
  if(strcmp(myObject["LED_01"], "OFF") == 0)  {digitalWrite(LED_01, LOW);   Serial.println("LED 01 OFF");}
  if(strcmp(myObject["LED_02"], "ON") == 0)   {digitalWrite(LED_02, HIGH);  Serial.println("LED 02 ON"); }
  if(strcmp(myObject["LED_02"], "OFF") == 0)  {digitalWrite(LED_02, LOW);   Serial.println("LED 02 OFF");}

  Serial.println("---------");
}
