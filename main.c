/********************************************************************************
* main.c: Demonstration av inbyggt system innefattande 7-segmentsdisplayer.
*         Timerkrets Timer 1 används för att räkna upp befintligt tal på
*         7-segmentsdisplayerna en gång per sekund.
********************************************************************************/
#include "timer.h"
#include "wdt.h"
#include "display.h"

/********************************************************************************
* setup: Initierar systemet enligt följande:
*
*        1. Initierar Watchdog-timern med en timeout på 1024 ms. System reset
*           aktiveras så att systemåterställning sker ifall Watchdog-timern
*           löper ut.
*
*        2. Initierar 7-segmentsdisplayerna med startvärde 0 och aktiverar
*           uppräkning en gång per sekund.
********************************************************************************/
static inline void setup(void)
{
   wdt_init(WDT_TIMEOUT_1024_MS);
   wdt_enable_interrupt();

   display_init();
   display_enable_output();
   display_enable_count();
   return;
}

/********************************************************************************
* main: Initierar systemet vid start. Uppräkning sker sedan kontinuerligt
*       av talet på 7-segmentsdisplayerna en gång per sekund.
********************************************************************************/
int main(void)
{
   setup();
   
   while (1)
   {
      wdt_reset();
   }

   return 0;
}

