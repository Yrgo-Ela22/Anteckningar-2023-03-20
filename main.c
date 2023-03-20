/********************************************************************************
* main.c: Demonstration av inbyggt system innefattande 7-segmentsdisplayer.
*         Timerkrets Timer 1 anv�nds f�r att r�kna upp befintligt tal p�
*         7-segmentsdisplayerna en g�ng per sekund.
********************************************************************************/
#include "timer.h"
#include "wdt.h"
#include "display.h"

/********************************************************************************
* setup: Initierar systemet enligt f�ljande:
*
*        1. Initierar Watchdog-timern med en timeout p� 1024 ms. System reset
*           aktiveras s� att system�terst�llning sker ifall Watchdog-timern
*           l�per ut.
*
*        2. Initierar 7-segmentsdisplayerna med startv�rde 0 och aktiverar
*           uppr�kning en g�ng per sekund.
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
* main: Initierar systemet vid start. Uppr�kning sker sedan kontinuerligt
*       av talet p� 7-segmentsdisplayerna en g�ng per sekund.
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

