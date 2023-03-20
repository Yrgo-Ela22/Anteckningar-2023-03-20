/********************************************************************************
* isr.c: Inneh�ller avbrottsrutiner.
********************************************************************************/
#include "display.h"

/********************************************************************************
* ISR (TIMER1_COMPA_vect): Avbrottsrutin som �ger rum vid uppr�kning till 256 av
*                          Timer 1 i CTC Mode, vilket sker var 0.128:e
*                          millisekund n�r timern �r aktiverad. En g�ng per
*                          millisekund togglas talet utskrivet p� 
*                          7-segmentsdisplayerna mellan tiotal och ental.
********************************************************************************/
ISR (TIMER1_COMPA_vect)
{
   display_toggle_digit();
   return;
}

/********************************************************************************
* ISR (TIMER2_OVF_vect): Avbrottsrutin som �ger rum vid uppr�kning till 256 av
*                        Timer 2 i Normal Mode, vilket sker var 0.128:e
*                        millisekund n�r timern �r aktiverad. En g�ng per sekund
*                        inkrementeras talet utskrivet p� 7-segmentsdisplayerna.
********************************************************************************/
ISR (TIMER2_OVF_vect)
{
   display_count();
   return;
}
