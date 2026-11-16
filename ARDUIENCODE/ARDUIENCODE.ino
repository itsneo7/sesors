
void enc(){
Serial.println(6);
  Serial.println(digitalRead(18));

}
void encb(){
Serial.println(5);
  Serial.print(digitalRead(19));

}
void setup() {
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(18), enc, RISING);
  attachInterrupt(digitalPinToInterrupt(19), encb, RISING);
  sei();
  Serial.begin(115200);

}


void loop() {
  // Serial.print(digitalRead(14));
  // Serial.print("\t");
  // Serial.print(digitalRead(15));

  // Serial.println();

  // put your main code here, to run repeatedly:

}
