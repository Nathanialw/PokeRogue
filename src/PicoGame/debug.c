#include "hardware/gpio.h"
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/regs/uart.h"

void uart_putc_direct(uint8_t c) {
    uart0_hw->dr = c;
    while (!(uart0_hw->fr & UART_UARTFR_TXFF_BITS));
}

void uart_puts_direct(const char *s) {
    while (*s) uart_putc_direct(*s++);
}

typedef struct {
    uint32_t r0, r1, r2, r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
} exception_frame_t;

#define LED_PIN 25   // built‑in LED on most Pico boards

void hard_fault_handler_c(exception_frame_t *frame) {

    uart_puts_direct("\n*** HARD FAULT ***\n");
    char buf[16];
    sprintf(buf, "PC=%08X\n", frame->pc);
    uart_puts_direct(buf);


    // Toggle LED rapidly to signal we're in the handler
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    for (int i = 0; i < 10; i++) {
        gpio_put(LED_PIN, 1);
        busy_wait_us(100000);
        gpio_put(LED_PIN, 0);
        busy_wait_us(100000);
    }

    // Then your existing printf code...
    while (1) tight_loop_contents();
}

__attribute__((naked))
void isr_hardfault(void) {
    __asm volatile (
        "mov r0, sp\n"
        "b hard_fault_handler_c\n"
    );
}











