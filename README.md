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

 ADC conversions from pin AN0

 The digital result of the conversion is saved in the variable *uiAnalogData*.

 The value of *uiAnalogData* is transmitted using USART (Baud Rate 115200 Bits/s).

 The output digital data can be viewed using Serial Plot from Arduino IDE or similar tools.

# [User Button](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/User%20Button)

The User LED 2 state follow the User Button state.

When button is pressed LED is on, and vice versa.

Furthermore, every button pressure the string "Pressed" is transmitted using USART (Baud Rate 115200 Bits/s).

Button debounce of 150 ms is used for reducing multiple USART prints.

# [External Interrupt](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/External%20Interrupt)

The User LED 2 state toggle upon the rising edge of the User Button pressure.

Furthermore, every rising edge of the User Button pressure the string "Hello" is transmitted using USART (Baud Rate 115200 Bits/s).

Note that the IRQ_Handler function is located in the file *stm32f4xx_it.c*

The following definition

*extern UART_HandleTypeDef huart2;*

has been added to the file *stm32f4xx_it.c* for visibility purpose.

# [Led Blinking with Timer Interrupt](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Led%20Blink%20with%20Timer%20Interrupt)

The User LED 2 state toggle upon the firing of the interrupt related to Timer 2 (set to 1 s).

The settings of the timer are:

*Prescaler: 9999*

*Counter Period: 8399*

The clock frequency is set to 84 MHz.

The start of the timer is managed using the instruction:

`HAL_TIM_Base_Start_IT(&htim2);`


# [Time counting](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Time%Counting)

A state machine provide an implementation of the time counting between two pressure of the User Button, and the value is printed by means of USART (Baud Rate 115200 Bits/s).

First User Button pressure -> Start

Second User Button pressure -> Stop

Timer 2 update period: 10 s

The settings of the timer are:

*Prescaler: 39999*

*Counter Period: 20999*

This project provides example of usage of *extern* variables between different project files, and of timers, interrupt and user button.

The time value is obtained multipliyng the counter value for the resolution (Prescaler value (39999) for the CLK period (1/84000000)) and is expressed in ms.

# [Sleep Mode](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Sleep_Mode)

Management of Low Power States

The devices support three low-power modes to achieve the best compromise between low power consumption, short startup time and available wakeup sources.
• Sleep mode
In Sleep mode, only the CPU is stopped. All peripherals continue to operate and can
wake up the CPU when an interrupt/event occurs.

# [Stop Mode](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Stop_Mode)

Management of Low Power States

The devices support three low-power modes to achieve the best compromise between low power consumption, short startup time and available wakeup sources.

• Stop mode
The Stop mode achieves the lowest power consumption while retaining the contents of SRAM and registers. All clocks in the 1.2 V domain are stopped, the PLL, the HSI RC and the HSE crystal oscillators are disabled. The voltage regulator can also be put either in normal or in low-power mode.
The device can be woken up from the Stop mode by any of the EXTI line (the EXTI line source can be one of the 16 external lines, the PVD output, the RTC alarm/ wakeup/ tamper/ time stamp events).

# [Standby Mode](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Standby_mode)

Management of Low Power States

The devices support three low-power modes to achieve the best compromise between low power consumption, short startup time and available wakeup sources.

• Standby mode
The Standby mode is used to achieve the lowest power consumption. The internal voltage regulator is switched off so that the entire 1.2 V domain is powered off. The PLL, the HSI RC and the HSE crystal oscillators are also switched off. After entering Standby mode, the SRAM and register contents are lost except for registers in the backup domain when selected.
The device exits the Standby mode when an external reset (NRST pin), an IWDG reset, a rising edge on the WKUP pin, or an RTC alarm/ wakeup/ tamper/time stamp event occurs.
Standby mode is not supported when the embedded voltage regulator is bypassed and the 1.2 V domain is controlled by an external power.

# [Simple Regression Neural Network Model](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Simple_Regression_ML_Model)
