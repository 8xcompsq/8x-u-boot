#ifndef _REGS_UART_H_
#define _REGS_UART_H_

struct sprd_uart_regs {
    u32 tx_fifo;    /* 0x00 */
    u32 rx_fifo;    /* 0x04 */
    u32 status;     /* 0x08 */
    u32 ctrl1;      /* 0x0C */
    u32 ctrl2;      /* 0x10 */
    u32 clk_divider;/* 0x14 */
};

#endif
