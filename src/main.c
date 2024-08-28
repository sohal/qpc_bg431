#include <stdbool.h>
#include "main.h"

uint8_t addOneToByte(const uint8_t byte)
{
    return(byte + 1);
}

void SystemInit(void)
{

}
int main (void)
{
    SystemInit();
    do{
        addOneToByte(1);
    }while(true);
    return 0;
}