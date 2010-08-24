/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2003
 * Texas Instruments, <www.ti.com>
 * Kshitij Gupta <Kshitij@ti.com>
 *
 * (C) Copyright 2004
 * ARM Ltd.
 * Philippe Robin, <philippe.robin@arm.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <common.h>
#include <linux-adapter.h>
#include <asm/arch/platform.h>

void peripheral_power_enable (void);

#if defined(CONFIG_SHOW_BOOT_PROGRESS)
void show_boot_progress(int progress)
{
    printf("Boot reached stage %d\n", progress);
}
#endif

#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)

static inline void delay (unsigned long loops)
{
	__asm__ volatile ("1:\n"
		"subs %0, %1, #1\n"
		"bne 1b":"=r" (loops):"0" (loops));
}

/*
* GPIO Initial for Hi3511v100 DMEB
* GPIO configure for different board
	GPIO6_0				SPI			I
	GPIO6_1				SPI			O
	GPIO7_6				SPI			I
	GPIO7_5				SPI			I
	GPIO1_7/GPIO2_0		PCI_REQ/GNT	O
	GPIO0_5/GPIO0_6		UART2		I
	GPIO2_7				UCTSN1		O 
	GPIO2_5/GPIO2_4		UART1		I
	GPIO1_1				EBICS1		O
	GPIO3_4				IIC_CLK		O
	GPIO3_3				IIC_SDA		IO
*/
void gpio_init(void)
{
	unsigned int gpio_ctrl = 0;
	unsigned int reg = 0;
/*
	sys control register gpio
*/
/* HI3511 DEMO BOARD
Offset Address
0x020	Register Name
SC_PERCTRL1	Total Reset Value
[31]	RW	pinmuxctrl31	SIO0����ķ���ָ֡ʾ���ÿ��ơ�0���ӹܽ�SIO0XFS��
[30]	RW	pinmuxctrl30	SIO0����ķ���ʱ�Ӹ��ÿ��ơ�0���ӹܽ�SIO0XCK��
[29:25]	-	reserved	������
[24]	RW	pinmuxctrl24	��̫����˫���ܽ�ERXERR/ECRS/ECOL���ÿ��ơ�0����̫���ӿڹܽš�
[23]	RW	pinmuxctrl23	VI1�ӿں�GPIO���ÿ��ơ�0��VI1�ӿڡ�
[22]	-	reserved	����
[21]	RW	pinmuxctrl21	����EBI�ӿ���Ƭѡ�ź�EBIADR24��GPIO�ĸ��ÿ��ơ�0��EBI�ӿڵĵ�ַ�ߡ�
[20]	RW	pinmuxctrl20	����EBI�ӿ���Ƭѡ�ź�EBICS1N��GPIO�ĸ��ÿ��ơ�0��GPIO1_1��
[19]	RW	pinmuxctrl19	оƬ����ɱ��ʱ�ӹܽ�ACKOUT�ܽţ���������ƵоƬ����ʱ�ӣ����ÿ��ơ�1���ɱ��ʱ�������
[18]	RW	pinmuxctrl18	SIO0��SIO0XFS�ܽź�GPIO�ĹܽŸ��ÿ��ơ�1��SIO0XFS��
[17]	RW	pinmuxctrl17	IRRCV��GPIO�ĹܽŸ��ÿ��ơ�0��IRRCV��
[16]	RW	pinmuxctrl16	UART1�ӿڸ��ÿ��ơ�1��UART1 URXD1/UTXD1/URTSN1/UCTSN1�źš�
[15]	RW	pinmuxctrl15	DDR�������źŵĹܽŸ��ÿ��ơ�1��DDR�������ź�DDRMRCVI��DDRMRCVO��
[14]	RW	pinmuxctrl14	����I2C�źź�GPIO���ÿ��ơ�1��GPIO3_3��GPIO3_4��
[13]	RW	pinmuxctrl13	PCI��PCIREQ4��PCIGRANT4��GPIO���ÿ��ơ�0��GPIO1_7��GPIO2_0��
[12]	RW	pinmuxctrl12	SPI�ӿ���Ƭѡ��������ơ�0��SPICSN0��
[11]	RW	pinmuxctrl11	1��SIO0XCK��
[10]	RW	pinmuxctrl10	GPIO��SPI�ĹܽŸ��ÿ��ơ�0��GPIO6_0��GPIO7_6��GPIO6_1��GPIO7_5��
[9]	RW	pinmuxctrl9	1��MMC��
[8:7]	RW	pinmuxctrl8-7	VI2�ӿڵ�ͬ���źš�GPIO���͸���ģʽ�µ�VI����ĹܽŸ��ÿ��ơ�10: UART��//00��GPIO0_5��GPIO0_6��
[6]	RW	pinmuxctrl6	0��VI3�ӿڡ�
[5]	RW	pinmuxctrl5	1
[4]	RW	pinmuxctrl4	0
[3]	RW	pinmuxctrl3	0
[2]	RW	pinmuxctrl2	0
[1:0]	RW	pinmuxctrl1-0	01
*/
	gpio_ctrl = 0x000DCB21;
 /* 	gpio_ctrl = 0x000DCB01;
	gpio_ctrl &= ~(1 << 0);
	gpio_ctrl &= ~(1 << 9);
	gpio_ctrl &= ~(1 << 10);
	gpio_ctrl &= ~(1 << 11);
	gpio_ctrl &= ~(1 << 14);
	gpio_ctrl |=  (1 << 17);
	gpio_ctrl &= ~(1 << 18);
*/
	gpio_ctrl &= ~(1 << 19);
//	gpio_ctrl |=  (1 << 23);
	

	/*added by  daoguang Wu*/
	__raw_writel(gpio_ctrl, REG_BASE_SCTL + REG_SC_PERCTRL1);
	reg = __raw_readl(REG_BASE_SCTL + REG_SC_PERCTRL3);
	reg = (reg & 0xFF000000) | (0x24000000);
	reg |= ((4096000ULL * (1 << 27)) / (CFG_CLK_BUS * 4));/* K = Fsio * (1 << 27) / (Fpll)   */
	__raw_writel(reg , REG_BASE_SCTL + REG_SC_PERCTRL3);

	reg = __raw_readl(REG_BASE_SCTL + REG_SC_PERCTRL4);
	reg |= 0x80;
	__raw_writel(reg , REG_BASE_SCTL + REG_SC_PERCTRL4);

}

