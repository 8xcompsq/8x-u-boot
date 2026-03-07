#define CONFIG_SYS_SDRAM_BASE       0x80000000
#define CONFIG_SYS_INIT_SP_ADDR     (CONFIG_SYS_SDRAM_BASE + 0x1000000)
#define CONFIG_LOADADDR             0x82000000
#define CONFIG_ENV_IS_IN_MMC        1

/* Define the boot command to look for a script on the SD card */
#define CONFIG_BOOTCOMMAND \
	"mmc dev 0; " \
	"if mmc rescan; then " \
		"fatload mmc 0:1 ${loadaddr} boot.scr; " \
		"source ${loadaddr}; " \
	"fi;"
