#include <SPI.h>
#include <nRF24L01.h> //INCLUSÃO DE BIBLIOTECA
#include <RF24.h> //INCLUSÃO DE BIBLIOTECA
 
RF24 radio(9, 10); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CE, CSN)
 
const byte address[6] = "00002"; //CRIA UM ENDEREÇO PARA ENVIO DOS
//DADOS (O TRANSMISSOR E O RECEPTOR DEVEM SER CONFIGURADOS COM O MESMO ENDEREÇO)
 
void setup() {
  Serial.begin(9600);
  radio.begin(); //INICIALIZA A COMUNICAÇÃO SEM FIO
  radio.openWritingPipe(address); //DEFINE O ENDEREÇO PARA ENVIO DE DADOS AO RECEPTOR
  radio.setPALevel(RF24_PA_HIGH); //DEFINE O NÍVEL DO AMPLIFICADOR DE POTÊNCIA
  radio.stopListening(); //DEFINE O MÓDULO COMO TRANSMISSOR (NÃO RECEBE DADOS)
}
 
void loop() {
  const char text[] = "MasterWalker Shop"; //VARIÁVEL RECEBE A MENSAGEM A SER TRANSMITIDA
  int result = radio.write(&text, sizeof(text));
  
  if (result)  {
    Serial.println("Enviou");            //ENVIA AO RECEPTOR A MENSAGEM
  }else {
    Serial.println("Nao enviou");
  }
  delay(5000); //INTERVALO DE 1 SEGUNDO
}
