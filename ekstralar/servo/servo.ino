#include<Servo.h>
// 5v
Servo motor;
void setup() {
  motor.attach(4);

}

void loop() {
 motor.write(90);
 delay(4000);



}
