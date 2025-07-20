#include "uart.h"

void uart_init(void){
    UBBR0H = (MYUBRR >> 8);
    UBBR0L = MYUBRR;
    UCSR0B = (1 << TXEN0);  // Enable TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  // 8-bit data, 1 stop, no parity
}

void uart_transmit(char data){
    while (!(UCSR0A & (1 << UDRE0)));  // Wait for buffer to be empty
    UDR0 = data;
}

void uart_print(const char *str) {
    while (*str) {
        uart_transmit(*str++);
    }
}