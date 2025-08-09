# Task-4-of-Electronic-IOT-Track
# 1. Controlling 4 DC Motors with 2 L293D ICs
## Project Overview
This project demonstrates how to control 4 DC motors using two L293D motor driver ICs with an Arduino Uno. The system supports:

Bidirectional motor control (forward/reverse)

Independent speed adjustment via PWM

Three movement patterns:

- Forward motion (30 seconds)

- Backward motion (60 seconds)

- Alternating left/right turns (60 seconds)

Designed for robotic vehicles and mechatronics projects

## Components List


<img width="1460" height="460" alt="image" src="https://github.com/user-attachments/assets/88f8c891-a7ba-4b38-b3b4-0746995695f9" />


## Detailed Wiring Guide


## 1# L293D (Left/Right Motors)

- Pin 1 (Enable 1,2) → Arduino ~5 (PWM) → Controls left motor speed

- Pin 2 (Input 1) → Arduino D2 → Left motor (+) direction control

- Pin 3 (Output 1) → Left motor red wire → Motor positive terminal

- Pin 6 (Output 2) → Left motor black wire → Motor negative terminal

- Pin 7 (Input 2) → Arduino D3 → Left motor (-) direction control

- Pin 9 (Enable 3,4) → Arduino ~6 (PWM) → Controls right motor speed

- Pin 10 (Input 3) → Arduino D4 → Right motor (+) direction control

- Pin 11 (Output 3) → Right motor red wire → Motor positive terminal

- Pin 14 (Output 4) → Right motor black wire → Motor negative terminal

- Pin 15 (Input 4) → Arduino D7 → Right motor (-) direction control

- Pin 8 (Vcc2/VSS) → External 7-12V power → Motor power supply

- Pin 16 (Vcc1/VCC) → Arduino 5V → Logic power

- Pins 4,5,12,13 (GND) → Arduino GND → Common ground


## 2# L293D (Front/Rear Motors)

- Pin 1 (Enable 1,2) → Arduino ~9 (PWM) → Controls front motor speed

- Pin 2 (Input 1) → Arduino D8 → Front motor (+) direction control

- Pin 3 (Output 1) → Front motor red wire → Motor positive terminal

- Pin 6 (Output 2) → Front motor black wire → Motor negative terminal

- Pin 7 (Input 2) → Arduino D10 → Front motor (-) direction control

- Pin 9 (Enable 3,4) → Arduino ~11 (PWM) → Controls rear motor speed

- Pin 10 (Input 3) → Arduino D12 → Rear motor (+) direction control

- Pin 11 (Output 3) → Rear motor red wire → Motor positive terminal

- Pin 14 (Output 4) → Rear motor black wire → Motor negative terminal

- Pin 15 (Input 4) → Arduino D13 → Rear motor (-) direction control

- Pin 8 (Vcc2/VSS) → External 7-12V power → Motor power supply

- Pin 16 (Vcc1/VCC) → Arduino 5V → Logic power

- Pins 4,5,12,13 (GND) → Arduino GND → Common ground



<img width="1760" height="1262" alt="image" src="https://github.com/user-attachments/assets/36168188-2a88-4dfe-83c4-8503595b15af" />
<img width="1750" height="1240" alt="image" src="https://github.com/user-attachments/assets/baec4fda-f305-46d9-b508-03c951616d39" />



## Arduino Code


<img width="1198" height="1576" alt="Screenshot 2025-08-09 094333" src="https://github.com/user-attachments/assets/32b26e93-716b-4c94-a7d9-5f6614c18428" />
<img width="1112" height="1402" alt="Screenshot 2025-08-09 094414" src="https://github.com/user-attachments/assets/dd898d9f-0303-4b77-88c4-eb9ad17c32e9" />
<img width="1048" height="1590" alt="Screenshot 2025-08-09 094519" src="https://github.com/user-attachments/assets/ef1cdb7f-42b7-447b-83c4-cee1a96400b9" />
<img width="850" height="768" alt="Screenshot 2025-08-09 094547" src="https://github.com/user-attachments/assets/a30f4ffb-9ae5-4a51-aa0f-e5c489868041" />

