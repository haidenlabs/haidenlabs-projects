# Arduino OLED Lyric Animation 🎬

A professional text animation project for Arduino Nano using a 128x64 SSD1306 OLED display. This project features custom "Inside-Out" transitions and a smooth "Typewriter" effect for poetic text rendering.

## ✨ Features
* **Dynamic Animations:** Custom logic for centered "Inside-Out" frame transitions.
* **Typewriter Effect:** Smooth, line-by-line character rendering with vertical centering.
* **Professional Typography:** Integrates multiple Adafruit GFX fonts for a high-end look.
* **Perfect Centering:** Advanced coordinate math to ensure text is perfectly aligned on the 128x64 grid.

## 🛠 Hardware Connection
| Component--- | Arduino Pin |
| :----------- | :-----------|
| **OLED VCC** | 3.3V or 5V |
| **OLED GND** | GND |
| **OLED SCL** | A5 (I2C) |
| **OLED SDA** | A4 (I2C) |

![Connection Diagram](./CONNECTION%20DIAGRAM.jpeg)

## 📦 Prerequisites
You will need the following libraries installed in your Arduino IDE:
1. `Adafruit_SSD1306`
2. `Adafruit_GFX_Library`

## 🚀 Getting Started
1. Clone this repository.
2. Ensure `CONNECTION DIAGRAM.jpeg` is in the same directory for reference.
3. Open `OLED_Lyrics.ino` in your Arduino IDE.
4. Select **Arduino Nano** as your board.
5. Hit **Upload** and watch the magic!
