#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int curr_pos = 0;    // variable to store the servo position
int delay_val = 5;
//int servo_val = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  Serial.println("Initializing servo to 0 degrees");
  myservo.write(curr_pos); //Initialize the servo to 0 degrees
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Hello from Arduino!");
  //delay(1000);
  //incomingByte = Serial.read();
  
  while (Serial.available() > 0){
    String str = Serial.readString();
    str.trim();
    //int pos = str.toInt();
    int new_pos = str.toInt();
    Serial.println("---------------------------");
    Serial.println("New Position: " + str);
    Serial.println("Current Delay Value: " + String(delay_val));

    int pos_incr = 1;
    if (new_pos > curr_pos){
      Serial.println("Driving Forward");

      for (int pos = curr_pos; pos <= new_pos; pos += pos_incr) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(delay_val);                       // waits 15ms for the servo to reach the position
      }
    }
    else if(new_pos < curr_pos){
      Serial.println("Driving Backward");
      
      for (int pos = curr_pos; pos >= new_pos; pos -= pos_incr) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(delay_val);                       // waits 15ms for the servo to reach the position
      }
    }
    else{
      Serial.println("Going Nowhere");
    }

    
    curr_pos = new_pos; //Write the given position as new position

    if (delay_val == 15){
      delay_val = 5;
    }
    else{
      delay_val += 5;
    }
    
    
    //myservo.write(pos);              // tell servo to go to position in variable 'pos'
  }

}
