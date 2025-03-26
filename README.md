# Arduino Motor Control, Bluetooth, and Ultrasonic Sensor Project

This project demonstrates controlling DC motors using an Arduino, receiving commands via Bluetooth and measuring distance with an ultrasonic sensor.  This can be used to control the basic movements of a robot or vehicle.

## Features

* **Motor Control:** Control of 4 DC motors using the Adafruit Motor Shield library (`AFMotor.h`). Supports forward, backward, left, right, and stop commands.
* **Bluetooth Control:** Remotely control the robot via serial communication over a Bluetooth module.  Uses 'F' (forward), 'B' (backward), 'L' (left), 'R' (right), and 'S' (stop) commands.
* **Ultrasonic Distance Measurement:** Measures distance using an HC-SR04 ultrasonic sensor. Used for obstacle avoidance when the robot is moving backward.
* **Speed Measurement (RPM):** Measures motor RPM and speed using an LM393 speed sensor.

## Requirements

* **Hardware:**
    * Arduino Uno (or compatible board)
    * Adafruit Motor Shield v2
    * 4 DC motors
    * L298N Motor Driver
    * HC-SR04 ultrasonic sensor
    * Bluetooth module (e.g., HC-05 or HC-06)
    * LM393 speed sensor
    * Connecting wires
* **Software:**
    * Arduino IDE
    * Adafruit Motor Shield Library

## Setup

1. **Install Libraries:** Install the Adafruit Motor Shield library in the Arduino IDE.
2. **Wiring:** Connect the components according to the Fritzing diagram. Connect the Bluetooth module's RX and TX pins to the Arduino's digital pins. Connect the ultrasonic sensor's trig and echo pins to digital pins 26 and 24, respectively. Connect the LM393 speed sensor to digital pin 2.
3. **Upload Code:** Upload this code to your Arduino.
4. **Bluetooth Connection:** Pair the Bluetooth module with your computer or phone.
5. **Serial Monitor:** Open the Serial Monitor in the Arduino IDE and set the baud rate to 9600.

## Usage

Send the following commands via the Bluetooth connection to control the robot:

* `F`: Forward
* `B`: Backward (stops if an obstacle closer than 10cm is detected)
* `L`: Left
* `R`: Right
* `S`: Stop

The robot's speed (m/s) and the distance read from the ultrasonic sensor (cm) will be displayed on the Serial Monitor.

# Contributors

* Nursen Marancı

* Sena Varıcı
