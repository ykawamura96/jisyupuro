#include "Arduino.h"
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

int trig = 8; // 出力ピン
int echo = 9; // 入力ピン
int trig2 = 10; // 出力ピン
int echo2 = 11; // 入力ピン
void setup () {
  Serial.begin (9600);
  mp3_set_serial (Serial);      //set Serial for DFPlayer-mini mp3 module
  delay(1);                     // delay 1ms to set volume
  mp3_set_volume (25);          // value 0~30
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}

void loop () {
  digitalWrite(trig, LOW);
  delayMicroseconds(1);
  // 超音波を出力
  digitalWrite(trig, HIGH);
  delayMicroseconds(11);
  // 超音波を出力終了
  digitalWrite(trig, LOW);
  // 出力した超音波が返って来る時間を計測
  int t = pulseIn(echo, HIGH);
  // 計測した時間と音速から反射物までの距離を計算
  float distance = t * 0.017;
  // 計算結果をシリアル通信で出力

  digitalWrite(trig2, LOW);
  delayMicroseconds(1);
  // 超音波を出力
  digitalWrite(trig2, HIGH);
  delayMicroseconds(11);
  // 超音波を出力終了
  digitalWrite(trig2, LOW);
  // 出力した超音波が返って来る時間を計測
  int t2 = pulseIn(echo2, HIGH);
  // 計測した時間と音速から反射物までの距離を計算
  float distance2 = t2 * 0.017;
  // 計算結果をシリアル通信で出力
  //mp3_random_play ();
  if (distance < 15) {
    mp3_play (9);
    delay (6000);
  } else if (distance < 30) {
    mp3_play (8);
    delay (6400);
  } else if (distance < 45) {
    mp3_play (7);
    delay (6850);
  }  else if (distance < 60) {
    mp3_play (6);
    delay (7384);
  } else if (distance < 75) {
    mp3_play (5);
    delay (8000);
  } else if (distance < 90) {
    mp3_play (4);
    delay (8727);
  } else if (distance < 105) {
    mp3_play (3);
    delay (9600);
  } else if (distance < 120) {
    mp3_play (2);
    delay (10666);
  } else if (distance > 135) {
    mp3_play (1);
    delay (12000);
  }
}
