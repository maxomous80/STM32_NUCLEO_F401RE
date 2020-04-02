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

The Timer callback is reported hereafter, and actually fires the printing of "Timer Interrupt 2" by means of USART (Baud Rate 115200 Bits/s) and the toggle of the onboard LED 2.
```
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim2) //Callback for Timer 2 interrupt
{
	HAL_UART_Transmit(&huart2, "Timer 2 Interrupt\n\r", 21, 1000);
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}
```
# [Time counting](https://github.com/maxomous80/STM32_NUCLEO_F401RE/tree/master/Time%Counting)

A state machine provide an implementation of the time counting between two pressure of the User Button, and the value is printed by means of USART (Baud Rate 115200 Bits/s).

First User Button pressure -> Start
Second User Button pressure -> Stop

Timer 2: 10 s

The settings of the timer are:

*Prescaler: 39999*

*Counter Period: 20999*


*Attention: Timer 2 interrupt fires immediately, the bit flag clear is required*
`__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE); //clear of the interrupt flag that fires immediately`



In main.c

```
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim2) //Callback for Timer 2 interrupt
{
	if (state==0)
		__HAL_TIM_CLEAR_IT(htim2, TIM_IT_UPDATE);
	else
	{
		HAL_TIM_Base_Stop(&htim2);
		HAL_UART_Transmit(&huart2, "Timer 2 Reset\n\r", 15, 1000);
		state=0; // state machine configuration
	}


}
```

In stm32f4xx_it.c
```
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
	if (state==0)
	{
	HAL_TIM_Base_Start_IT(&htim2);	//timer start on first button pressing
	__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE); //clear of the interrupt flag that fires immediately
	__HAL_TIM_SetCounter(&htim2, 0); // set of the counter value to 0
	HAL_UART_Transmit(&huart2, "Timer 2 Start\n\r", 15, 1000);
	state=1; // state machine configuration
	}
	else
		{
		HAL_TIM_Base_Stop_IT(&htim2); //timer start on second button pressing
		time2=__HAL_TIM_GET_COUNTER(&htim2); // reading of the timer value
		state=0; // state machine configuration
		HAL_UART_Transmit(&huart2, "Timer 2 Stop\n\r", 15, 1000);
		uint8_t buffertx[50]="";
		sprintf(buffertx, "Time: %lu ms\n\r", (time2*476/1000)); //476 is obtained multipliyng Prescaler value (39999) for CLK period (1/84000000)
		HAL_UART_Transmit(&huart2, buffertx, sizeof(buffertx), 1000);
		}

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}
```

This project provides example of usage of *extern* variables between different project files, and of timers, interrupt and user button.

The time value is obtained multipliyng the counter value for the resolution (Prescaler value (39999) for the CLK period (1/84000000)) and is expressed in ms.