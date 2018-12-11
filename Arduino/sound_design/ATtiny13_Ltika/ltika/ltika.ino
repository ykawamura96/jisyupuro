#define LED 0
#define SW1 1
#define SW2 2
#define SL 4
#define MIC 3
int mic_val = 0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(MIC, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  //pinMode(SW3, INPUT);
  pinMode(SL, OUTPUT);
}
void knock() {
  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(10);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(10);

  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(10);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(10);

  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(10);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(10);
}

void loop() {
  int i = 0;
  int x = 0;
  int mic_val = 0;
  for (i = 0 ; i < 2 ; i++) {
    x = analogRead(MIC);
    mic_val += abs(x - 521);
  }
  mic_val = mic_val / 2;

  if (mic_val > 230) {
    int x = 0;
    int mic_val = 0;
    for (i = 0 ; i < 2 ; i++) {
      x = analogRead(MIC);
      mic_val += abs(x - 521);
    }
    mic_val = mic_val / 2;
    if (mic_val > 230) {
      //knock();*/
      digitalWrite(LED, HIGH);
      digitalWrite(SL, HIGH);
      delay(1);
    }
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(SL, LOW);
    delay(1);
  }
}
