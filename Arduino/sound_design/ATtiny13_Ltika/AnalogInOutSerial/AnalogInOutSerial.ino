/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  int i;
  int x = 0;
  // read the analog in value:
  for (i = 0 ; i < 100 ; i++) {
    sensorValue = analogRead(analogInPin);
    x += abs(sensorValue - 521);
  }
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  x = x / 100;
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
  //Serial.print(ADCdisplay(3, x, 0, 0));
  // print the results to the Serial Monitor:
  Serial.println(x);
  //Serial.print("\t output = ");
  //Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(100);
}

char * ADCdisplay(int kosu, int d1, int d2, int d3)
{
  int i , j , x , p , d[3] ;
  static char buf[18] ;

  p = 0 ;
  d[0] = d1 ;
  d[1] = d2 ;
  d[2] = d3 ;
  // ３チャンネル分繰り返す
  for (j = 0 ; j < kosu ; j++) {
    buf[p] = 'X' + j ;  // チャンネル(X/Y/Z)を指定
    p++ ;
    // データをＨＥＸ文字に変換する
    for (i = 15 ; i > 0 ; i = i - 4) {
      x =  (unsigned int)(d[j] << (15 - i)) >> 12 ;
      if (x < 0xa) buf[p] = x + 0x30 ;
      else         buf[p] = x + 0x37 ;
      p++ ;
    }
  }
  // 最後にCR・LFを追加する
  buf[p] = 0x0d ;
  p++ ;
  buf[p] = 0x0a ;
  // 変換したデータの格納先アドレスを返す
  return buf ;
}
