# Smart Water Level Monitoring System

### Overview
This project is an IoT-based system designed to monitor the water level of a tank in real-time using LEDs as indicators and an Arduino microcontroller. It also tracks how often the tank gets emptied per day, sending data to a web application via Python and Firebase for analysis. This system provides an efficient solution for water management in households, industries, and other setups.

---

### Features
- **LED Indicators**:
  - **Red LED**: Indicates the water level is at maximum.
  - **First Green LED**: Lights up when the water level is slightly low.
  - **Second Green LED**: Lights up when the water level is moderately low.
  - **Third Green LED**: Lights up when the tank is empty.
- **Real-Time Monitoring**: Displays water levels visually using LEDs.
- **Data Analytics**: Tracks how many times the tank is emptied per day and sends the data to a website via Firebase.
- **IoT Integration**: Provides remote access to tank usage data for efficient planning.

---

### Components Used
- **Arduino**: Microcontroller for controlling the sensors and LEDs.
- **Ultrasonic Sensor**: To measure the water level in the tank.
- **Jumper Wires**: For connecting components.
- **Breadboard**: For building the circuit.
- **Small Water Tank**: Used for demonstration.
- **Python**: Script for data processing and Firebase integration.
- **Firebase**: Database for storing water usage data.

---

### How It Works
1. **Water Level Monitoring**:
   - The ultrasonic sensor measures the distance between the top of the tank and the water surface.
   - Based on the water level:
     - **Red LED** glows when the tank is full.
     - **Green LEDs** glow sequentially as the water level decreases.
     - The third green LED lights up when the tank is empty.
2. **Data Logging**:
   - A Python script runs on a computer or Raspberry Pi.
   - The script collects water level data and calculates how often the tank is emptied per day.
   - Data is sent to a Firebase database.
3. **Web Interface**:
   - A web application fetches data from Firebase and displays analytics like daily water usage trends.

---

### Day-to-Day Applications
- **Households**: Monitor water usage to avoid wastage and track refilling requirements.
- **Industries**: Automate water management systems in factories to ensure uninterrupted processes.
- **Farming**: Manage water levels in irrigation tanks efficiently.
- **Schools/Offices**: Keep track of water consumption and improve water conservation efforts.

---

### Setup Instructions
1. **Hardware Setup**:
   - Connect the ultrasonic sensor to the Arduino for water level detection.
   - Wire the LEDs and resistors to the Arduino to act as indicators.
   - Assemble the circuit on a breadboard.
2. **Upload Arduino Code**:
   - Open the Arduino IDE.
   - Load the code provided in the `arduino_code/` folder.
   - Upload it to the Arduino.
3. **Python Script**:
   - Install Python and required libraries:
     ```bash
     pip install pyrebase4
     ```
   - Run the script from the `python_code/` folder:
     ```bash
     python send_data.py
     ```
4. **Firebase Setup**:
   - Create a Firebase project and set up a database.
   - Update the Firebase credentials in the Python script.

---

### Project Files
- **`/arduino_code`**: Contains the Arduino code for water level monitoring and LED control.
- **`/python_code`**: Python script for data logging and Firebase integration.
- **`/website`**: Sample website code to display water usage data (optional).

---

### Contributors
- **[Your Name](https://github.com/AshishGautamX)** (Project Lead)
- **[Your Teacher's Name]** (Owner/Guide)

---

### License
This project is licensed under the MIT License. See `LICENSE` for more details.