/*
 * Miscellaneous platform dependent initialisations
 */
int board_init (void)
{
	DECLARE_GLOBAL_DATA_PTR;
	unsigned long t;

	gd->bus_clk = CFG_CLK_BUS;
	gd->cpu_clk = CFG_CLK_CPU;

	/* enable timer 0_1 */
	t = __raw_readl(REG_BASE_SCTL) | (1<<16);
	__raw_writel(t, REG_BASE_SCTL);

	gd->bd->bi_arch_number = MACH_TYPE_VERSATILE_PB;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = CFG_BOOT_PARAMS;

	gd->flags = 0;

	icache_enable ();

	__raw_writel(0, CFG_TIMERBASE + REG_TIMER_CONTROL);
	__raw_writel(~0, CFG_TIMERBASE + REG_TIMER_RELOAD);
	__raw_writel(CFG_TIMER_CTRL, CFG_TIMERBASE + REG_TIMER_CONTROL);
	__raw_writel(__raw_readl(REG_BASE_SCTL + REG_SC_CTRL) | (1<<16), REG_BASE_SCTL + REG_SC_CTRL);

	t = __raw_readl(REG_GPIO_DIR+REG_GPIO7_BASE) | (1<<4);
	__raw_writel(t, REG_GPIO_DIR +REG_GPIO7_BASE);

	__raw_writel(0, (1<<6) +REG_GPIO7_BASE);
	/* gpio init */
	gpio_init();

	return 0;
}

void init_eth_mac_env(void);

int misc_init_r (void)
{
#ifdef CONFIG_RANDOM_ETHADDR
	random_init_r();
#endif
	init_eth_mac_env();

	setenv("verify", "n");

	return (0);
}

int dram_init (void)
{
	  DECLARE_GLOBAL_DATA_PTR;

          gd->bd->bi_dram[0].start = CFG_DDR_PHYS_OFFSET;
          gd->bd->bi_dram[0].size = CFG_DDR_SIZE;

	return 0;
}

