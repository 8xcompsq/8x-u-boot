#include <config.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <linux/types.h>

/* * GPIO 214 calculation:
 * Bank = 214 / 32 = 6
 * Bank Offset = 6 * 0x80 = 0x300 (Standard Spreadtrum GPIO layout)
 */
#define GPIO_DAT (0xf5220000 + 0x300) 
#define GPIO_DIR (0xf5220000 + 0x304)
#define PIN_BIT  (1 << (214 % 32))

DECLARE_GLOBAL_DATA_PTR;

#define REG_ADI_BASE          0xf53f8000
#define ADI_ARM_STS0          (REG_ADI_BASE + 0x10)
#define ADI_WDG_CTRL          (REG_ADI_BASE + 0x40) // From your DTS: watchdog@40

void disable_sprd_watchdog(void)
{
    /* * Wait for ADI bus to be ready (bit 31 of STS0 is usually the busy bit)
     * We use a timeout to prevent an infinite loop if the bus is dead.
     */
    int timeout = 1000;
    while ((readl(ADI_ARM_STS0) & (1 << 31)) && timeout--) {
        asm volatile("nop");
    }

    /* * Write 0 to the watchdog control register to disable it.
     * On many SC8830 PMICs, bit 0 is the enable bit.
     */
    writel(0x0, ADI_WDG_CTRL);
}

void error_blink(void) {
    /* Set as output */
    writel(readl(GPIO_DIR) | PIN_BIT, GPIO_DIR);
    
    while (1) {
        writel(readl(GPIO_DAT) | PIN_BIT, GPIO_DAT); // ON
        for(volatile int i=0; i<500000; i++);
        writel(readl(GPIO_DAT) & ~PIN_BIT, GPIO_DAT); // OFF
        for(volatile int i=0; i<500000; i++);
    }
}

int board_init(void)
{
    /* Required for some older ARM boot flows */
    disable_sprd_watchdog();
    error_blink();
    return 0;
}

int dram_init(void)
{
    /* * From your DTS: reg = <0x80000000 0x40000000>
     * We set ram_size to 1GB (0x40000000)
     */
    gd->ram_size = 0x40000000;
    return 0;
}

int dram_init_banksize(void)
{
    gd->bd->bi_dram[0].start = 0x80000000;
    gd->bd->bi_dram[0].size  = 0x40000000;
    return 0;
}
