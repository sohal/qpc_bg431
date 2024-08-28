#include <stdbool.h>
#include "main.h"
#include "SEGGER_RTT.h"
#include "stm32f0xx_hal.h"

static void _Delay(int period) {
  int i = 100000*period;
  do { ; } while (i--);
}

uint32_t addOneToByte(const uint32_t byte)
{
    return(byte + 1);
}

void SystemInit(void)
{
    SEGGER_RTT_Init();
    SEGGER_RTT_WriteString(0, "Hello World from Segger!\n");
}
int main (void)
{
    uint32_t i = 0U;
    SystemInit();
    do{
        addOneToByte(i);
        SEGGER_RTT_printf(0, "%sCounter: %s%d\n", RTT_CTRL_BG_BRIGHT_WHITE, RTT_CTRL_BG_BRIGHT_GREEN, i);
       // HAL_Delay(500);
       _Delay(100);
    }while(true);
    return 0;
}