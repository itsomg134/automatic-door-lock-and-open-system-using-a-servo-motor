# automatic-door-lock-and-open-system-using-a-servo-motor

# 🚪 Automatic Door Lock and Open System

An Arduino-based automatic door control system that combines a servo motor for locking/unlocking and a DC motor for opening/closing the door. Features motion detection and manual controls for a complete smart door solution.

## 📋 Overview

This project implements an intelligent door automation system using Arduino Uno. The system automatically detects motion, unlocks the door, opens it, keeps it open for a preset time, and then closes and locks it again. Perfect for home automation, smart offices, or accessible entrance systems.

## ✨ Features

- **Automatic Motion Detection** - PIR sensor triggers door opening when someone approaches
- **Servo-Controlled Lock** - Smooth locking and unlocking mechanism
- **DC Motor Door Control** - Powerful motor opens and closes the door
- **Manual Override** - Physical buttons for manual operation
- **State Machine Logic** - Smooth transitions between door states
- **Status LED Indicator** - Visual feedback for door status
- **Configurable Timings** - Easy to adjust open/close/wait times
- **Serial Monitoring** - Real-time status updates via Serial Monitor

## 🔧 Hardware Requirements

### Components
- Arduino Uno (or compatible board)
- Servo Motor (SG90 or similar)
- DC Motor with gearbox (12V recommended)
- L298N Motor Driver Module
- PIR Motion Sensor (HC-SR501)
- 2x Push Buttons
- LED (optional, can use built-in LED)
- Jumper Wires
- Breadboard
- 12V Power Supply for DC motor
- 5V Power Supply for Arduino (USB or adapter)

### Optional Components
- Limit switches for accurate door position detection
- Ultrasonic sensor as alternative to PIR
- LCD display for status messages
- Buzzer for audio feedback

## 📐 Circuit Diagram

### Pin Connections

| Component | Arduino Pin | Notes |
|-----------|-------------|-------|
| Servo Signal | 9 | PWM capable |
| Servo VCC | 5V | - |
| Servo GND | GND | - |
| L298N IN1 | 5 | Motor direction |
| L298N IN2 | 6 | Motor direction |
| L298N EN | 10 | PWM speed control |
| PIR Sensor OUT | 2 | Digital input |
| Open Button | 3 | Internal pullup |
| Close Button | 4 | Internal pullup |
| Status LED | 13 | Built-in LED |

### L298N Motor Driver Connections
- **OUT1 & OUT2**: Connect to DC motor terminals
- **12V & GND**: Connect to 12V power supply
- **5V**: Can power Arduino if jumper is set (optional)

## 🚀 Installation

### Step 1: Clone the Repository
```bash
git clone https://github.com/yourusername/automatic-door-lock-system.git
cd automatic-door-lock-system
```

### Step 2: Install Arduino IDE
Download and install from [Arduino Official Website](https://www.arduino.cc/en/software)

### Step 3: Install Required Libraries
- **Servo Library** - Usually pre-installed with Arduino IDE
- No external libraries required!

### Step 4: Upload Code
1. Open `automatic_door_lock.ino` in Arduino IDE
2. Select **Tools → Board → Arduino Uno**
3. Select correct **Port**
4. Click **Upload** button

## 🎮 Usage

### Basic Operation
1. **Power On**: System starts with door LOCKED and CLOSED
2. **Motion Detection**: Walk in front of PIR sensor
3. **Auto Open**: Door unlocks and opens automatically
4. **Wait Time**: Door stays open for 5 seconds (configurable)
5. **Auto Close**: Door closes and locks automatically

### Manual Controls
- **Open Button**: Force door to unlock and open
- **Close Button**: Force door to close immediately
- **LED Indicator**: 
  - OFF = Door closed and locked
  - ON = Door open or opening

### Serial Monitor
Open Serial Monitor (115200 baud) to see real-time status:
```
Automatic Door System Initialized
Door is LOCKED and CLOSED
Motion detected! Unlocking door...
Lock: UNLOCKED
Door unlocked. Opening...
Motor: OPENING
Door is OPEN
Closing door...
Motor: CLOSING
Motor: STOPPED
Door closed. Locking...
Lock: LOCKED
Door is LOCKED and CLOSED
```

## ⚙️ Configuration

Adjust these constants in the code to customize behavior:

```cpp
#define SERVO_LOCK_POS 0     // Locked angle (0-180)
#define SERVO_UNLOCK_POS 90  // Unlocked angle (0-180)
#define MOTOR_SPEED 200      // Motor speed (0-255)
#define DOOR_OPEN_TIME 3000  // Time to fully open (ms)
#define DOOR_CLOSE_TIME 3000 // Time to fully close (ms)
#define DOOR_WAIT_TIME 5000  // How long door stays open (ms)
```

## 🔍 Troubleshooting

### Door doesn't open
- Check DC motor connections to L298N
- Verify 12V power supply is connected
- Increase `MOTOR_SPEED` value
- Check motor direction (swap IN1 and IN2 if needed)

### Servo doesn't move
- Ensure servo is powered (5V and GND)
- Check signal wire connection to pin 9
- Test servo separately with sweep example

### PIR sensor not detecting
- Wait 30-60 seconds after power on (calibration time)
- Adjust sensitivity potentiometer on PIR
- Check 5V and GND connections

### Motor runs but door doesn't move
- Check mechanical coupling between motor and door
- Increase motor speed or use geared motor
- Ensure motor has sufficient torque

## 🛠️ Customization Ideas

- Add **RFID/Keypad** for access control
- Implement **limit switches** for precise positioning
- Add **ultrasonic sensor** for obstacle detection
- Integrate with **home automation** (WiFi/Bluetooth)
- Add **emergency override** mechanism
- Install **magnetic lock** for additional security
- Connect to **smartphone app** for remote control

## 📊 System States

```
LOCKED_CLOSED → UNLOCKING → OPENING → OPEN → CLOSING → LOCKING → LOCKED_CLOSED
      ↑                                                                   ↓
      └───────────────────────────────────────────────────────────────────┘
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## ⚠️ Safety Warnings

- **Power Safety**: Use appropriate power supplies and avoid shorts
- **Mechanical Safety**: Ensure door mechanism cannot trap or injure users
- **Testing**: Test thoroughly before deploying in public areas
- **Emergency Stop**: Implement emergency stop mechanism for safety
- **Supervision**: Don't leave system unattended during initial testing

## 📧 Contact

Your Name - [@itsom134](https://github.com/itsomg134)

## 🙏 Acknowledgments

- Arduino Community for excellent documentation
- All contributors who help improve this project
- Open source hardware community



🐛 **Report issues** to help improve the project

💡 **Suggest features** for future updates
<img width="1920" height="1080" alt="Screenshot (85)" src="https://github.com/user-attachments/assets/e0ccec37-2c91-4077-a695-2eeded744559" />
<img width="1920" height="1080" alt="Screenshot (84)" src="https://github.com/user-attachments/assets/6f10c03f-7567-4b79-93fe-bd8331cfd86f" />

