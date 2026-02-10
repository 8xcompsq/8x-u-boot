#ifndef __CONFIG_H
#define __CONFIG_H

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
