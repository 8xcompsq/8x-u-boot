#include <config.h>
#include <cpu_func.h>
#include <init.h>
#include <asm/armv7.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <linux/types.h>
#include <stdio.h>

/* Satisfies the linker for reset calls */
void reset_cpu(void)
{
    while (1); 
}

/* Satisfies CONFIG_DISPLAY_CPUINFO */
int print_cpuinfo(void)
{
    printf("CPU:   Spreadtrum SC8830\n");
    return 0;
}

/* arch_cpu_init is called early in the boot sequence */
int arch_cpu_init(void)
{
    icache_enable();
    return 0;
}
