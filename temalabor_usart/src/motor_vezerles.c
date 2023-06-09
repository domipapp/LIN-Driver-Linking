#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_cmu.h"
void setOut1(void){
	  GPIO_PinOutSet(gpioPortC, 0);//IN1
	  GPIO_PinOutSet(gpioPortC, 3);//EN1
}
void clearOut1(void){
	  GPIO_PinOutClear(gpioPortC, 0);//IN1
	  GPIO_PinOutSet(gpioPortC, 3);//EN1
}
void disableOut1(void){
	  GPIO_PinOutClear(gpioPortC, 0);//IN1
	  GPIO_PinOutClear(gpioPortC, 3);//EN1
}



void setOut2(void){
	  GPIO_PinOutSet(gpioPortC, 4);//IN2
	  GPIO_PinOutSet(gpioPortC, 5);//EN2
}
void clearOut2(void){
	  GPIO_PinOutClear(gpioPortC, 4);//IN2
	  GPIO_PinOutSet(gpioPortC, 5);//EN2
}
void disableOut2(void){
	  GPIO_PinOutClear(gpioPortC, 4);//IN2
	  GPIO_PinOutClear(gpioPortC, 5);//EN2
}



void setOut3(void){
	  GPIO_PinOutSet(gpioPortD, 2);//IN3
	  GPIO_PinOutSet(gpioPortD, 3);//EN3
}
void clearOut3(void){
	  GPIO_PinOutClear(gpioPortD, 2);//IN3
	  GPIO_PinOutSet(gpioPortD, 3);//EN3
}
void disableOut3(void){
	  GPIO_PinOutClear(gpioPortD, 2);//IN3
	  GPIO_PinOutClear(gpioPortD, 3);//EN3
}
