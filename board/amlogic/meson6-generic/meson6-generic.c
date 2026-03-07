#include <common.h>
#include <asm/arch/io.h>

int board_init(void) {
    /* Basic Amlogic board init - usually just returns 0 for now */
    return 0;
}

int dram_init(void) {
    /* We define the 256MB RAM size here */
    gd->ram_size = 256 * 1024 * 1024; 
    return 0;
}
