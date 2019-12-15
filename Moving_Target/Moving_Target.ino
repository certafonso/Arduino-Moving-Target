#include <Servo.h>

Servo myServo;  // create a servo object

int const potPin = A0; // analog pin used to connect the potentiometer
int potVal;  // variable to read the value from the analog pin
int angle;   // variable to hold the angle for the servo motor
int const led = 7;
int n = 0;
int threshold = 400;
int starttime;
int curtime = 0;
int score;

void setup() {
  myServo.attach(13); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
  myServo.write(0);
  while (threshold > analogRead(potPin)){
    digitalWrite(led, HIGH);
    delay(10);
  }
  
  starttime = millis();
  Serial.println("0");
  while (curtime - starttime <= 30000){
    //Serial.println(curtime - starttime);
  
    angle = random(180);
    
    // print out the angle for the servo motor
    //Serial.print(", angle: ");
    //Serial.println(angle);
  
    // set the servo position
    myServo.write(angle);
    delay(500);
  
    digitalWrite(led, HIGH);
    
  
    while (n <= random(30,100)){
      potVal = analogRead(potPin);
      //Serial.print("potVal: ");
      //Serial.println(potVal);
      if (potVal > threshold){
        digitalWrite(led, LOW);
        n = 200;
        score += 1;
        Serial.println(score);
      }
      else{
        n += 1;
      }
      delay(10);
    }
  
    n = 0;
    digitalWrite(led, LOW);
    curtime = millis();
  }
  digitalWrite(led, LOW);
  myServo.write(0);
}

void loop() {
}
