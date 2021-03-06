/*
 * (C) Copyright 2016 Nexell
 * Hyunseok, Jung <hsjung@nexell.co.kr>
 *
 * SPDX-License-Identifier:      GPL-2.0+
 */

#include <config.h>
#include <common.h>
#include <asm/io.h>

#include <asm/arch/nexell.h>
#include <asm/arch/nx_gpio.h>

#ifdef CONFIG_DM_PMIC_NXE2000
#include <dm.h>
#include <dm/uclass-internal.h>
#include <power/pmic.h>
#include <power/nxe2000.h>
#endif

#ifdef CONFIG_DM_REGULATOR_NXE2000
#include <power/regulator.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_PWM_NX
enum gpio_group {
	gpio_a,	gpio_b, gpio_c, gpio_d, gpio_e,
};

struct pwm_device {
	int grp;
	int bit;
	int io_fn;
};

static struct pwm_device pwm_dev[] = {
	[0] = { .grp = gpio_d, .bit = 1,  .io_fn = 0 },
	[1] = { .grp = gpio_c, .bit = 13, .io_fn = 1 },
	[2] = { .grp = gpio_c, .bit = 14, .io_fn = 1 },
	[3] = { .grp = gpio_d, .bit = 0,  .io_fn = 0 },
};
#endif

static void board_backlight_disable(void)
{
#ifdef CONFIG_PWM_NX
	int gp = pwm_dev[CONFIG_BACKLIGHT_CH].grp;
	int io = pwm_dev[CONFIG_BACKLIGHT_CH].bit;
	int fn = pwm_dev[CONFIG_BACKLIGHT_CH].io_fn;

	/*
	 * pwm backlight OFF: HIGH, ON: LOW
	 */
	nx_gpio_set_pad_function(gp, io, fn);
	nx_gpio_set_output_value(gp, io, 0);
	nx_gpio_set_output_enable(gp, io, 1);
#endif
}

static void board_backlight_enable(void)
{
#ifdef CONFIG_PWM_NX
	/*
	 * pwm backlight ON: HIGH, ON: LOW
	 */
	pwm_init(
		CONFIG_BACKLIGHT_CH,
		CONFIG_BACKLIGHT_DIV, CONFIG_BACKLIGHT_INV
		);
	pwm_config(
		CONFIG_BACKLIGHT_CH,
		TO_DUTY_NS(CONFIG_BACKLIGHT_DUTY, CONFIG_BACKLIGHT_HZ),
		TO_PERIOD_NS(CONFIG_BACKLIGHT_HZ)
		);
#endif
}

static void board_gpio_ctl(int gp, int io, int fn, int on, u32 mode)
{
	nx_gpio_set_pad_function(gp, io, fn);

	if (on)
		nx_gpio_set_output_value(gp, io, 1);
	else
		nx_gpio_set_output_value(gp, io, 0);

	nx_gpio_set_pull_mode(gp, io, mode);
	nx_gpio_set_output_enable(gp, io, 1);
}

int board_init(void)
{
	board_backlight_disable();

#ifdef CONFIG_SILENT_CONSOLE
	gd->flags |= GD_FLG_SILENT;
#endif

	return 0;
}

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
#ifdef CONFIG_SILENT_CONSOLE
	gd->flags &= ~GD_FLG_SILENT;
