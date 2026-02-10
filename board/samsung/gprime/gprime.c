#include <config.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <linux/types.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
    /* Required for some older ARM boot flows */
    gd->bd->bi_boot_params = 0x80000100;
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
