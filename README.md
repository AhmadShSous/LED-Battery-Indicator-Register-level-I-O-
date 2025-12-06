# Battery Indicator — Register-Level I/O (ATmega328P)

This project uses **direct register access (PORT, DDR, PINx)** to control two LEDs and a push-button to simulate battery status on an Arduino Uno (ATmega328P).

##  Hardware Connections
| Component | MCU Pin | Description |
|----------|---------|-------------|
| LED1     | PB3 (D11) | ON in Battery OK mode |
| LED2     | PD6 (D6)  | Blinks in Battery LOW mode |
| Button   | PD2 (D2)  | Toggles battery mode (with internal pull-up) |

##  System Logic
- **Battery OK →** LED1 ON, LED2 OFF  
- **Battery LOW →** LED1 OFF, LED2 blinking at 2Hz (250ms toggle)  
- Button toggles between modes (debounced manually).

##  Features
- Direct register manipulation  
- Non-blocking LED blinking using `millis()`  
- Internal pull-up enabled for button  
- Clean and simple code structure  

##  Project Files
- `main.ino` → Main code  
- `README.md` → This documentation  

##  How to Run
1. Open Arduino IDE  
2. Copy `main.ino`  
3. Choose board: **Arduino Uno**  
4. Upload  
5. Press the button to switch battery modes  

##  Expected Output
- Default: **LED1 ON**, **LED2 OFF**  
- After pressing button: **LED1 OFF**, **LED2 BLINKING**

 ##  Simulation (TinkerCad)

You can view and test the full circuit and code on TinkerCad:  

 **TinkerCad Project Link:**  
**https://www.tinkercad.com/things/0tpFZtYX7rU-surprising-habbi-leelo?sharecode=PT-4j8QcRYN70GHRgecWcGFcuWLkYKxQ7y5PbQp37lw**


