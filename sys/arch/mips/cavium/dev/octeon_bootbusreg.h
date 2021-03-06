/*	$NetBSD$	*/

/*
 * Copyright (c) 2007 Internet Initiative Japan, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Boot-Bus Registers
 */

#ifndef _OCTEON_BOOTBUSREG_H_
#define _OCTEON_BOOTBUSREG_H_

/* ---- register addresses */

#define	MIO_BOOT_REG_CFG0			0x0001180000000000ULL
#define	MIO_BOOT_REG_CFG1			0x0001180000000008ULL
#define	MIO_BOOT_REG_CFG2			0x0001180000000010ULL
#define	MIO_BOOT_REG_CFG3			0x0001180000000018ULL
#define	MIO_BOOT_REG_CFG4			0x0001180000000020ULL
#define	MIO_BOOT_REG_CFG5			0x0001180000000028ULL
#define	MIO_BOOT_REG_CFG6			0x0001180000000030ULL
#define	MIO_BOOT_REG_CFG7			0x0001180000000038ULL
#define	MIO_BOOT_REG_TIM0			0x0001180000000040ULL
#define	MIO_BOOT_REG_TIM1			0x0001180000000048ULL
#define	MIO_BOOT_REG_TIM2			0x0001180000000050ULL
#define	MIO_BOOT_REG_TIM3			0x0001180000000058ULL
#define	MIO_BOOT_REG_TIM4			0x0001180000000060ULL
#define	MIO_BOOT_REG_TIM5			0x0001180000000068ULL
#define	MIO_BOOT_REG_TIM6			0x0001180000000070ULL
#define	MIO_BOOT_REG_TIM7			0x0001180000000078ULL
#define	MIO_BOOT_LOC_CFG0			0x0001180000000080ULL
#define	MIO_BOOT_LOC_CFG1			0x0001180000000088ULL
#define	MIO_BOOT_LOC_ADR			0x0001180000000090ULL
#define	MIO_BOOT_LOC_DAT			0x0001180000000098ULL
#define	MIO_BOOT_ERR				0x00011800000000a0ULL
#define	MIO_BOOT_INT				0x00011800000000a8ULL
#define	MIO_BOOT_THR				0x00011800000000b0ULL
#define	MIO_BOOT_BIST_STAT			0x00011800000000f8ULL

/* ---- register bits */

#define	MIO_BOOT_REG_CFGN_XXX_63_37		UINT64_C(0xffffffe000000000)
#define	MIO_BOOT_REG_CFGN_SAM			UINT64_C(0x0000001000000000)
#define	MIO_BOOT_REG_CFGN_WE_EXT		UINT64_C(0x0000000c00000000)
#define	MIO_BOOT_REG_CFGN_OE_EXT		UINT64_C(0x0000000300000000)
#define	MIO_BOOT_REG_CFGN_EN			UINT64_C(0x0000000080000000)
#define	MIO_BOOT_REG_CFGN_OR			UINT64_C(0x0000000040000000)
#define	MIO_BOOT_REG_CFGN_ALE			UINT64_C(0x0000000020000000)
#define	MIO_BOOT_REG_CFGN_WIDTH			UINT64_C(0x0000000010000000)
#define	MIO_BOOT_REG_CFGN_SIZE			UINT64_C(0x000000000fff0000)
#define	MIO_BOOT_REG_CFGN_BASE			UINT64_C(0x000000000000ffff)

