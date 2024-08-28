
#include "cmock.h"
#include "source.h"

void test_addOneToByte_AllOK(void)
{
    volatile uint8_t retVal = 0;
    retVal = addOneToByte((const uint8_t)2);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(3, retVal, "The output is bad");
}

void test_addOneToByte_Overflow(void)
{
    volatile uint8_t retVal = addOneToByte((const uint8_t)255);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(0, retVal, "The output is not overflowing");
}
