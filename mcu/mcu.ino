#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

String ssid = "TP-LINK_GOLD";
String password = "slobodno";
int ID = 0;
int pins[] = {5,4,0,14,12,13,15};

StaticJsonBuffer<200> jsonBuffer;
JsonObject& json = jsonBuffer.createObject();
/*
void ICACHE_RAM_ATTR updateData(){
  return;
}
*/
void setup() {
  /*
  for(int i = 0; i < 7; i++){
    pinMode(pins[i], OUTPUT);
  }
  */
  int httpCode = 0;
  json.set<int>("ID", ID);
  json.set<int>("mesto", 0);
  
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connectning to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected");

  if (WiFi.status() == WL_CONNECTED)
  {
      HTTPClient http;
      http.begin("http://192.168.1.4:5000/slots/" + String(ID));
      http.addHeader("Content-Type", "application/json");
      String output;
      json.printTo(output);
      httpCode = http.PUT(output);

      if (httpCode > 0)
      {
        DynamicJsonBuffer jsonBuffer2;
        JsonObject& root = jsonBuffer2.parseObject(http.getString());
        int id = root["ID"];
        String mesto = root["mesto"];

        Serial.print("ID:");
        json["ID"].printTo(Serial);
        Serial.print("\nmesto:");
        json["mesto"].printTo(Serial);
      }

      http.end();
  }

  ESP.deepSleep(5e6);
  //attachInterrupt(digitalPinToInterrupt(2), updateData, RISING);
}

void loop() {
  
}
