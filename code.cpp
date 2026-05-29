/**
 * Tiva C Launchpad Bluetooth RC Car Firmware
 * Timeline: Jan 2021 - Dec 2021
 * Target: EK-TM4C123GXL (ARM Cortex-M4)
 */

// Left Motor Direction
const int IN1 = PD_0; 
const int IN2 = PD_1; 

// Right Motor Direction
const int IN3 = PD_2; 
const int IN4 = PD_3; 

// Hardware PWM Speed Enable Pins
const int ENA = PB_6; 
const int ENB = PB_7; 

int activeSpeed = 220; // Driving duty cycle (0 to 255)
char dynamicCommand; 

void setup() {
  // Initialize UART1 on pins PB0 and PB1 at 9600 baud rate for HC-05
  Serial1.begin(9600); 
  
  // Set GPIO pin modes
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  haltVehicle(); 
}

void loop() {
  // Read incoming byte array from the Bluetooth pipeline
  if (Serial1.available() > 0) {
    dynamicCommand = Serial1.read(); 
    
    switch (dynamicCommand) {
      case 'F': driveForward();   break;
      case 'B': driveBackward();  break;
      case 'L': executeLeft();    break;
      case 'R': executeRight();   break;
      case 'S': haltVehicle();    break;
    }
  }
}

void driveForward() {
  analogWrite(ENA, activeSpeed);
  analogWrite(ENB, activeSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void driveBackward() {
  analogWrite(ENA, activeSpeed);
  analogWrite(ENB, activeSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void executeLeft() {
  analogWrite(ENA, activeSpeed);
  analogWrite(ENB, activeSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void executeRight() {
  analogWrite(ENA, activeSpeed);
  analogWrite(ENB, activeSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void haltVehicle() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
