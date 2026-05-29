 Hardware Pin Mapping (Tiva C Layout)
Ensure your connections account for the Tiva C's 3.3V GPIO boundaries:

* HC-05 Bluetooth Module
* TX Pin: Connect to Tiva C Pin PB0 (RX)
   * RX Pin: Connect to Tiva C Pin PB1 (TX)
   * VCC / GND: Connect to Tiva C 5V / GND pins [4] 
* L298N Motor Driver Module
* IN1 & IN2: Connect to Tiva C Pins PD0 & PD1 (Left Motor logic)
   * IN3 & IN4: Connect to Tiva C Pins PD2 & PD3 (Right Motor logic)
   * ENA & ENB: Connect to Tiva C Pins PB6 & PB7 (PWM hardware pins for speed control)
   * GND Terminal: Link to battery Negative (-) terminal AND Tiva C GND pin [1, 5, 6] 

