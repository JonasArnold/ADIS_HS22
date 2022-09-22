#include "application.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

static void delay(void)
{
	uint32_t i;

	for (i = 0; i < 500000; ++i) {
		__asm volatile ("nop");
	}
}

void App_Run(void){
    while(1) {
    	GPIO_PortToggle(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN_MASK);
    	delay();
    }
}
