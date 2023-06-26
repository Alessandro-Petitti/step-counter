
# Step-Counter

Welcome to the Step Counter repository! This project utilizes the M5Stack, a handy integrated development environment (IDE), and the built-in Inertial Measurement Unit (IMU) to count and track the number of steps you take.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

The Step Counter project aims to provide a simple and efficient way to count your steps using the M5Stack device and its integrated IMU. By utilizing the IMU's accelerometer, we can detect motion and infer the number of steps taken.

This repository contains all the necessary code and resources required to set up the step counter on your M5Stack device. The project is open-source!
## Prerequisites

To use this project, you will need the following:

- M5Stack device
- Arduino IDE (or any compatible IDE)
- M5Stack library (installed via Arduino Library Manager)

## Installation

To set up the Step Counter project, follow these steps:

1. Clone this repository to your local machine using the following command:
```bash
git clone https://github.com/Alessandro-Petitti/step-counter.git
```

 Alternatively, you can download the ZIP file and extract it to a local directory.

3. Open the Arduino IDE (or your preferred IDE) and navigate to the project directory.

4. Install the M5Stack library if you haven't already. Open the Arduino Library Manager (**Sketch > Include Library > Manage Libraries**), search for "M5Stack," and click the **Install** button.

5. Connect your M5Stack device to your computer using a USB cable.

6. Open the `podometro.ino` file in the Arduino IDE.

7. Select the appropriate board and port from the **Tools** menu.

8. Click the **Upload** button or press **Ctrl+U** to compile and upload the code to your M5Stack device.

## Usage

To use the Step Counter, follow these instructions:

1. Ensure that the Step Counter project is uploaded and running on your M5Stack device.

2. Place the M5Stack device securely on your belt loops, preferably in the center back of your waist.

3. Start walking or running, and the M5Stack device will count your steps using the IMU's accelerometer.

4. You can monitor the step count on the M5Stack device's display or retrieve it programmatically for further processing.

5. To reset the step count, restart the M5Stack device.


