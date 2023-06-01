#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); 
#define THRESHOLD 10 
#define echoPin1 2 
#define trigPin1 3
#define echoPin2 4 
#define trigPin2 5
#define MAX_DIST 20 // Define maximum distance in cm

// direction of movement
char direction;


//Motor A
int enA=8;
int in1=7;
int in2=6;

//Motor B
int enB=9;
int in3=10;
int in4=11;

int speed=200;

//gyro
int correction;
int deviation;

int red=A1;
int yellow=A2;
int green=A3;


void setup() {
  BT.begin(9600);
  Serial.begin(9600);

  // set pin for Gyro
  pinMode(gyroPin, INPUT);


  // Set pins for ultrasonic
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);


  

  // motors control
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  analogWrite(enA , 200);
  analogWrite(enB , 200);

  //leds to help in understandin the situation
  pinMode(red , OUTPUT); //red to indicate stopping
  pinMode(yellow , OUTPUT); //yellow to indicate there's an object
  pinMode(green , OUTPUT); //green to indicate movement

}

void loop() {

  //gyroscope to calculate deviation
  correction=0;
  int gyroVal = analogRead(gyroPin);
  // Calculate deviation from center
  int deviation = gyroVal - 512; 
  // If deviation exceeds threshold, correct course
  if (abs(deviation) > THRESHOLD) {
    if (deviation > 0) {
      // Turn left
      correction=-deviation/8;
    } else {
      // Turn right 
      correction=deviation/8;
    }
  }
  
   // Send pulse to trigger sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Measure duration of echo pulse
  long duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculate distance in cm
  int forward_distance = duration1 * 0.034 / 2;


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Measure duration of echo pulse
  long duration2 = pulseIn(echoPin2, HIGH);
  // Calculate distance in cm
  int backward_distance = duration2 * 0.034 / 2;



  if(BT.read())
  {
     direction=BT.read();
  }

  if(direction=='f'){
  forward(); 
  }
  if(direction=='b'){
  backward(); 
  }
  if(direction=='r'){
  direction='s'
  right();
  }
 if(direction=='l'){
  direction='s'
  left(); 
  }
 if(direction=='s'){
  stop(); 
  }
}


 void forward() {

  if (forward_distance <= MAX_DIST)
  {
    stop();
  }
  else if (forward_distance <= MAX_DIST*2)
  {
    analogWrite(enA,speed/2+correction);
    analogWrite(enB,speed/2-correction);
    digitalWrite(in1, LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else
  {

  analogWrite(enA,speed+correction);
  analogWrite(enB,speed-correction);
  digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }
}
  void backward() {
  if (backward_distance <= MAX_DIST)
  {
    stop();
  }
  else if (forward_distance <= MAX_DIST*2)
  {
    analogWrite(enA,speed/2-correction);
    analogWrite(enB,speed/2+correction);
    digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else
  {
    analogWrite(enA,speed-correction);
    analogWrite(enB,speed+correction);
    digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  
}
  void right() {
  analogWrite(enA,speed/2);
  analogWrite(enB,speed/2);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(800);
  stop();
}
  void left() {
  analogWrite(enA,speed/2);
  analogWrite(enB,speed/2);
  digitalWrite(in1, HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(800);
  stop();
  
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void movement()
{
  analogWrite(red,0);
  analogWrite(yellow,0);
  analogWrite(green,255);
}
void stopping()
{
  analogWrite(red,255);
  analogWrite(yellow,0);
  analogWrite(green,0);
}
void alarm()
{
  analogWrite(red,0);
  analogWrite(yellow,255);
  analogWrite(green,0);
}
