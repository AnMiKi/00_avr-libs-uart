#ifndef UART_H
#define UART_H

#include <avr/io.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

// Init the UART
void uart_init(void);

// Send a single byte over uart
void uart_transmit(void);

// Send a null-terminated string over uart
void uard_print(const char *str);

#endif
