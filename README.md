# smart-irrigation-iot
Smart Irrigation System using ESP32, Soil Moisture Sensor, Relay and Blynk IoT
# 🌱 Smart Irrigation System using ESP32 & Blynk IoT

## 📌 Project Overview
This project is a **Smart Irrigation System** that monitors soil moisture and automatically controls a water pump using ESP32 and Blynk IoT.

It helps in:
- Saving water 💧
- Reducing manual effort 🤖
- Maintaining healthy plants 🌿

---

## ⚙️ Components Used
- ESP32 Microcontroller
- Soil Moisture Sensor
- Relay Module
- DC Water Pump
- 9V / External Power Supply
- Jumper Wires
- Blynk IoT App

---

## 🔌 Pin Connections

| Component            | ESP32 Pin |
|---------------------|----------|
| Soil Sensor (AO)    | GPIO34   |
| Relay IN            | GPIO26   |
| VCC / GND           | 3.3V / GND |

---

## 💻 Code Explanation (Simple)

- ESP32 reads soil moisture from **GPIO34**
- Converts it into percentage
- Sends data to **Blynk App (V0)**
- If soil is dry → Pump ON
- If soil is wet → Pump OFF

---

## 🔁 Working Principle

1. Soil sensor reads moisture level  
2. ESP32 processes the data  
3. Data sent to Blynk app  
4. If soil is dry → Relay ON → Pump ON  
5. If soil is wet → Relay OFF → Pump OFF  

---

## 📱 Blynk Setup
- Create a Blynk template
- Add a **Gauge widget**
- Set Virtual Pin to **V0**
- Connect ESP32 using Auth Token

---

## 📊 Output
- Real-time soil moisture percentage
- Automatic irrigation control

---

## 🚀 Future Improvements
- Add mobile notifications 📲
- Use solar power ☀️
- Add multiple sensors 🌱
- Store data in cloud 📊

---

## 👩‍💻 Author
- Your Name

---

## ⭐ Conclusion
This project demonstrates how IoT can be used for **smart agriculture** and efficient water management.
