/*
 * Warhacks 2020
 * Project by: Joel, Xen, Jennifer and Kamyar
 * Tech boyz
 */


#include <NewPing.h>
#include <AFMotor.h>


AF_DCMotor left_motor(1);
AF_DCMotor right_motor(2);

int leftSensor = A3;
int rightSensor = A4;

//sensor setup
// get analog sensor values (0 - 1023)
  
    
#define TRIGGER_PIN  A1  
#define ECHO_PIN     A2  
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {

  Serial.begin(9600);
  //wheels speed
  left_motor.setSpeed(125);
  right_motor.setSpeed(125);

  left_motor.run(RELEASE);
  right_motor.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50); 
    int count = 0;
    int leftValue = analogRead(leftSensor);
    int rightValue = analogRead(rightSensor);
        
//    Serial.print("left = "); 
//    Serial.println(leftValue);
//  
//    // print right value
//    Serial.print("right = "); 
//    Serial.println(rightValue);
  
     if( leftValue < 450 && rightValue <450 )
     {
      runForward();
     }

    else if( rightValue > 600 )
    {
      turnRight();
    }

    else if(leftValue >600)
    {
      turnLeft();
    }

    if(sonar.ping_cm() < 30 && count == 0 && sonar.ping_cm() != 0)
   {
    turnLeft2sec();
    runForward1sec();
    turnRight2sec();
    count++;
   }
   
 
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");

   
}

void runForward(){
  // set motor direction (FORWARD / BACKWARD)
    left_motor.run(FORWARD);
    right_motor.run(BACKWARD);
}

void runBackward(){
  // set motor direction (FORWARD / BACKWARD)
    left_motor.run(BACKWARD);
    right_motor.run(FORWARD);
}

void runBackward1sec(){
  // set motor direction (FORWARD / BACKWARD)
    left_motor.run(BACKWARD);
    right_motor.run(FORWARD);
    delay(1000);

     left_motor.run(RELEASE);
    right_motor.run(RELEASE);
}

void turnLeft(){ 
    left_motor.run(RELEASE);
    right_motor.run(BACKWARD);
}

void turnLeft2sec(){
    left_motor.run(RELEASE);
    right_motor.run(BACKWARD);
    delay(500);

left_motor.run(RELEASE);
right_motor.run(RELEASE);
}

void runForward1sec(){
  // set motor direction (FORWARD / BACKWARD)
    left_motor.run(FORWARD);
    right_motor.run(BACKWARD);
delay(1500);

    left_motor.run(RELEASE);
    right_motor.run(RELEASE);

}
void turnRight2sec(){
    left_motor.run(FORWARD);
    right_motor.run(RELEASE);
    delay(1300);
 left_motor.run(RELEASE);
right_motor.run(RELEASE);   
    
}


void turnRight(){
    left_motor.run(FORWARD);
    right_motor.run(RELEASE);
}