#define	MIO_BOOT_REG_TIMN_PAGEM			UINT64_C(0x8000000000000000)
#define	MIO_BOOT_REG_TIMN_WAITM			UINT64_C(0x4000000000000000)
#define	MIO_BOOT_REG_TIMN_PAGES			UINT64_C(0x3000000000000000)
#define	MIO_BOOT_REG_TIMN_ALE			UINT64_C(0x0fc0000000000000)
#define	MIO_BOOT_REG_TIMN_PAGE			UINT64_C(0x003f000000000000)
#define	MIO_BOOT_REG_TIMN_WAIT			UINT64_C(0x0000fc0000000000)
#define	MIO_BOOT_REG_TIMN_PAUSE			UINT64_C(0x000003f000000000)
#define	MIO_BOOT_REG_TIMN_WR_HLD		UINT64_C(0x0000000fc0000000)
#define	MIO_BOOT_REG_TIMN_RD_HLD		UINT64_C(0x000000003f000000)
#define	MIO_BOOT_REG_TIMN_WE			UINT64_C(0x0000000000fc0000)
#define	MIO_BOOT_REG_TIMN_OE			UINT64_C(0x000000000003f000)
#define	MIO_BOOT_REG_TIMN_CE			UINT64_C(0x0000000000000fc0)
#define	MIO_BOOT_REG_TIMN_ADR			UINT64_C(0x000000000000003f)

#define	MIO_BOOT_LOC_CFGN_XXX_63_32		UINT64_C(0xffffffff00000000)
#define	MIO_BOOT_LOC_CFGN_EN			UINT64_C(0x0000000080000000)
#define	MIO_BOOT_LOC_CFGN_XXX_30_28		UINT64_C(0x0000000070000000)
#define	MIO_BOOT_LOC_CFGN_BASE			UINT64_C(0x000000000ffffff8)
#define	MIO_BOOT_LOC_CFGN_XXX_2_0		UINT64_C(0x0000000000000007)

#define	MIO_BOOT_LOC_ADR_XXX_63_8		UINT64_C(0xffffffffffffff00)
#define	MIO_BOOT_LOC_ADR_ADR			UINT64_C(0x00000000000000f8)
#define	MIO_BOOT_LOC_ADR_XXX_2_0		UINT64_C(0x0000000000000007)

#define	MIO_BOOT_ERR_XXX_63_2			UINT64_C(0xfffffffffffffffc)
#define	MIO_BOOT_ERR_WAIT_ERR			UINT64_C(0x0000000000000002)
#define	MIO_BOOT_ERR_ADR_ERR			UINT64_C(0x0000000000000001)

#define	MIO_BOOT_INT_XXX_63_2			UINT64_C(0xfffffffffffffffc)
#define	MIO_BOOT_INT_WAIT_INT			UINT64_C(0x0000000000000002)
#define	MIO_BOOT_INT_ADR_INT			UINT64_C(0x0000000000000001)

#define	MIO_BOOT_THR_XXX_63_14			UINT64_C(0xffffffffffffc000)
#define	MIO_BOOT_THR_FIF_CNT			UINT64_C(0x0000000000003f00)
#define	MIO_BOOT_THR_XXX_7_6			UINT64_C(0x00000000000000c0)
#define	MIO_BOOT_THR_FIF_THR			UINT64_C(0x000000000000003f)

#define	MIO_BOOT_BIST_STAT_XXX_63_4		UINT64_C(0xfffffffffffffff0)
#define	MIO_BOOT_BIST_STAT_NCBO_1		UINT64_C(0x0000000000000008)
#define	MIO_BOOT_BIST_STAT_NCBO_0		UINT64_C(0x0000000000000004)
#define	MIO_BOOT_BIST_STAT_LOC			UINT64_C(0x0000000000000002)
#define	MIO_BOOT_BIST_STAT_NCBI			UINT64_C(0x0000000000000001)

/* ---- snprintb */

#define	MIO_BOOT_REG_CFGN_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x24"		"SAM\0" \
	"f\x22\x02"	"WE_EXT\0" \
	"f\x20\x02"	"OE_EXT\0" \
	"b\x1f"		"EN\0" \
	"b\x1e"		"OR\0" \
	"b\x1d"		"ALE\0" \
	"b\x1c"		"WIDTH\0" \
	"f\x10\x0c"	"SIZE\0" \
	"f\x00\x10"	"BASE\0"
#define	MIO_BOOT_REG_CFG0_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG1_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG2_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG3_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG4_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG5_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG6_BITS			MIO_BOOT_REG_CFGN_BITS
#define	MIO_BOOT_REG_CFG7_BITS			MIO_BOOT_REG_CFGN_BITS

