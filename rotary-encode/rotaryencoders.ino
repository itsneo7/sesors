#define CLK 2   // interrupt-capable pin
#define DT  3   // interrupt-capable pin

volatile long counter = 0;
volatile int lastA, lastB;

void setup() {
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT,  INPUT_PULLUP);
  Serial.begin(9600);

  // Save initial states
  lastA = digitalRead(CLK);
  lastB = digitalRead(DT);

  // Interrupts on both channels
  attachInterrupt(digitalPinToInterrupt(CLK), readEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT),  readEncoder, CHANGE);
}

void loop() {
  long val;
  noInterrupts();
  val = counter;
  interrupts();

  Serial.println(val);
  delay(50);
}

void readEncoder() {
  int a = digitalRead(CLK);
  int b = digitalRead(DT);

  // --- Logic for direction detection ---
  if (a != lastA) {   // A changed
    if (a == b) {
      counter++;
    } else {
      counter--;
    }
  }
  else if (b != lastB) {  // B changed
    if (a != b) {
      counter++;
    } else {
      counter--;
    }
  }

  lastA = a;
  lastB = b;
}
