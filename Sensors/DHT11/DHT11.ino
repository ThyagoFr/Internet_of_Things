// BIBILIOTECA PARA O USO DO SENSOR
#include <DHT.h>

// CONFIGURACOES INICIAIS
#define SENSOR 5
#define VCC    3
#define GND    4


DHT dht_sensor(SENSOR,DHT11);

void setup() {
  Serial.begin(9600);
  pinMode(GND,OUTPUT);
  pinMode(VCC,OUTPUT);
  pinMode(SENSOR,INPUT);

  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);
  dht_sensor.begin();

}

void loop() {

  int temperatura = dht_sensor.readTemperature();
  int umidade = dht_sensor.readHumidity();

  Serial.print(temperatura);
  Serial.print(",");
  Serial.print(umidade);
  Serial.println();
  delay(2000);

}
