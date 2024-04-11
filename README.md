# driver-assistant
It is a driver assistance system using C programming to provide real-time warnings for selecting the appropriate driving mode.

The system is powered by a 12V battery, which is regulated down to 5V using a 7805 voltage regulator to supply the required voltage to the Arduino Uno board and the LM016L LCD display.

The program is designed to display a warning message "Go to P or D" on the LCD when the temperature sensor (LM35) detects a threshold temperature of 100°C. This elevated temperature condition occurs when the vehicle is in the "D" (drive) mode, the vehicle is stationary, and the foot brake is applied.

When the temperature exceeds the threshold, the warning message is displayed on the LCD, and a red LED is made to blink as an additional alert. Once the driver moves the gear selector to the "P" (park) or "N" (neutral) mode, and the temperature drops, the warning message disappears, and the LED stops blinking, as shown in the final figure.

The project demonstrates the integration of a microcontroller (Arduino Uno), a temperature sensor (LM35), and a digital display (LCD) to create a temperature monitoring and warning system for an automotive application.
