# RFID-Gemini-GPT-Opener

![Python](https://img.shields.io/badge/Python-3.x-blue.svg)
![Arduino IDE](https://img.shields.io/badge/Arduino-IDE-green.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

This project integrates **Arduino with RFID** and a **Python desktop script** to automatically launch applications or websites when specific RFID cards or tokens are scanned.  

## 🚀 Features
- Detects RFID cards using Arduino.
- Sends commands to the computer via serial communication.
- Launches different apps/websites based on the card scanned.
- Example setup:
  - **Admin Card** → Opens personal portfolio.
  - **Token** → Opens Google Gemini.

## 🛠️ Tech Stack
- **Arduino (C++ with `.ino`)** – Handles RFID scanning and sends signals via serial.
- **Python (`app_launcher.py`)** – Listens for commands from Arduino and launches applications/websites.
- **Hardware** – Arduino + RFID Module + RFID Tags.

## 📂 Project Structure

├── rfid_logic.ino # Arduino code for RFID reader
├── app_launcher.py # Python script to launch apps/websites
└── README.md # Project documentation


## ⚙️ Setup & Installation

### 1. Arduino Setup
- 1. Open `rfid_logic.ino` in the Arduino IDE.
- 2. Connect your Arduino and upload the code.
- 3. Make sure the RFID module is wired correctly to the Arduino.

### 2. Python Setup
1. Install dependencies:
   ```bash
   pip install pyserial

## Edit app_launcher.py if you want to change URLs:
PORTFOLIO_URL = "https://your-portfolio-link.com" #or any link
GEMINI_URL = "https://gemini.google.com/" #or any link

## Run the Python script:
python app_launcher.py


### 3.Usage
- # 1. Connect Arduino with RFID module.
- # 2. Run the Python script.
- # 3. Scan RFID cards:
    - Admin card → Opens your portfolio.
    - Other token → Opens Gemini (or other assigned apps/websites).

### 🖼️ Demo Flow
- # 1. Arduino detects RFID card.
- # 2. Sends command like OPEN_PORTFOLIO or OPEN_GEMINI to computer.
- # 3. Python script receives command and launches the mapped website.

### 🧩 Customization
- Modify rfid_logic.ino to send different commands for different RFID tags.
- Update app_launcher.py to open different applications/websites.

