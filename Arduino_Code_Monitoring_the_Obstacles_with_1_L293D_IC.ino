// C++ code
#include <Servo.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int enablePin = 5;
const int input1Pin = 2;
const int input2Pin = 3;

// Servo object
Servo myServo;

// Variables
long duration;
int distance;
bool movingForward = true;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set motor control pins
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
  
  // Start with motor stopped
  digitalWrite(enablePin, LOW);
  
  // Attach servo to the motor driver outputs
  // (Note: Servo library typically connects directly to Arduino pins,
  // but we're simulating servo control through the L293D here)
}

void loop() {
  // Measure distance
  distance = measureDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if obstacle is within 10cm
  if (distance <= 10 && distance > 0) {
    // Stop the motor
    digitalWrite(enablePin, LOW);
    delay(500); // Short pause
    
    // Change direction
    movingForward = !movingForward;
    
    // Set new direction
    if (movingForward) {
      digitalWrite(input1Pin, HIGH);
      digitalWrite(input2Pin, LOW);
    } else {
      digitalWrite(input1Pin, LOW);
      digitalWrite(input2Pin, HIGH);
    }
    
    // Restart motor
    digitalWrite(enablePin, HIGH);
    delay(1000); // Move for a second before checking again
  } else if (distance > 10 || distance == 0) {
    // Keep moving in current direction
    digitalWrite(enablePin, HIGH);
  }
  
  delay(100); // Short delay between measurements
}

int measureDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance (in cm)
  distance = duration * 0.034 / 2;
  
  return distance;
}
