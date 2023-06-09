#include "em_device.h"
#include "em_chip.h"
#include <stdio.h>
#include "em_usart.h"
#include "em_cmu.h"
#include "retargetserial.h"
#include "em_system.h"
#include "em_gpio.h"
#include "em_core.h"
#include "motor_vezerles.h"




int main(void)
{
	USART_InitAsync_TypeDef UART1_init = USART_INITASYNC_DEFAULT;
  /* Chip errata */
  CHIP_Init();

//  CMU ->HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;

  //orajel (ado-vevo, nem kommunikacio
  //  CMU_ClockEnable(CMU_Clock_TypeDef clock, bool enable);
    CMU_ClockEnable(cmuClock_GPIO, true);
    CMU_ClockEnable(cmuClock_USART1, true);

  //lab engedelezesek es minden 0-ba allitasa
    //USART_Tx
  GPIO_PinModeSet(gpioPortD, 0, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortD, 0);
    //USART_Rx
  GPIO_PinModeSet(gpioPortD, 1, gpioModeInput,1);
   GPIO_PinOutClear(gpioPortD, 1);
    //IN1
  GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortC, 0);
    //EN1
  GPIO_PinModeSet(gpioPortC, 3, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortC, 3);
  	//IN2
  GPIO_PinModeSet(gpioPortC, 4, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortC, 4);
  	//EN2
  GPIO_PinModeSet(gpioPortC, 5, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortC, 5);
    //IN3
  GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortD, 2);
    //EN3
  GPIO_PinModeSet(gpioPortD, 3, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortD, 3);
    //IN4
  GPIO_PinModeSet(gpioPortD, 4, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortD, 4);
    //EN4
  GPIO_PinModeSet(gpioPortD, 5, gpioModePushPull,1);
  GPIO_PinOutClear(gpioPortD, 5);


  //UART felkonfiguralasa
	UART1_init.baudrate = 19200;
	UART1_init.databits = usartDatabits8;
	UART1_init.parity = usartNoParity;
	UART1_init.stopbits = usartStopbits1;

  //USART konfiguralasa
  //USART_InitAsync(USART_TypeDef *usart, const USART_InitAsync_TypeDef *init)
	USART_InitAsync(USART1, &UART1_init);

  USART1 -> ROUTE |= USART_ROUTE_LOCATION_LOC1;
  USART1 -> ROUTE |= USART_ROUTE_RXPEN;
  USART1 -> ROUTE |= USART_ROUTE_TXPEN;
  USART_Enable(USART1,usartEnable);

  /* Infinite loop */
  uint8_t	pre = 0;
  uint8_t	m1 = 0;
  uint8_t	m2 = 0;


  while (1) {
	  pre = USART_Rx(USART1);//ezzel ellenorizzuk, hogy mik jottek
	  if(pre == 0x00){
		  pre = USART_Rx(USART1);
		  if(pre == 0x55){
			  pre = USART_Rx(USART1);
			  if(pre == 0x8b){
				  m1 = USART_Rx(USART1);
				  	  if(m1 == 0x02){//M1 motor jobbra forog
				  		  setOut1();
				  		  clearOut2();
				  		  disableOut3();
				  	  }
				  	  if(m1 == 0x01){//M1 motor balra forog
				  		  clearOut1();
				  		  setOut2();
				  		  disableOut3();
				  	  }
				  	  if(m1 == 0x00){//M1 motor nem forog
				  		disableOut1();
				  	  }
				  m2 = USART_Rx(USART1);
					  if(m2 == 0x01){//M2 motor jobbra forog
						  setOut2();
						  clearOut3();
						  disableOut1();
					  }
					  if(m2 == 0x02){//M2 motor balra forog
						  clearOut2();
						  setOut3();
						  disableOut1();
					  }
					  if(m2 == 0x00){//M2 motor nem forog
						  disableOut3();
					  }
			  	  }
		  	  }
	  }
  }
}