#define	MIO_BOOT_REG_TIMN_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x3f"		"PAGEM\0" \
	"b\x3e"		"WAITM\0" \
	"f\x3c\x02"	"PAGES\0" \
	"f\x36\x06"	"ALE\0" \
	"f\x30\x06"	"PAGE\0" \
	"f\x2a\x06"	"WAIT\0" \
	"f\x24\x06"	"PAUSE\0" \
	"f\x1e\x06"	"WR_HLD\0" \
	"f\x18\x06"	"RD_HLD\0" \
	"f\x12\x06"	"WE\0" \
	"f\x0c\x06"	"OE\0" \
	"f\x06\x06"	"CE\0" \
	"f\x00\x06"	"ADR\0"
#define	MIO_BOOT_REG_TIM0_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM1_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM2_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM3_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM4_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM5_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM6_BITS			MIO_BOOT_REG_TIMN_BITS
#define	MIO_BOOT_REG_TIM7_BITS			MIO_BOOT_REG_TIMN_BITS

#define	MIO_BOOT_LOC_CFGN_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x1f"		"EN\0" \
	"f\x03\x19"	"BASE\0"
#define	MIO_BOOT_LOC_CFG0_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG1_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG2_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG3_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG4_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG5_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG6_BITS			MIO_BOOT_LOC_CFGN_BITS
#define	MIO_BOOT_LOC_CFG7_BITS			MIO_BOOT_LOC_CFGN_BITS

#define	MIO_BOOT_LOC_ADR_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"f\x03\x05"	"ADR\0"

#define	MIO_BOOT_ERR_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x01"		"WAIT_ERR\0" \
	"b\x00"		"ADR_ERR\0"

#define	MIO_BOOT_INT_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x01"		"WAIT_INT\0" \
	"b\x00"		"ADR_INT\0"

#define	MIO_BOOT_THR_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"f\x08\x06"	"FIF_CNT\0" \
	"f\x00\x06"	"FIF_THR\0"

#define	MIO_BOOT_BIST_STAT_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x03"		"NCBO_1\0" \
	"b\x02"		"NCBO_0\0" \
	"b\x01"		"LOC\0" \
	"b\x00"		"NCBI\0"

/* ---- bus_space */

#define	MIO_BOOT_REG_CFG0_OFFSET		0x0000
#define	MIO_BOOT_REG_CFG1_OFFSET		0x0008
#define	MIO_BOOT_REG_CFG2_OFFSET		0x0010
#define	MIO_BOOT_REG_CFG3_OFFSET		0x0018
#define	MIO_BOOT_REG_CFG4_OFFSET		0x0020
#define	MIO_BOOT_REG_CFG5_OFFSET		0x0028
#define	MIO_BOOT_REG_CFG6_OFFSET		0x0030
#define	MIO_BOOT_REG_CFG7_OFFSET		0x0038
#define	MIO_BOOT_REG_TIM0_OFFSET		0x0040
#define	MIO_BOOT_REG_TIM1_OFFSET		0x0048
#define	MIO_BOOT_REG_TIM2_OFFSET		0x0050
#define	MIO_BOOT_REG_TIM3_OFFSET		0x0058
#define	MIO_BOOT_REG_TIM4_OFFSET		0x0060
#define	MIO_BOOT_REG_TIM5_OFFSET		0x0068
#define	MIO_BOOT_REG_TIM6_OFFSET		0x0070
#define	MIO_BOOT_REG_TIM7_OFFSET		0x0078
#define	MIO_BOOT_LOC_CFG0_OFFSET		0x0080
#define	MIO_BOOT_LOC_CFG1_OFFSET		0x0088
#define	MIO_BOOT_LOC_ADR_OFFSET			0x0090
#define	MIO_BOOT_LOC_DAT_OFFSET			0x0098
#define	MIO_BOOT_ERR_OFFSET			0x00a0
#define	MIO_BOOT_INT_OFFSET			0x00a8
#define	MIO_BOOT_THR_OFFSET			0x00b0
#define	MIO_BOOT_BIST_STAT_OFFSET		0x00f8

#endif /* _OCTEON_BOOTBUSREG_H_ */
