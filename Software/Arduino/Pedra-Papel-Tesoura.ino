#include <arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic ultrasonic(12, 13);
Servo myservo;  

int distance;
int pos = 0, add = 1; 

void setup() {
    Serial.begin(9600);
    myservo.attach(9); 
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("distancia detectada: ");
  Serial.println(distance);
  
  if(distance < 10){
    int rand = random(0,3);
    
    myservo.write(rand*90);
    Serial.print("angulo sorteado: ");
    Serial.println(rand*90);
    
    delay(2000);
  }
  delay(10);
}
