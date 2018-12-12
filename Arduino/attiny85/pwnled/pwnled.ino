#define LED 0
#define SW1 1
//#define SW2 2
#define SL 4
#define MIC 3

/* Four PWM Outputs */

// ATtiny85 outputs
const int Red = 0;
const int Green = 1;
const int Blue = 4;
const int White = 3;
volatile uint8_t* Port[] = {&OCR0A, &OCR0B, &OCR1A, &OCR1B};

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  /*for (int i=-255; i <= 254; i++) {
    OCR0A = abs(i);
    OCR0B = 255-abs(i);
    OCR1A = abs(i);
    OCR1B = 255-abs(i);
    delay(10);
  }*/
  for(int i = 0; i<=512; i++){
   analogWrite(LED, abs(i - 255));
    delay(3);
  }
}
