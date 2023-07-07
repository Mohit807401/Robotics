#include <SoftwareSerial.h>  // TX RX software library for bluetooth
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
int x_key = A1;
int y_key = A0;
int x_pos;
int y_pos;
int servo1_pin = 8;  //y
int servo2_pin = 9;  //x
int servo3_pin = 7;  //x
int servo4_pin = 6;  //y
int servo5_pin = 5;  //y
int servo6_pin = 4;  //x
int servo7_pin = 3;  //y
int servo8_pin = 2;  // x
int initial_position = 90;
int initial_position1 = 90;
//int bluetoothTx = 1; // bluetooth tx to 10 pin
//int bluetoothRx = 0; // bluetooth rx to 11 pin
//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  Serial.begin(9600);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);
  servo4.attach(servo4_pin);
  servo5.attach(servo5_pin);
  servo6.attach(servo6_pin);
  servo7.attach(servo7_pin);
  servo8.attach(servo8_pin);
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  //bluetooth.begin(9600);
  servo1.write(initial_position);
  servo2.write(initial_position1);
  servo3.write(initial_position);
  servo4.write(initial_position1);
  servo5.write(initial_position);
  servo6.write(initial_position1);
  servo7.write(initial_position);
  servo8.write(initial_position1);
  pinMode(x_key, INPUT);
  pinMode(y_key, INPUT);
}

void loop() {
  //   if(bluetooth.available()> 0 ) // receive number from bluetooth
  //  {
  //    int servopos = bluetooth.read(); // save the received number to servopos
  //    Serial.println(servopos); // serial print servopos current number received from bluetooth
  //    servo1.write(servopos);
  //    servo2.write(servopos);
  //    servo3.write(servopos);
  //    servo4.write(servopos);
  //    servo5.write(servopos);
  //    servo6.write(servopos);
  //    servo7.write(servopos);
  //    servo8.write(servopos);
  //    // roate the servo the angle received from the android app
  //  }
  x_pos = analogRead(x_key);
  y_pos = analogRead(y_key);

  if (x_pos < 300) {
    if (initial_position < 10) {
    } else {
      initial_position = initial_position - 20;
      servo2.write(initial_position);
      servo3.write(initial_position);
      servo6.write(initial_position);
      servo8.write(initial_position);
      delay(100);
    }
  }
  if (x_pos > 700) {
    if (initial_position > 180) {
    } else {
      initial_position = initial_position + 20;
      servo2.write(initial_position);
      servo3.write(initial_position);
      servo6.write(initial_position);
      servo8.write(initial_position);
      delay(100);
    }
  }

  if (y_pos < 300) {
    if (initial_position1 < 10) {
    } else {
      initial_position1 = initial_position1 - 20;
      servo1.write(initial_position1);
      servo4.write(initial_position1);
      servo5.write(initial_position1);
      servo7.write(initial_position1);
      delay(100);
    }
  }
  if (y_pos > 700) {
    if (initial_position1 > 180) {
    } else {
      initial_position1 = initial_position1 + 20;
      servo1.write(initial_position1);
      servo4.write(initial_position1);
      servo5.write(initial_position1);
      servo7.write(initial_position1);
      delay(100);
    }
  }
}
