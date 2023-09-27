#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define interval 100 // Change interval from here
#include "Quadruped_parameters.h"

void sw(int k1 = k1_normal, int k2 = k2_normal, int k3 = k3_normal, int k4 = k4_normal, int l1 = l1_normal, int l2 = l2_normal, int l3 = l3_normal, int l4 = l4_normal) {
  pwm.setPWM(4, 0, k1);
  delay(interval);
  pwm.setPWM(5, 0, k2);
  delay(interval);
  pwm.setPWM(6, 0, k3);
  delay(interval);
  pwm.setPWM(7, 0, k4);
  delay(interval);
  pwm.setPWM(0, 0, l1);
  delay(interval);
  pwm.setPWM(1, 0, l2);
  delay(interval);
  pwm.setPWM(2, 0, l3);
  delay(interval);
  pwm.setPWM(3, 0, l4);
}

void setup() {
  Serial.begin(115200); // Baud rate
  pwm.begin();
  pwm.setPWMFreq(60); // Servo motors work at 60hz refresh rate
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readString();
    command.trim();
    
    if (command.equals("S")) {
      sw(k1_sleep, k2_sleep, k3_sleep, k4_sleep, l1_sleep, l2_sleep, l3_sleep, l4_sleep); // sleep
    } else if (command.equals("W")) {
      sw(); // wake
    } else if (command.equals("F")) {
      forward();
    } else if (command.equals("F3")) {
      forward();
      forward();
      forward();
    } else if (command.equals("B")) {
      backward();
    } else if (command.equals("B3")) {
      backward();
      backward();
      backward();
    } else if (command.equals("L")) {
      left();
    } else if (command.equals("L3")) {
      left();
      left();
      left();
    } else if (command.equals("R")) {
      right();
    } else if (command.equals("R3")) {
      right();
      right();
      right();
    }
  }
}

/* ---------- Quadruped Functions ---------- */

void forward() {
  pwm.setPWM(4, 0, k1_up);
  delay(interval);
  pwm.setPWM(0, 0, l1_forward);
  delay(interval);
  pwm.setPWM(4, 0, k1_normal);
  delay(interval);

  pwm.setPWM(5, 0, k2_up);
  delay(interval);
  pwm.setPWM(1, 0, l2_forward);
  delay(interval);
  pwm.setPWM(5, 0, k2_normal);
  delay(interval);

  pwm.setPWM(6, 0, k3_up);
  delay(interval);
  pwm.setPWM(2, 0, l3_forward);
  delay(interval);
  pwm.setPWM(6, 0, k3_normal);
  delay(interval);

  pwm.setPWM(7, 0, k4_up);
  delay(interval);
  pwm.setPWM(3, 0, l4_forward);
  delay(interval);
  pwm.setPWM(7, 0, k4_normal);
  delay(interval);

  pwm.setPWM(0, 0, l1_normal);
  delay(1);
  pwm.setPWM(1, 0, l2_normal);
  delay(1);
  pwm.setPWM(2, 0, l3_normal);
  delay(1);
  pwm.setPWM(3, 0, l4_normal);
}


void backward(){
  pwm.setPWM(7, 0, k4_up);
  delay(interval);
  pwm.setPWM(3, 0, l4_backward);
  delay(interval);
  pwm.setPWM(7, 0, k4_normal);
  delay(interval);

  pwm.setPWM(6, 0, k3_up);
  delay(interval);
  pwm.setPWM(2, 0, l3_backward);
  delay(interval);
  pwm.setPWM(6, 0, k3_normal);
  delay(interval);

  pwm.setPWM(5, 0, k2_up);
  delay(interval);
  pwm.setPWM(1, 0, l2_backward);
  delay(interval);
  pwm.setPWM(5, 0, k2_normal);
  delay(interval);

  pwm.setPWM(4, 0, k1_up);
  delay(interval);
  pwm.setPWM(0, 0, l1_backward);
  delay(interval);
  pwm.setPWM(4, 0, k1_normal);
  delay(interval);

  pwm.setPWM(3, 0, l4_normal);
  delay(1);
  pwm.setPWM(2, 0, l3_normal);
  delay(1);
  pwm.setPWM(1, 0, l2_normal);
  delay(1);
  pwm.setPWM(0, 0, l1_normal);
}

void left()
{
  pwm.setPWM(5, 0, k2_up);
  delay(interval);
  pwm.setPWM(1, 0, l2_forward);
  delay(interval);
  pwm.setPWM(5, 0, k2_normal);
  delay(interval);

  pwm.setPWM(4, 0, k1_up);
  delay(interval);
  pwm.setPWM(0, 0, l1_backward);
  delay(interval);
  pwm.setPWM(4, 0, k1_normal);
  delay(interval);

  pwm.setPWM(1, 0, l2_normal);
  delay(interval);
  pwm.setPWM(0, 0, l1_normal);
}

void right()
{
  pwm.setPWM(4, 0, k1_up);
  delay(interval);
  pwm.setPWM(0, 0, l1_forward);
  delay(interval);
  pwm.setPWM(4, 0, k1_normal);
  delay(interval);

  pwm.setPWM(5, 0, k2_up);
  delay(interval);
  pwm.setPWM(1, 0, l2_backward);
  delay(interval);
  pwm.setPWM(5, 0, k2_normal);
  delay(interval);

  pwm.setPWM(0, 0, l1_normal);
  delay(interval);
  pwm.setPWM(1, 0, l2_normal);
}