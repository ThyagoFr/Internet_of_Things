#include <ESP8266WiFi.h>//Biblioteca do WiFi.
#include <WiFiUdp.h>//Biblioteca do UDP.
 
WiFiUDP udp;  //Cria um objeto da classe UDP.
String  req;  //String que armazena os dados recebidos pela rede.
const char* ssid = "JRNET_THAGO";
const char* pass = "86337748";
 
void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(D3,OUTPUT);
  pinMode(D7,OUTPUT);
  digitalWrite(D3,LOW);
  digitalWrite(D7,LOW);
  WiFi.begin(ssid,pass);

  while( WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("");
  Serial.println("Conectado com sucesso");
  Serial.println("Dispositivo rodando em :");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  Serial.print("Port : 555");
  delay(2000);
  udp.begin(555);//Inicializa a recepçao de dados UDP na porta 555
}
 
void loop() {
   listen();//Sub-rotina para verificar a existencia de pacotes UDP.
}
 
void listen(){
   if (udp.parsePacket() > 0){
       req = "";
       while (udp.available() > 0) {
           char z = udp.read();
           req += z;
       }
       Serial.println(req);
    }
}
