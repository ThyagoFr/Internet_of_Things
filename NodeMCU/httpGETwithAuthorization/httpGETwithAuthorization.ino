#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
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
    http.begin("http://nodegarden.herokuapp.com/data_farm");
    http.setAuthorization("thyago392035","392035");

    int httpcode = http.GET();
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
