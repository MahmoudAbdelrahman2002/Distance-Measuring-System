# Distance Measuring System

An embedded C project for AVR microcontroller that implements a real-time distance measuring system using an ultrasonic sensor with LCD display capabilities.

## 📋 Project Overview

This project creates a comprehensive distance measurement system that can accurately detect distances using ultrasonic waves and display the results on an LCD screen. The system is built around an AVR microcontroller and includes additional features like temperature sensing and motor control capabilities.

## ✨ Features

- **Real-time Distance Measurement**: Uses ultrasonic sensor for accurate distance detection
- **LCD Display**: 16x2 character LCD showing distance readings in real-time
- **Temperature Monitoring**: LM35 temperature sensor integration
- **Motor Control**: DC motor with speed control using PWM
- **Precise Timing**: Input Capture Unit (ICU) for accurate echo time measurement
- **Modular Design**: Well-structured code with separate modules for each component
- **Interrupt-driven**: Efficient interrupt-based signal processing

## 🔧 Hardware Requirements

### Essential Components
- **Microcontroller**: AVR ATmega series (ATmega16/32 recommended)
- **Ultrasonic Sensor**: HC-SR04 or compatible
- **Display**: 16x2 Character LCD (HD44780 compatible)
- **Temperature Sensor**: LM35 precision temperature sensor
- **DC Motor**: Standard DC motor for control applications
- **Motor Driver**: L293D or similar H-bridge driver IC
- **Power Supply**: 5V regulated power supply

### Pin Connections
- **Ultrasonic Trigger**: PORTB PIN5
- **Ultrasonic Echo**: Connected to ICU input
- **LCD Control**: 
  - RS: PORTB PIN0
  - Enable: PORTB PIN2
  - Data: PORTA (8-bit mode)
- **Temperature Sensor**: Connected to ADC channel
- **Motor Control**: Connected via PWM pins

## 💻 Software Requirements

### Development Environment
- **IDE**: Eclipse IDE with AVR plugin
- **Compiler**: GCC AVR compiler toolchain
- **Simulation**: Proteus Design Suite (optional)
- **Programmer**: AVR ISP, USBasp, or compatible programmer

### Dependencies
- AVR-libc library
- util/delay.h for timing functions
- avr/io.h for I/O operations
- avr/interrupt.h for interrupt handling

## 🚀 Installation & Setup

### Building the Project

1. **Clone the Repository**
   ```bash
   git clone https://github.com/MahmoudAbdelrahman2002/Distance-Measuring-System.git
   cd Distance-Measuring-System
   ```

2. **Open in Eclipse**
   - Import existing project into Eclipse AVR workspace
   - Project is pre-configured with build settings

3. **Build the Project**
   - Right-click project → Build Project
   - Or use the pre-built makefile in Debug directory

4. **Flash to Microcontroller**
   ```bash
   avrdude -p atmega16 -c usbasp -U flash:w:Mini_priject_4.hex
   ```

### Circuit Setup

1. **Connect the Hardware** according to the pin configuration above
2. **Open Proteus Simulation** (optional):
   - Load `Mini_project_4.pdsprj`
   - Run simulation to test before hardware implementation
3. **Power up the System** and verify all connections

## 📖 Usage Instructions

### Basic Operation

1. **Power On**: Connect 5V power supply to the circuit
2. **Initialization**: LCD will display "Distance =" on startup
3. **Measurement**: System automatically starts measuring distance
4. **Reading**: Distance values are displayed in real-time on LCD
5. **Range**: Effective measuring range depends on ultrasonic sensor (typically 2-400cm)

### Display Format
- **Distance < 100cm**: Shows value with trailing spaces for clean display
- **Distance ≥ 100cm**: Shows full three-digit value
- **Update Rate**: Continuous real-time updates

## 🏗️ Code Structure

### Module Overview

```
├── app.c                 # Main application logic and control loop
├── ultrasonic.c/.h      # Ultrasonic sensor driver and distance calculation
├── lcd.c/.h             # LCD display driver (8-bit mode)
├── icu.c/.h             # Input Capture Unit for precise timing
├── gpio.c/.h            # General Purpose I/O driver
├── adc.c/.h             # Analog-to-Digital Converter driver
├── dc_motor.c/.h        # DC motor control with PWM
├── lm35.c/.h            # LM35 temperature sensor driver
├── pwm.c/.h             # Pulse Width Modulation driver
├── std_types.h          # Standard data type definitions
└── common_macros.h      # Utility macros for bit manipulation
```

### Key Functions

- **`Ultrasonic_readDistance()`**: Main distance measurement function
- **`Ultrasonic_edgeProcessing()`**: Interrupt callback for echo timing
- **`LCD_displayStringRowColumn()`**: LCD text positioning and display
- **`DcMotor_Rotate()`**: Motor control with direction and speed

## 🔧 Technical Details

### Distance Calculation
- **Method**: Time-of-flight measurement using ultrasonic waves
- **Formula**: Distance = (Echo_Time × Sound_Speed) / 2
- **Conversion**: `distance = echo_time / 58.8` (for cm)
- **Precision**: ICU provides microsecond-level timing accuracy

### Interrupt System
- **ICU Interrupt**: Captures rising and falling edges of echo signal
- **Timer**: Used for precise time interval measurement
- **Callback**: `Ultrasonic_edgeProcessing()` handles edge detection

## 👨‍💻 Author

**Mahmoud Abdelrahman**
- GitHub: [@MahmoudAbdelrahman2002](https://github.com/MahmoudAbdelrahman2002)

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 Notes

- Ensure proper wiring before powering the system
- Verify voltage levels match component specifications
- Test in simulation before hardware implementation
- Calibrate ultrasonic sensor for your specific environment if needed

## 🔍 Troubleshooting

### Common Issues
- **No LCD Display**: Check power connections and contrast adjustment
- **Incorrect Readings**: Verify ultrasonic sensor connections and timing
- **Build Errors**: Ensure AVR toolchain is properly installed
- **Programming Issues**: Check programmer connections and device selection

### Debug Tips
- Use Proteus simulation to verify logic before hardware testing
- Check Debug folder for compiled files and build logs
- Verify fuse bit settings for proper clock configuration

---

*This project demonstrates embedded systems design, real-time signal processing, and modular programming practices for AVR microcontrollers.*