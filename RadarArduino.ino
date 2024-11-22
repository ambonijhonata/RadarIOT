#include <Servo.h>. 

const int trigPin = 10;  
const int echoPin = 9;  

long duration;  
int distance;  
Servo servo; 

void setup() {  
 pinMode(trigPin, OUTPUT); //Define o trigPin como uma saída
 pinMode(echoPin, INPUT); //Define o echoPin como uma entrada
 Serial.begin(9600);  
 servo.attach(12);
 servo.write(0);
}

void loop() {  
  

  for(int i = 15; i <= 165; i++){
    servo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i); 
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");   
  }

  for(int i = 165; i > 15; i--){
    servo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() {   
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);   
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;  
  return distance;  
}