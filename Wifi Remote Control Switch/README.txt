# WiFi Remote Control Switch

This project provides two options for building a **WiFi Remote Control Switch** using Arduino. The switch can be controlled remotely either via a cloud server (Option 1) or by setting up a local Wi-Fi access point (Option 2).

## Table of Contents

- [Overview](#overview)
- [Options](#options)
  - [Option 1: Cloud Server](#option-1-cloud-server)
  - [Option 2: Wi-Fi Access Point](#option-2-wi-fi-access-point)
- [Hardware Requirements](#hardware-requirements)
- [Setup Instructions](#setup-instructions)
- [License](#license)

---

## Overview

The **WiFi Remote Control Switch** project allows you to control an electronic device remotely via Wi-Fi. You have two options for connecting and controlling the switch:

1. **Cloud Server**: The switch connects to the internet and can be controlled from anywhere via a cloud-based interface.
2. **Wi-Fi Access Point**: The Arduino acts as a local access point, allowing nearby devices to connect and control the switch without internet access.

Both options provide flexible ways to control devices, such as lights, fans, or appliances, from a smartphone, computer, or other connected devices.

---

## Options

### Option 1: Cloud Server

In this option, the Arduino connects to your Wi-Fi network and acts as a server. You can control the switch from anywhere through a web interface or mobile device by accessing the cloud server.

**File:** `cloud_server.ino`

#### How It Works

- The Arduino connects to a specified Wi-Fi network using a Wi-Fi module (e.g., ESP8266 or ESP32).
- It creates a cloud server that can handle requests from remote devices.
- You can control the connected switch from a web interface, turning it on or off remotely.

### Option 2: Wi-Fi Access Point

In this option, the Arduino creates its own local Wi-Fi access point, allowing devices in range to connect directly to it and control the switch.

**File:** `Wifi_access_point.ino`

#### How It Works

- The Arduino acts as a Wi-Fi access point, broadcasting a network.
- Devices can connect to this network without needing an internet connection.
- Once connected, users can access a web interface to control the switch locally.

---

## Hardware Requirements

- Arduino board (e.g., ESP8266 or ESP32)
- Relay module (to control the external device)
- Wi-Fi module (ESP8266 or ESP32)
- Breadboard and jumper wires
- USB cable to connect Arduino to the computer

---

## Setup Instructions

### Step 1: Clone the Repository

```bash
git clone https://github.com/waiyaraung111/Arduino-Projects-Collection.git
```

### Step 2: Open the Relevant File in Arduino IDE

- For **Option 1**, open `cloud_server.ino`.
- For **Option 2**, open `Wifi_access_point.ino`.

### Step 3: Modify Wi-Fi Credentials

In both options, modify the Wi-Fi credentials in the code to match your network (for Option 1) or set a custom SSID and password (for Option 2):

```cpp
const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
```

### Step 4: Upload the Code to Arduino

1. Connect your Arduino to the computer.
2. Upload the code through the Arduino IDE.

### Step 5: Test the Setup

- **Option 1 (Cloud Server)**: After uploading, open the Serial Monitor to get the IP address of your Arduino. Use this IP to access the cloud server from any browser and control the switch.
- **Option 2 (Wi-Fi Access Point)**: Once the Arduino creates the access point, connect to it using a device (e.g., smartphone) and open a browser to access the local control interface.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

