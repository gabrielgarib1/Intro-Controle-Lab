# DAS5210 — Introduction to Process Control (Lab Activities)

This repository contains the laboratory code and supporting files for DAS5210 — Introduction to Process Control (2024/1). The labs use a DC motor experimental kit controlled with an Arduino and focus on understanding static and dynamic input-output behavior and designing basic feedback controllers.

## Quick overview

- Lab 0 — Kit introduction: learn the experimental setup, components, and get the motor running. Groups are formed and components distributed.
- Lab 1 — Static input-output analysis: observe motor output for different inputs, identify dead-zone and linear operating region, add a first-order digital filter, and model the static relationship between input (voltage/command) and output (speed or other measured variable).
- Lab 2 — Dynamic input-output analysis: using the linear region identified in Lab 1, measure the motor's dynamic response and fit a first-order linear model.
- Lab 3 — On-off controller: implement a bang-bang (on-off) controller that respects the motor's minimum/maximum voltage and speed limits.
- Lab 4 — Proportional controller (P): implement proportional control and study the effect on dynamic response and steady-state error.
- Lab 5 — Proportional-Integral controller (PI): implement PI control, observe improved steady-state error, study integral windup, and implement anti-windup.
- Lab 6 — Proportional-Integral-Derivative controller (PID): implement PID control and evaluate closed-loop performance.

## Goals and learning outcomes

- Become familiar with the experimental DC motor kit and measurement tools (Arduino).
- Characterize the motor's static and dynamic behavior.
- Implement and tune basic controllers (on-off, P, PI, PID) and understand trade-offs like stability, transient response, and steady-state error.
- Learn practical issues such as dead-zone, actuator saturation, and integral windup.

## How to use

1. Open the appropriate sketch for the lab you are working on (for example, `Lab3_onoff.cpp`).
2. Open the sketch in the Arduino IDE or compatible build system. Configure the correct board and serial port.
3. Upload the code to the Arduino and follow the lab instructions to run experiments and record results.

## Tips

- Always identify the motor's dead-zone and safe operating range before testing controllers.
- Use simple logging (serial prints) and plotting (Serial Plotter or external tools) to visualize responses.
- When tuning PI/PID, start with small gains and increase gradually. Implement anti-windup when using an integrator and expect actuator saturation.
- Install and use Better Serial Plotter software to get better data from arduino.
