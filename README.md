# ♻️ Smart Dustbin

An Arduino-based smart dustbin prototype designed to make waste disposal completely hands-free, hygienic, and clean. By automating the lid mechanism, it helps prevent the spread of germs by ensuring you never have to touch a dirty bin.

## ✨ Features

- **Hands-Free Operation**: Automatically detects your hand or trash nearby and opens the lid without physical contact.
- **Dual Sensor System**: 
  - **Hand Detection**: Senses when an object is brought near the bin.
  - **Fullness Detection**: Monitors the trash level and prevents the lid from opening if the bin is full.
- **Real-Time LCD Feedback**: A 16x2 I2C LCD display keeps you updated with clear status messages ("Ready to Use", "Lid Opening...", "Lid Closed", "Bin is FULL!").
- **Automatic Closure**: The servo motor smoothly lowers the lid back down a few seconds after opening.

## 🛠️ Hardware Requirements

- Arduino Uno
- Servo Motor (e.g., SG90)
- 2x Ultrasonic Sensors (HC-SR04)
- 16x2 LCD Display with I2C Module
- Jumper Wires & Breadboard
- USB Cable (for programming and power)

## 🔌 Wiring / Pinout

| Component | Pin / Feature | Arduino Pin |
| :--- | :--- | :--- |
| **Servo Motor** | Signal | Pin 3 |
| **Hand Sensor** | Trig / Echo | Pin 9 / Pin 10 |
| **Fullness Sensor**| Trig / Echo | Pin 6 / Pin 7 |
| **LCD I2C** | SDA / SCL | A4 / A5 (Default I2C) |

*(Note: Ensure your LCD I2C address matches the code. Default is `0x27`, but some modules use `0x3F`.)*

## ⚙️ How It Works

1. **Initialization**: Upon powering up, the LCD displays "Smart Dustbin" and the servo ensures the lid is closed (0 degrees).
2. **Monitoring**: The Arduino continuously reads distances from both ultrasonic sensors.
3. **Full Bin Check**: If the internal fullness sensor detects trash within 15 cm, the LCD displays "Bin is FULL!" and the lid remains locked shut.
4. **Hand Detection**: If the bin is not full and the hand sensor detects an object within 10 cm, the LCD shows "Lid Opening..." and the servo rotates to 180 degrees.
5. **Auto-Close**: After a 3-second delay, the servo returns to 0 degrees, the LCD

---
*Built with ❤️ using Arduino.*
