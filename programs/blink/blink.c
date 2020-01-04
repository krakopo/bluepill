#include "stm32f1xx.h"

void spin_delay()
{
	const int SPIN_DELAY = 500000;
	volatile int i = 0;
	for (i = 0; i < SPIN_DELAY; i++);
}

void led_init()
{
	/* Enable the clock */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	/* Reset PC13 (LED PIN) */
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);

	/* Set MODE for PC13 to 0b11: Output @ 50 MHz */
	GPIOC->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0);
}

void led_on()
{
	/*
	 * Reset bit for PC13 to turn LED on (active low)
	 *
	 * BSRR = Bit Set Reset Register
	 */
	GPIOC->BSRR = GPIO_BSRR_BR13;
}

void led_off()
{
	/* Set bit for PC13 to turn LED off (active low) */
	GPIOC->BSRR = GPIO_BSRR_BS13;
}

int main() 
{
	led_init();

	while (1)
	{
		led_on();

		spin_delay();

		led_off();

		spin_delay();
	}

	return 0;
}
