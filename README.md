# STM32_NUCLEO_F401RE
STM32IDE code public repository for STM32 NUCLEO_F401RE Board

# [LED Blinking](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/LED%20Blinking)

A simple LED blinking (Onboard LED 2, 500ms)

# [USART Example](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/USART%20Example)

Printing of "Hello World" by means of USART (Baud Rate 115200 Bits/s)

# [USART Example 2](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/USART%20Example%202)
Printing of "Hello World" by means of USART (Baud Rate 115200 Bits/s) using a data buffer

# [USART Example 3](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/USART%20Example%203)
Printing of "Test X" by means of USART (Baud Rate 115200 Bits/s) using a data buffer and a variable (cont), whose value is dinamically updated inside the buffer using the sprintf function

# [USART_DIGITAL_SINE_GENERATOR](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/USART_DIGITAL_SINE_GENERATOR)
Digital sine generation using USART (Baud Rate 115200 Bits/s)

 The output digital data can be viewed using Serial Plot from Arduino IDE or similar tools.

WARNING
The float formatting support is not default enabled, check your MCU Settings from "Project Properties >  C/C++ Build > Settings > Tool Settings" enabling "use float with printf", or add manually "-u _printf_float" in linker flags.
 Click on Device Configuration Tool Update after completion to apply the modification 

# [ADC](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/ADC%20Example)

 ADC conversione from pin AN0
 The digital result of the conversion is saved in the variable *uiAnalogData*.

 The value of *uiAnalogData* is transmitted using USART (Baud Rate 115200 Bits/s).

 The output digital data can be viewed using Serial Plot from Arduino IDE or similar tools.