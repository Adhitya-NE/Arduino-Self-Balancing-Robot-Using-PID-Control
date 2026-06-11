# Arduino-Self-Balancing-Robot-Using-PID-Control
An Arduino-based self-balancing robot that maintains its upright position using real-time tilt measurements from an MPU6050 sensor and a PID control algorithm. The system continuously adjusts motor speed and direction through an L298N motor driver to keep the robot balanced on two wheels.

# Overview
This project implements a two-wheeled self-balancing robot using an Arduino Uno as the main controller. The robot utilizes an MPU6050 sensor containing a 3-axis accelerometer and 3-axis gyroscope to measure its tilt angle.

A PID (Proportional–Integral–Derivative) controller processes the tilt error and generates motor control signals that allow the robot to maintain its balance automatically.

# Features
- Real-time tilt angle measurement using MPU6050
- PID-based balancing control
- Two-wheel self-balancing mechanism
- Motor speed and direction control via L298N
- Continuous feedback control loop
- Arduino Uno implementation

# Hardware Components
| Component | Quantity | Function |
|------------|------------|------------|
| Arduino Uno R3 | 1 | Main controller |
| MPU6050 (GY-521) | 1 | Tilt angle measurement |
| L298N Motor Driver | 1 | Motor control |
| N20 DC Gear Motor | 2 | Robot movement |
| Wheels | 2 | Mobility |
| MT3608 Boost Converter | 1 | Voltage regulation |
| AA Battery | 4 | Power source |
| Battery Holder with Switch | 1 | Power management |
| Double-Sided PCB | 3 | Mechanical structure |
| Nylon Spacer | Several | PCB mounting |

# Control System
The robot operates using a closed-loop PID control system.

## Control Flow
1. MPU6050 measures robot tilt angle.
2. Arduino calculates the angle error.
3. PID controller generates correction output.
4. PWM signals are sent to the L298N driver.
5. Motors rotate to counteract falling motion.
6. The process repeats continuously.

## PID Parameters
| Parameter | Value |
|------------|------------|
| Kp | 15.0 |
| Ki | 0.5 |
| Kd | 3.0 |
| Setpoint | 20.0° |

# Wiring Connections
## MPU6050
| MPU6050 | Arduino Uno |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## L298N Motor Driver
| L298N | Arduino Uno |
|--------|------------|
| ENA | 11 |
| IN1 | 7 |
| IN2 | 6 |
| IN3 | 5 |
| IN4 | 4 |
| ENB | 10 |

# Circuit Schematic
<img width="522" height="495" alt="image" src="https://github.com/user-attachments/assets/48de1a3f-f720-4a5c-bbb3-0dfbf7955d0a" />

# Block Diagram
<img width="688" height="276" alt="image" src="https://github.com/user-attachments/assets/8bb07789-04ee-47fa-9ccb-f5ca311d8657" />

# Technologies Used
- Arduino IDE
- Embedded Systems
- PID Control
- MPU6050
- I2C Communication
- DC Motor Control
- PWM Control

# Authors
- Fadlan Umar Rozikin (235150307111032)
- Syieva Maulana Haaq W. (235150307111006)
- Firda Aisyah (235150307111031)
- Michella Alya Carol (235150301111042)
- Adhitya Noer Effendi (235150307111024)
- Adhimu Rizky Ramadhani (235150300111020)
