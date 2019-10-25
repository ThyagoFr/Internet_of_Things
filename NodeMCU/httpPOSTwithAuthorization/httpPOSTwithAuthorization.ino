#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "JRNET_THAGO";
const char* password = "86337748";
 
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connectando...");
  }
  
}
 
void loop() {

  if (WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    String json;
    DynamicJsonDocument json_data(1024);
    
    http.begin("http://nodegarden.herokuapp.com/data_farm");
    http.setAuthorization("thyago392035","392035");
    http.addHeader("Content-Type", "application/json");

    json_data["data"] = "25/10/2019";
    json_data["id_sensor"] =  random(1,6);
    json_data["luminosidade"] = random(20,60)/100.0;
    json_data["temperatura"] = random(20,60)/100.0;
    json_data["umidade_ar"] = random(20,60);
    json_data["umidade_solo"] =  random(20,60)/100.0;
    
    serializeJsonPretty(json_data, json);
    Serial.println(json);
    
    int httpcode = http.POST(json);
    if (httpcode > 0){
      String payload = http.getString();
      Serial.println(payload);
    } else{
      Serial.println("Erro na requisicao");
    }

    http.end();
  }

  delay(1000);

}
