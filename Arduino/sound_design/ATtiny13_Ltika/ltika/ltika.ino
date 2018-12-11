#define LED 5
#define SW1 1
//#define SW2 2
#define SL 4
#define MIC 3
int mic_val = 0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(MIC, INPUT);
  pinMode(SW1, INPUT);
//  pinMode(SW2, INPUT);
  //pinMode(SW3, INPUT);
  pinMode(SL, OUTPUT);
}
void knock() {
  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(50);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(500);

  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(50);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(500);

  digitalWrite(LED, HIGH);
  digitalWrite(SL, HIGH);
  delay(50);
  digitalWrite(LED, LOW);
  digitalWrite(SL, LOW);
  delay(500);
}

void loop() {
//  knock();
  int mic_val = 0;
  mic_val += abs(analogRead(MIC) - 521);
  if(mic_val > 300){
    knock();

  }
}
