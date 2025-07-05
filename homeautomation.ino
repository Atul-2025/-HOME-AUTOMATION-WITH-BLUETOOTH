#include <SoftwareSerial.h>               // Include SoftwareSerial library to allow serial communication on other digital pins

SoftwareSerial mySerial(6, 7);            // Create a SoftwareSerial object named 'mySerial' using pin 6 as RX and pin 7 as TX (used for Bluetooth like HC-05)

void setup()
{
  Serial.begin(9600);                     // Initialize serial communication with the computer at 9600 baud rate
  mySerial.begin(9600);                   // Initialize software serial communication (e.g., with HC-05 Bluetooth module) at 9600 baud rate

  pinMode(12, OUTPUT);                    // Set digital pin 12 as output (e.g., to control a device/LED)
  pinMode(11, OUTPUT);                    // Set digital pin 11 as output
  pinMode(10, OUTPUT);                    // Set digital pin 10 as output
  pinMode(9, OUTPUT);                     // Set digital pin 9 as output

  digitalWrite(12, HIGH);                 // Turn off device connected to pin 12 (assuming active LOW configuration)
  digitalWrite(11, HIGH);                 // Turn off device on pin 11
  digitalWrite(10, HIGH);                 // Turn off device on pin 10
  digitalWrite(9, HIGH);                  // Turn off device on pin 9
}

void loop()
{
  if (mySerial.available() > 0)           // Check if data is available from the Bluetooth module
  {
    char data = mySerial.read();          // Read one character from the Bluetooth serial
    Serial.println(data);                 // Print the received character to the serial monitor for debugging

    if (data == 'B')                      // If the received character is 'B'
    {
      digitalWrite(12, HIGH);            // Turn OFF the device on pin 12 (HIGH = off in active LOW logic)
    } 
    else if (data == 'A')                 // If received 'A'
    {
      digitalWrite(12, LOW);             // Turn ON the device on pin 12
    }
    else if (data == 'D')                 // If received 'D'
    {
      digitalWrite(11, HIGH);            // Turn OFF device on pin 11
    }
    else if (data == 'C')                 // If received 'C'
    {
      digitalWrite(11, LOW);             // Turn ON device on pin 11
    }
    else if (data == 'F')                 // If received 'F'
    {
      digitalWrite(10, HIGH);            // Turn OFF device on pin 10
    }
    else if (data == 'E')                 // If received 'E'
    {
      digitalWrite(10, LOW);             // Turn ON device on pin 10
    }
    else if (data == 'H')                 // If received 'H'
    {
      digitalWrite(9, HIGH);             // Turn OFF device on pin 9
    }
    else if (data == 'G')                 // If received 'G'
    {
      digitalWrite(9, LOW);              // Turn ON device on pin 9
    }
  }
}
