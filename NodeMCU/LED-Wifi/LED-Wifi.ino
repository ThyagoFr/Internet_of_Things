#include <ESP8266WiFi.h>

const char* ssid = "JRNET_THAGO";
const char* pass = "86337748";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(D3,OUTPUT);
  pinMode(D7,OUTPUT);

  digitalWrite(D3,LOW);
  digitalWrite(D7,LOW);

  Serial.println("Conectando a rede...");
  WiFi.begin(ssid,pass);

  while( WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("Conectado com sucesso!");
  Serial.println("Servidor rodando em :");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  Serial.print("Port : 80");  
}

void loop() {
 WiFiClient client = server.available();
 while (!client.available()){
  delay(1);
 }
 Serial.println("Cliente conectado...");
 String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
 s += "highw";
 s += "</html>\n";
 client.print(s);
 
 String req = client.readStringUntil('\r');
 client.flush();

 if (req.indexOf("led3_ON")){
  digitalWrite(3,HIGH);
 }else if (req.indexOf("led3_OFF")){
  digitalWrite(3,LOW);
 }else if (req.indexOf("led7_ON")){
  digitalWrite(7,HIGH);
 }else if (req.indexOf("led7_OFF")){
  digitalWrite(7,LOW);
 }

}
