#include <Servo.h>

Servo servo;

int GSM = 3;
int pos = 0;
// ******Parameter******
int maxspeed = 30;
int spinning_time = 1000;
int pause_time = 5000;
// ******Parameter******

#define In1 10
#define In2 9

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM, OUTPUT);

  Serial.begin(9600);
  servo.attach(2);
  servo.write(0);
}

void loop() {
  up(40);
  startSpin();
  delay(5000);
  up(100);
  delay(1000);
  up(120);
  delay(1000);
  down(80);
  delay(1000);
  down(50);
  delay(1000);
  up(100);
  delay(1000);
  up(120);
  delay(1000);
  down(0);
  stopSpin();
  delay(1000);

  down(0);

  delay(pause_time);
}

void up(int height) {
  for (int i = pos; i <= height; i += 1) {
    servo.write(i);

    delay(20);
  }
  pos = height;
}

void down(int height) {
  for (int i = pos; i >= height; i -= 1) {
    servo.write(i);
    delay(20);
  }
  pos = height;
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM, i);
    delay(50);
  }
}

void stopSpin() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM, i);
    delay(50);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}