// BIBILIOTECA PARA O USO DO SENSOR
#include <DHT.h>

// CONFIGURACOES INICIAIS
#define SENSOR A2

DHT dht_sensor(SENSOR,DHT11);

void setup() {
  Serial.begin(9600);
  
  pinMode(SENSOR,INPUT);
  dht_sensor.begin();

}

void loop() {

  float temperatura = dht_sensor.readTemperature();
  float umidade = dht_sensor.readHumidity();

  Serial.print(temperatura);
  Serial.print(",");
  Serial.print(umidade);
  Serial.println();
  delay(2000);

}
