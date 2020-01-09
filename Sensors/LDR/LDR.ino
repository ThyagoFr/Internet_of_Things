#define LDR A3

// Quuando luz -> infinito,resistencia -> 0
// Quuando luz -> 0,resistencia -> infinito
void setup() {
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  
}

void loop() {
  int value = analogRead(LDR);
  float Rl = map(value,0,150,10000,0);
  Serial.println(value);
  delay(1000);

}
