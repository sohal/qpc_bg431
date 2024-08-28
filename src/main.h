/**
 * @file main.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-18
 * 
 * @copyright Copyright (c) 2023
 * MIT license
 */
#ifndef MAIN_H
#define MAIN_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

/**
 * @brief function to add one to incoming argument
 * Overflows to 0
 * @param byte unsigned byte
 * @return uint8_t byte + 1
 */
uint8_t addOneToByte(const uint8_t byte);

void SystemInit(void);
#ifdef __cplusplus
}
#endif
#endif //MAIN_H