#endif

	/* Not used : gpio, output, low*/
	board_gpio_ctl(gpio_b,  2, 0, 0, nx_gpio_pull_down);
	board_gpio_ctl(gpio_b,  4, 0, 0, nx_gpio_pull_down);
	board_gpio_ctl(gpio_b,  8, 0, 0, nx_gpio_pull_down);
	board_gpio_ctl(gpio_b, 10, 0, 0, nx_gpio_pull_down);

	/* U74 I2C : gpio, output, high */
	board_gpio_ctl(gpio_b, 28, 2, 1, nx_gpio_pull_off);
	board_gpio_ctl(gpio_b, 29, 2, 1, nx_gpio_pull_off);

	/* HDMI I2C : gpio, output, high */
	board_gpio_ctl(gpio_c,  0, 1, 1, nx_gpio_pull_off);
	board_gpio_ctl(gpio_c,  1, 1, 1, nx_gpio_pull_off);

	/* HDMI CEC : gpio, output, high */
	board_gpio_ctl(gpio_c,  3, 1, 1, nx_gpio_pull_off);

	/* Not used : gpio, output, low */
	board_gpio_ctl(gpio_c,  9, 1, 0, nx_gpio_pull_down);
	board_gpio_ctl(gpio_c, 10, 1, 0, nx_gpio_pull_down);

	/* BT EN High:On */
	board_gpio_ctl(gpio_c, 11, 1, 1, nx_gpio_pull_off);

	/* WIFI EN High:On */
	board_gpio_ctl(gpio_c, 12, 1, 1, nx_gpio_pull_off);

	/* Not used : gpio, output, low */
	board_gpio_ctl(gpio_c, 25, 1, 0, nx_gpio_pull_down);

	/* DIV_TP I2C : gpio, output, high */
	board_gpio_ctl(gpio_c, 29, 0, 1, nx_gpio_pull_off);
	board_gpio_ctl(gpio_c, 30, 0, 1, nx_gpio_pull_off);

	/* USB_OTG_POW_CTL : output, high */
	board_gpio_ctl(gpio_d,  0, 0, 1, nx_gpio_pull_off);

	/* DIV_TP_RST : gpio, output, high */
	board_gpio_ctl(gpio_d, 11, 0, 1, nx_gpio_pull_off);

	/* SD2_PWREN Low:On*/
	board_gpio_ctl(gpio_e, 7, 0, 0, nx_gpio_pull_off);

	/* SD1_PWREN Low:On*/
	board_gpio_ctl(gpio_e, 13, 0, 0, nx_gpio_pull_off);

	/* Not used : gpio, output, low */
	board_gpio_ctl(gpio_e, 14, 0, 0, nx_gpio_pull_off);
	board_gpio_ctl(gpio_e, 15, 0, 0, nx_gpio_pull_off);
	board_gpio_ctl(gpio_e, 18, 0, 0, nx_gpio_pull_off);
	board_gpio_ctl(gpio_e, 19, 0, 0, nx_gpio_pull_off);

	/* Alive : gpio, input, pullup */


	board_backlight_enable();

#ifdef CONFIG_RECOVERY_BOOT
#define ALIVE_SCRATCH1_READ_REGISTER	(0xc00108b4)
#define ALIVE_SCRATCH1_RESET_REGISTER	(0xc00108ac)
#define RECOVERY_SIGNATURE				(0x52455343)    /* (ASCII) : R.E.S.C */
	printf("signature --> 0x%x\n", readl(ALIVE_SCRATCH1_READ_REGISTER));
	if (readl(ALIVE_SCRATCH1_READ_REGISTER) == RECOVERY_SIGNATURE) {
		printf("reboot recovery!!!!\n");
		writel(0xffffffff, ALIVE_SCRATCH1_RESET_REGISTER);
		setenv("bootcmd", "run recoveryboot");
	}
#endif

	return 0;
}
#endif

#ifdef CONFIG_SPLASH_SOURCE
#include <splash.h>
struct splash_location splash_locations[] = {
	{
	.name = "mmc_fs",
	.storage = SPLASH_STORAGE_MMC,
	.flags = SPLASH_STORAGE_FS,
	.devpart = "0:1",
	},
	{
	.name = "mmc",
	.storage = SPLASH_STORAGE_MMC,
	.flags = SPLASH_STORAGE_RAW,
	.offset = CONFIG_SPLASH_MMC_OFFSET,
	},
};

int splash_screen_prepare(void)
{
	int err = splash_source_load(splash_locations,
					sizeof(splash_locations)/sizeof(struct splash_location));
	if (!err) {
		char addr[64];

		sprintf(addr, "0x%lx", gd->fb_base);
		setenv("fb_addr", addr);
	}

	return err;
}
#endif

/* u-boot dram initialize  */
int dram_init(void)
{
	gd->ram_size = CONFIG_SYS_SDRAM_SIZE;
	return 0;
}

/* u-boot dram board specific */
void dram_init_banksize(void)
{
	/* set global data memory */
	gd->bd->bi_arch_number = machine_arch_type;
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x00000100;

	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE;
	gd->bd->bi_dram[0].size  = CONFIG_SYS_SDRAM_SIZE;
}

#ifdef CONFIG_DM_PMIC_NXE2000
void power_init_board(void)
{
	struct udevice *pmic;
	struct udevice *dev;
#ifdef CONFIG_DM_REGULATOR
	struct dm_regulator_uclass_platdata *reg_uc_pdata;
	struct udevice *regulator;
#endif
	int ret = -ENODEV;

	ret = pmic_get("nxe2000_gpio@32", &pmic);
	if (ret)
		printf("Can't get PMIC: %s!\n", "nxe2000_gpio@32");

	if (device_has_children(pmic)) {
#ifdef CONFIG_DM_REGULATOR
		for (ret = uclass_find_first_device(UCLASS_REGULATOR, &dev);
			dev;
			ret = uclass_find_next_device(&dev)) {
			if (ret)
				continue;

			reg_uc_pdata = dev_get_uclass_platdata(dev);
			if (!reg_uc_pdata)
				continue;

			uclass_get_device_tail(dev, 0, &regulator);
		}
#endif
	}
}
#endif

