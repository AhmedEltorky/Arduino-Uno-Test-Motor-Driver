// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 8;
int in2 = 9;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

int speedLeft, speedRight;


void setup() {
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  speedLeft = speedRight = 100;
}

void forwardMove() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speedLeft);
  analogWrite(enB, speedRight);
}

void backwardMove() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speedLeft);
  analogWrite(enB, speedRight);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speedLeft);
  analogWrite(enB, speedRight);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speedLeft);
  analogWrite(enB, speedRight);
}

void stopMove() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void loop() {
  // ... if you need to run test one just un-comment it and comment test two or you can un-comment both ... //
  // test one
  // test the motor direction.
  /*forwardMove();
    delay(5000);
    stopMove();
    delay(500);
    backwardMove();
    delay(5000);
    stopMove();
    delay(500);*/

  // test two
  // this test make the motor run from 0 to its maximum speed then to 0 speed again.
  speedLeft = speedRight = 0;
  for (int i = 1; i <= 255; i++) {
    speedLeft = speedRight = i;
    forwardMove();
    delay(50);
  }
  delay(2000); // motor run 2 sec at it's max speed
  for (int i = 254; i >= 0; i--) {
    speedLeft = speedRight = i;
    forwardMove();
    delay(50);
  }
}
