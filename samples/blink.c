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

	/* Configure PC13 */
    GPIOC->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0);
}

void led_on()
{
	GPIOC->BSRR = GPIO_BSRR_BR13;
}

void led_off()
{
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
