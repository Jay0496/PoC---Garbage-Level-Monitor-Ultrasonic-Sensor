# PoC Garbage Level Monitor Ultrasonic-Sensor

## **Purpose**
This project demonstrates a proof of concept for measuring distance and estimating battery life using an ultrasonic sensor, LED, and LCD screen connected to an Arduino Uno. The system:  
1. Measures distance using an ultrasonic sensor.  
2. Lights up an LED if an object is detected within 10 cm.  
3. Displays real-time distance and estimated battery life percentage on an LCD.  

This setup serves as a foundation for more complex applications, such as obstacle detection or battery-powered monitoring systems. This was made specifically for a larger project LORA garbage level monitoring system needs to indicate when the bin is becoming full or there is a low battery to either empty the bin or switch out the battery for the sensor.

---

## **How It Works**
1. The **ultrasonic sensor** emits sound waves to measure the distance to an object.  
   - If the measured distance is less than 10 cm, the **LED** turns on as an alert.  
2. The system includes a **voltage divider** to simulate battery voltage monitoring. The measured voltage is used to calculate the battery life percentage.  
3. Both distance and battery life percentages are updated every second and displayed on the **LCD screen**.

---

## **Hardware Requirements**
- 1 x Arduino Uno  
- 1 x Breadboard  
- 1 x Ultrasonic Sensor (HC-SR04)  
- 1 x I2C LCD (16x2)  
- 1 x LED (any colour)  
- 1 x 220Ω resistor for the LED  
- 2 x 10kΩ resistors for the voltage divider  
- Jumper wires  

---

## **Circuit Diagram**
![image](https://github.com/user-attachments/assets/edc43dfc-80a3-4233-a251-cab74197c709)



---

## **Connections**
### **Ultrasonic Sensor**:
| Sensor Pin | Arduino Pin   |
|------------|---------------|
| VCC        | 5V            |
| GND        | GND           |
| TRIG       | Digital Pin 7 |
| ECHO       | Digital Pin 6 |

### **LED (Series Connection)**:
| LED Pin | Arduino Pin   |
|---------|---------------|
| Anode   | Digital Pin 13 (via 220Ω resistor) |
| Cathode | GND           |

### **LCD (I2C Connection)**:
| LCD Pin | Arduino Pin   |
|---------|---------------|
| SDA     | A4            |
| SCL     | A5            |
| VCC     | 5V            |
| GND     | GND           |

### **Voltage Divider (Parallel Connection)**:
| Resistor Connections | Details                         |
|-----------------------|---------------------------------|
| R1 (10kΩ)            | Between A0 and GND             |
| R2 (10kΩ)            | Between A0 and battery (5V)    |

---

## **Steps to Run the Project**
1. Connect the hardware as described above.  
2. Upload the provided Arduino code to your Arduino Uno using the Arduino IDE.  
3. Power the Arduino and monitor the output on the LCD.  
4. Use the Tinkercad simulator to test distance and battery life scenarios before building the physical circuit.  

---

## **Output Explanation**
1. **LCD Display**:  
   - Displays the measured distance (in cm).  
   - Displays the estimated battery life percentage.  

2. **LED Behavior**:  
   - Lights up when the distance is less than 10 cm.  
   - Turns off when the distance is or exceeds 10 cm.  

---

## **Future Improvements**  
- Use a real battery to measure the actual voltage and estimate the battery life.  
- Expand on it using LORA to send the information to a computer and store it in a database.
