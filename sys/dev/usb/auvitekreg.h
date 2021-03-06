/* $NetBSD$ */

/*-
 * Copyright (c) 2010 Jared D. McNeill <jmcneill@invisible.ca>
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _AUVITEKREG_H
#define _AUVITEKREG_H

#define	AU0828_CMD_REQUEST_IN	0x00
#define	AU0828_CMD_REQUEST_OUT	0x01

#define	AU0828_REG_GPIO1_OUTEN	0x0000
#define	AU0828_REG_GPIO2_OUTEN	0x0001
#define	AU0828_REG_GPIO1_PINDIR	0x0002
#define	AU0828_REG_GPIO2_PINDIR	0x0003

#define	AU0828_REG_SENSOR_CTL	0x0100
#define	AU0828_REG_SENSORVBI_CTL 0x0103

#define	AU0828_REG_HPOS_LO	0x0110
#define	AU0828_REG_HPOS_HI	0x0111
#define	AU0828_REG_VPOS_LO	0x0112
#define	AU0828_REG_VPOS_HI	0x0113
#define	AU0828_REG_HRES_LO	0x0114
#define	AU0828_REG_HRES_HI	0x0115
#define	AU0828_REG_VRES_LO	0x0116
#define	AU0828_REG_VRES_HI	0x0117

#define	AU0828_REG_I2C_TRIGGER	0x0200
#define  AU0828_I2C_TRIGGER_WR		0x01
#define	 AU0828_I2C_TRIGGER_RD		0x20
#define	 AU0828_I2C_TRIGGER_HOLD	0x40
#define	AU0828_REG_I2C_STATUS	0x0201
#define	 AU0828_I2C_STATUS_RD_DONE	0x01
#define	 AU0828_I2C_STATUS_NO_RD_ACK	0x02
#define	 AU0828_I2C_STATUS_WR_DONE	0x04
#define	 AU0828_I2C_STATUS_NO_WR_ACK	0x08
#define	 AU0828_I2C_STATUS_BUSY		0x10
#define	AU0828_REG_I2C_CLKDIV	0x0202
#define	 AU0828_I2C_CLKDIV_250		0x07
#define	 AU0828_I2C_CLKDIV_100		0x14
#define	 AU0828_I2C_CLKDIV_30		0x40
#define	AU0828_REG_I2C_DSTADDR	0x0203
#define	AU0828_REG_I2C_FIFOWR	0x0205
#define	AU0828_REG_I2C_FIFORD	0x0209
#define	AU0828_REG_I2C_MBMODE	0x02ff

#define	AU0828_REG_AUDIOCTL	0x050c

#define	AU0828_REG_POWER_CTL	0x0600
#define	 AU0828_POWER_EN		0x10

#endif /* !_AUVITEKREG_H */
