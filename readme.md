# Density-Based Traffic Light System

This project is a density-based traffic light control system that uses ultrasonic sensors to detect vehicle density on the road. The system adjusts traffic lights based on the density of vehicles in different lanes, ensuring efficient traffic flow. This README provides an overview of the system and its code.

## Hardware Setup

To implement the density-based traffic light system, you'll need the following components:

- 4 Ultrasonic Sensors
- 4 LEDs for Red Signals (ledPinR1, ledPinR2, ledPinG1, ledPinG2)
- Arduino or compatible microcontroller

Components Used
Ultrasonic Sensors
4 Ultrasonic Sensors (HC-SR04 or similar)
Each sensor requires two pins: Trigger (Trig) and Echo (Echo).
LEDs
4 LEDs for Red Signals (ledPinR1, ledPinR2, ledPinG1, ledPinG2)
Arduino Board
An Arduino or compatible microcontroller.
Hardware Connections
Here are the hardware connections for the components used in the density-based traffic light system:

Ultrasonic Sensors
Sensor 1
Trigger (Trig): Connected to pin 13 on the Arduino.
Echo (Echo): Connected to pin 12 on the Arduino.
Sensor 2
Trigger (Trig): Connected to pin 3 on the Arduino.
Echo (Echo): Connected to pin 11 on the Arduino.
Sensor 3
Trigger (Trig): Connected to pin 2 on the Arduino.
Echo (Echo): Connected to pin 10 on the Arduino.
Sensor 4
Trigger (Trig): Connected to pin 9 on the Arduino.
Echo (Echo): Connected to pin 4 on the Arduino.
LEDs
Red Signals
Red LED 1: Connected to pin 8 on the Arduino (ledPinR1).
Red LED 2: Connected to pin 7 on the Arduino (ledPinR2).
Red LED 3: Connected to pin 6 on the Arduino (ledPinG1).
Red LED 4: Connected to pin 5 on the Arduino (ledPinG2).
Power Supply
Ensure that your Arduino board is powered properly, either through USB or an external power source, depending on your specific Arduino model.

Arrangement
The arrangement of the ultrasonic sensors and LEDs will depend on your specific setup. Here are some general guidelines:

Ultrasonic Sensors: Place the ultrasonic sensors at appropriate locations to monitor the traffic in different lanes. For example, you might install them above each lane to measure the distance to vehicles in that lane.

LEDs: The LEDs represent the traffic signal lights. You can connect them to your Arduino and arrange them to indicate traffic signals for each lane. Red LEDs indicate the red signal, and green LEDs indicate the green signal.

Ensure that the sensors have a clear line of sight to the traffic in their respective lanes. Position the LEDs in a way that is visible to drivers and pedestrians.

Powering the System
Make sure your Arduino board is powered using a suitable power source (USB, battery, or external power supply) to ensure continuous operation.

With these hardware connections and the provided Arduino code, your density-based traffic light system will effectively manage traffic flow based on vehicle density in different lanes.

## How It Works

This system uses four ultrasonic sensors to measure the distance to vehicles in different lanes. It then adjusts the traffic lights based on the density of vehicles in each lane, improving traffic flow.

## Modes of Operation

The system has five modes of operation:

1. MODE1: Fewer vehicles in lanes 1 and 2, no obstacles in lanes 3 and 4.
2. MODE2: More vehicles in lanes 1 and 2, no obstacles in lanes 3 and 4.
3. MODE3: Fewer vehicles in lanes 3 and 4, no obstacles in lanes 1 and 2.
4. MODE4: More obstacles in lanes 3 and 4, no obstacles in lanes 1 and 2.
5. MODE5: All lanes have moderate vehicle density.

