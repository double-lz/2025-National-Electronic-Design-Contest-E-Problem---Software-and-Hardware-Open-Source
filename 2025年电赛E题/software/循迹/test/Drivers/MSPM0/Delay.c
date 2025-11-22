#include  "Delay.h"

void Delay_us(unsigned long us) 
{
    while(us--)
    {
		delay_cycles(CPUCLK_FREQ/1000000);
	}
}

void Delay_ms(uint32_t ms)
{
	 while(ms--)
	 {
		 delay_cycles(CPUCLK_FREQ/1000);
	 }
}