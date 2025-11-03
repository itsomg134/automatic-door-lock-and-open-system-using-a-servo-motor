
#include <Arduino.h>
#include <Servo.h>


#define SERVO_PIN 9          
#define DC_MOTOR_IN1 5       
#define DC_MOTOR_IN2 6     
#define DC_MOTOR_EN 10      
#define PIR_SENSOR 2         
#define BUTTON_OPEN 3       
#define BUTTON_CLOSE 4       
#define LED_STATUS 13        


#define SERVO_LOCK_POS 0   
#define SERVO_UNLOCK_POS 90 
#define MOTOR_SPEED 200      
#define DOOR_OPEN_TIME 3000  
#define DOOR_CLOSE_TIME 3000 
#define DOOR_WAIT_TIME 5000  


enum DoorState {
  LOCKED_CLOSED,
  UNLOCKING,
  OPENING,
  OPEN,
  CLOSING,
  LOCKING
};


Servo lockServo;
DoorState currentState = LOCKED_CLOSED;
unsigned long lastActionTime = 0;
bool motionDetected = false;

void setup() {
  Serial.begin(9600);
  

  lockServo.attach(SERVO_PIN);
  lockServo.write(SERVO_LOCK_POS);
  
  pinMode(DC_MOTOR_IN1, OUTPUT);
  pinMode(DC_MOTOR_IN2, OUTPUT);
  pinMode(DC_MOTOR_EN, OUTPUT);
  

  pinMode(PIR_SENSOR, INPUT);
  pinMode(BUTTON_OPEN, INPUT_PULLUP);
  pinMode(BUTTON_CLOSE, INPUT_PULLUP);
  pinMode(LED_STATUS, OUTPUT);
  

  stopMotor();
  
  Serial.println("Automatic Door System Initialized");
  Serial.println("Door is LOCKED and CLOSED");
}

void loop() {

  motionDetected = digitalRead(PIR_SENSOR);
  bool openButtonPressed = !digitalRead(BUTTON_OPEN);
  bool closeButtonPressed = !digitalRead(BUTTON_CLOSE);
  

  switch(currentState) {
    case LOCKED_CLOSED:
      digitalWrite(LED_STATUS, LOW);
      
      if (motionDetected || openButtonPressed) {
        Serial.println("Motion detected! Unlocking door...");
        unlockDoor();
        currentState = UNLOCKING;
        lastActionTime = millis();
      }
      break;
      
    case UNLOCKING:
    
      if (millis() - lastActionTime > 1000) {
        Serial.println("Door unlocked. Opening...");
        openDoor();
        currentState = OPENING;
        lastActionTime = millis();
      }
      break;
      
    case OPENING:
      digitalWrite(LED_STATUS, HIGH);
    
      if (millis() - lastActionTime > DOOR_OPEN_TIME) {
        stopMotor();
        Serial.println("Door is OPEN");
        currentState = OPEN;
        lastActionTime = millis();
      }
      break;
      
    case OPEN:
      digitalWrite(LED_STATUS, HIGH);
      
      if (closeButtonPressed || millis() - lastActionTime > DOOR_WAIT_TIME) {
        Serial.println("Closing door...");
        closeDoor();
        currentState = CLOSING;
        lastActionTime = millis();
      }
      break;
      
    case CLOSING:
      
      if (millis() - lastActionTime > DOOR_CLOSE_TIME) {
        stopMotor();
        Serial.println("Door closed. Locking...");
        lockDoor();
        currentState = LOCKING;
        lastActionTime = millis();
      }
      break;
      
    case LOCKING:
      
      if (millis() - lastActionTime > 1000) {
        Serial.println("Door is LOCKED and CLOSED");
        currentState = LOCKED_CLOSED;
      }
      break;
  }
  
  delay(50); 
}


void unlockDoor() {
  lockServo.write(SERVO_UNLOCK_POS);
  Serial.println("Lock: UNLOCKED");
}


void lockDoor() {
  lockServo.write(SERVO_LOCK_POS);
  Serial.println("Lock: LOCKED");
}

// Function to open door (DC motor clockwise)
void openDoor() {
  digitalWrite(DC_MOTOR_IN1, HIGH);
  digitalWrite(DC_MOTOR_IN2, LOW);
  analogWrite(DC_MOTOR_EN, MOTOR_SPEED);
  Serial.println("Motor: OPENING");
}

void closeDoor() {
  digitalWrite(DC_MOTOR_IN1, LOW);
  digitalWrite(DC_MOTOR_IN2, HIGH);
  analogWrite(DC_MOTOR_EN, MOTOR_SPEED);
  Serial.println("Motor: CLOSING");
}

void stopMotor() {
  digitalWrite(DC_MOTOR_IN1, LOW);
  digitalWrite(DC_MOTOR_IN2, LOW);
  analogWrite(DC_MOTOR_EN, 0);
  Serial.println("Motor: STOPPED");
}