## Safety Considerations

### Electrical Safety

- Double-check all polarities before powering on

- Use separate power supplies for Arduino and motors

- Implement fuse protection (1A fast-blow recommended)

### Thermal Management

- Monitor IC temperature during initial tests

- Add heatsinks if continuous operation >5 minutes

- Allow cooling periods between heavy use

### Mechanical Safety

- Secure all moving parts before testing

- Keep clear of rotating components

- Work in clear space free of obstructions


# 2. Monitoring the Obstacles with L293D IC
## Project Overview
This project demonstrates how to control a servo motor using an L293D motor driver and an HC-SR04 ultrasonic sensor with an Arduino. When an obstacle is detected within 10 cm, the servo motor stops and reverses its direction.
This setup is useful for:

- Robotics (obstacle avoidance)

- Automated systems (changing direction upon detection)

- Educational purposes (learning motor control & sensor integration)

## Components List


<img width="1720" height="400" alt="image" src="https://github.com/user-attachments/assets/7a8d1a59-5420-4519-884f-a0c7964f5aac" />


## Detailed Wiring Guide

### Arduino → L293D

- Pin 5 (PWM) → EN1 (Pin 1) (Speed control)

- Pin 2 (Digital) → IN1 (Pin 2) (Direction control)

- Pin 3 (Digital) → IN2 (Pin 7) (Direction control)

- 5V → VCC1 (Pin 16) (Logic power)

- GND → GND (Pins 4,5,12,13) (Common ground)

### L293D → Servo Motor

- OUT1 (Pin 3) → Signal (Yellow/Orange wire) (PWM control)

- OUT2 (Pin 6) → Power (Red wire) (Servo V+)

- GND (Pins 4,5,12,13) → GND (Brown/Black wire)

### Arduino → HC-SR04 Ultrasonic

- Pin 9 (Digital) → Trig (Trigger pulse)

- Pin 10 (Digital) → Echo (Echo pulse)

- 5V → VCC (Sensor power)

- GND → GND (Sensor ground)

### Power Notes

- L293D VCC2 (Pin 8) → *Optional external power (5V-12V)* for high-torque servos.

- L293D EN2 (Pin 9) → Leave disconnected (not used in this setup).


<img width="1738" height="1074" alt="image" src="https://github.com/user-attachments/assets/d9649e59-f1a1-4199-8b5e-8cde8a6c5a4f" />


## Arduino Code


<img width="1356" height="1542" alt="Screenshot 2025-08-09 101200" src="https://github.com/user-attachments/assets/edf5b3a2-7f0f-4576-b1b8-0519c4877374" />
<img width="1230" height="1578" alt="Screenshot 2025-08-09 101231" src="https://github.com/user-attachments/assets/bd6045be-e384-4750-ab66-4a30616e5fcd" />
<img width="1294" height="564" alt="Screenshot 2025-08-09 101304" src="https://github.com/user-attachments/assets/e999d214-4eeb-4d6a-9ea3-b3894cf414b3" />


## Safety Considerations

### Electrical Safety
1. Voltage Limits:

- Arduino: 5V (USB) / 7-12V (DC jack)

- L293D Logic (VCC1): 5V max

- Servo: 4.8-6V (small) / 6-12V (large) → Use external supply

2. Current Limits:

- Arduino 5V: 500mA (USB) / 1A (DC jack) → Avoid overloading.

- L293D: 600mA per channel → Heat sink if exceeded.

3. Short-Circuit Protection:

- Double-check wiring before powering on.

- Add a 1A fuse for high-power servos.

### Thermal Safety
1. L293D:

- Gets hot under load → Add heat sink.

- Touch-test: If too hot (>60°C), reduce duty cycle.

2. Servo:

- High-torque models heat up → Allow cooldown breaks.

### Mechanical Safety
1. Servo Limits:

- Avoid forcing beyond 0°-180° (damages gears).

- Secure mounting to prevent vibrations/loose parts.

2. Ultrasonic Sensor:

- Keep away from moving parts to avoid collisions.


















