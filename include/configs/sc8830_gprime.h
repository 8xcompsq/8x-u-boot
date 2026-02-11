#ifndef __CONFIG_H
#define __CONFIG_H

/* Initial Stack Setup */
#define CFG_SYS_INIT_RAM_ADDR        0xf5000000 /* Internal SRAM base */
#define CFG_SYS_INIT_RAM_SIZE        0x4000     /* 16 KB */

/* Real UART Base from DTS */
#define CFG_SC8830_UART0_BASE        0xf5360000

/* GPIO Base from DTS */
#define CFG_SC8830_GPIO_BASE         0xf5220000

/* include/configs/sc8830_gprime.h */
#define CFG_SYS_HZ_CLOCK           26000000
#define CONFIG_SYS_HZ              1000

/* * This puts the early stack at the top of our 64KB window
 * minus the size of the Global Data structure.
 */
#define CFG_SYS_INIT_SP_ADDR \
    (CFG_SYS_INIT_RAM_ADDR + CFG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

/* Architecture and CPU */
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_ARMV7_PSCI_1_0

/* Memory layout */
#define CONFIG_SYS_SDRAM_BASE       0x80000000
#define CONFIG_SYS_INIT_SP_ADDR     (CONFIG_SYS_SDRAM_BASE + 0x100000)
#define CONFIG_SYS_TEXT_BASE        0x80008000 /* Standard Android Kernel Offset */

/* Console Configuration */
#define CONFIG_BAUDRATE             115200
#define CONFIG_SYS_CBSIZE           1024

/* Android Boot Image Support */
#define CONFIG_BOOTCOMMAND          "bootm 0x82000000"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "fdt_high=0xffffffff\0" \
    "initrd_high=0xffffffff\0" \
    "console=ttyS0,115200n8\0"

#endif
