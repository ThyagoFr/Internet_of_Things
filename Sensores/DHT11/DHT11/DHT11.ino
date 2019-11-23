// BIBILIOTECA PARA O USO DO SENSOR
#include <DHT.h>

// CONFIGURACOES INICIAIS
#define SENSOR A2
#define GND A3
#define VCC A4

DHT dht_sensor(SENSOR,DHT11);

void setup() {
  Serial.begin(9600);
  
  pinMode(VCC,OUTPUT);
  pinMode(GND,OUTPUT);
  pinMode(SENSOR,INPUT);

  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);
  dht_sensor.begin();

}

void loop() {

  float temperatura = dht_sensor.readTemperature();
  float umidade = dht_sensor.readHumidity();

  Serial.print(temperatura);
  Serial.print("C");
  Serial.println();
  Serial.print(umidade);
  Serial.print("%");
  Serial.println();
  Serial.printf()
  
  delay(2000);

}
