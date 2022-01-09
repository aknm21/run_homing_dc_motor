/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 13
#define MOTOR_A 9
#define MOTOR_B 10
#define START_BUTTON 5
#define LIMIT_BUTTON_START 6
#define LIMIT_BUTTON_END 7
int motorState = 0;

#define SPEAKER 12   // スピーカーの出力ピン番号
#define BEATTIME 100 // 音を出している時間(msec)

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(LIMIT_BUTTON_START, INPUT_PULLUP);
  pinMode(LIMIT_BUTTON_END, INPUT_PULLUP);

  digitalWrite(MOTOR_A, LOW);
  digitalWrite(MOTOR_B, LOW);

  // Serial.begin(9600);
  delay(1000);
}

void loop()
{
  // Serial.print("BTN: ");
  // Serial.print(digitalRead(START_BUTTON));
  // Serial.print(", STA: ");
  // Serial.print(digitalRead(LIMIT_BUTTON_START));
  // Serial.print(", END: ");
  // Serial.print(digitalRead(LIMIT_BUTTON_END));
  // Serial.print(", motorState: ");
  // Serial.println(motorState);

  if (motorState == 0 && digitalRead(START_BUTTON) == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    tone(SPEAKER, 262, BEATTIME);
    digitalWrite(MOTOR_A, HIGH);
    digitalWrite(MOTOR_B, LOW);
    motorState = 1;
  }

  if (motorState == 1 && digitalRead(LIMIT_BUTTON_END) == HIGH)
  {
    tone(SPEAKER, 262, BEATTIME);
    digitalWrite(MOTOR_A, LOW);
    digitalWrite(MOTOR_B, LOW);
    delay(1000);
    tone(SPEAKER, 262, BEATTIME);
    digitalWrite(MOTOR_A, LOW);
    digitalWrite(MOTOR_B, HIGH);
    motorState = 2;
  }

  if (motorState == 2 && digitalRead(LIMIT_BUTTON_START) == HIGH)
  {
    tone(SPEAKER, 262, BEATTIME);
    digitalWrite(MOTOR_A, LOW);
    digitalWrite(MOTOR_B, LOW);
    motorState = 0;
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
}
