/*	$NetBSD$	*/

/*-
 * Copyright (c) 1999-2001
 *         Shin Takemura and PocketBSD Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
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
/*
 *  Do not edit.
 *  This file is automatically generated by platid.awk.
 */
#include <machine/platid.h>
#include <machine/platid_mask.h>
struct platid_name platid_name_table[] = {
#ifdef hpcmips
	{ &platid_mask_CPU_MIPS,
	 TEXT("MIPS") },
	{ &platid_mask_CPU_MIPS_VR,
	 TEXT("MIPS VR") },
	{ &platid_mask_CPU_MIPS_VR_41XX,
	 TEXT("MIPS VR 41XX") },
	{ &platid_mask_CPU_MIPS_VR_4102,
	 TEXT("MIPS VR 4102") },
	{ &platid_mask_CPU_MIPS_VR_4111,
	 TEXT("MIPS VR 4111") },
	{ &platid_mask_CPU_MIPS_VR_4121,
	 TEXT("MIPS VR 4121") },
	{ &platid_mask_CPU_MIPS_VR_4181,
	 TEXT("MIPS VR 4181") },
	{ &platid_mask_CPU_MIPS_VR_4122,
	 TEXT("MIPS VR 4122") },
	{ &platid_mask_CPU_MIPS_VR_4131,
	 TEXT("MIPS VR 4131") },
	{ &platid_mask_CPU_MIPS_VR_4181A,
	 TEXT("MIPS VR 4181A") },
	{ &platid_mask_CPU_MIPS_TX,
	 TEXT("MIPS TX") },
	{ &platid_mask_CPU_MIPS_TX_3900,
	 TEXT("MIPS TX 3900") },
	{ &platid_mask_CPU_MIPS_TX_3911,
	 TEXT("MIPS TX 3911") },
	{ &platid_mask_CPU_MIPS_TX_3912,
	 TEXT("MIPS TX 3912") },
	{ &platid_mask_CPU_MIPS_TX_3920,
	 TEXT("MIPS TX 3920") },
	{ &platid_mask_CPU_MIPS_TX_3922,
	 TEXT("MIPS TX 3922") },
	{ &platid_mask_CPU_MIPS_TX_3927,
	 TEXT("MIPS TX 3927") },
#endif /* hpcmips */
#ifdef hpcsh
	{ &platid_mask_CPU_SH,
	 TEXT("SH") },
	{ &platid_mask_CPU_SH_3,
	 TEXT("SH 3") },
	{ &platid_mask_CPU_SH_3_7709,
	 TEXT("SH 3 7709") },
	{ &platid_mask_CPU_SH_3_7709A,
	 TEXT("SH 3 7709A") },
	{ &platid_mask_CPU_SH_3_7707,
	 TEXT("SH 3 7707") },
	{ &platid_mask_CPU_SH_4,
	 TEXT("SH 4") },
	{ &platid_mask_CPU_SH_4_7750,
	 TEXT("SH 4 7750") },
#endif /* hpcsh */
#ifdef hpcarm
	{ &platid_mask_CPU_ARM,
	 TEXT("ARM") },
	{ &platid_mask_CPU_ARM_STRONGARM,
	 TEXT("ARM STRONGARM") },
	{ &platid_mask_CPU_ARM_STRONGARM_SA1100,
	 TEXT("ARM STRONGARM SA1100") },
	{ &platid_mask_CPU_ARM_STRONGARM_SA1110,
	 TEXT("ARM STRONGARM SA1110") },
	{ &platid_mask_CPU_ARM_XSCALE,
	 TEXT("ARM XSCALE") },
	{ &platid_mask_CPU_ARM_XSCALE_PXA250,
	 TEXT("ARM XSCALE PXA250") },
	{ &platid_mask_CPU_ARM_XSCALE_PXA270,
	 TEXT("ARM XSCALE PXA270") },
#endif /* hpcarm */
#ifdef hpcmips
	{ &platid_mask_MACH_NEC,
	 TEXT("NEC") },
	{ &platid_mask_MACH_NEC_MCCS,
	 TEXT("NEC MC-CS") },
	{ &platid_mask_MACH_NEC_MCCS_1X,
	 TEXT("NEC MC-CS series") },
	{ &platid_mask_MACH_NEC_MCCS_11,
	 TEXT("NEC MC-CS11") },
	{ &platid_mask_MACH_NEC_MCCS_12,
	 TEXT("NEC MC-CS12") },
	{ &platid_mask_MACH_NEC_MCCS_13,
	 TEXT("NEC MC-CS13") },
	{ &platid_mask_MACH_NEC_MCR,
	 TEXT("NEC MC-R") },
	{ &platid_mask_MACH_NEC_MCR_3XX,
	 TEXT("NEC MC-R300 series") },
	{ &platid_mask_MACH_NEC_MCR_300,
	 TEXT("NEC MC-R300") },
	{ &platid_mask_MACH_NEC_MCR_320,
	 TEXT("NEC MC-R320") },
	{ &platid_mask_MACH_NEC_MCR_FORDOCOMO,
	 TEXT("NEC MobileGearII for DoCoMo") },
	{ &platid_mask_MACH_NEC_MCR_MPRO700,
	 TEXT("NEC MobilePro 700") },
	{ &platid_mask_MACH_NEC_MCR_330,
	 TEXT("NEC MC-R330") },
	{ &platid_mask_MACH_NEC_MCR_5XX,
	 TEXT("NEC MC-R500 series") },
	{ &platid_mask_MACH_NEC_MCR_500,
	 TEXT("NEC MC-R500") },
	{ &platid_mask_MACH_NEC_MCR_510,
	 TEXT("NEC MC-R510") },
	{ &platid_mask_MACH_NEC_MCR_520,
	 TEXT("NEC MC-R520") },
	{ &platid_mask_MACH_NEC_MCR_520A,
	 TEXT("NEC MobilePro 770") },
	{ &platid_mask_MACH_NEC_MCR_500A,
	 TEXT("NEC MobilePro 750c") },
	{ &platid_mask_MACH_NEC_MCR_530,
	 TEXT("NEC MC-R530") },
	{ &platid_mask_MACH_NEC_MCR_430,
	 TEXT("NEC MC-R430") },
	{ &platid_mask_MACH_NEC_MCR_530A,
	 TEXT("NEC MobilePro 780") },
	{ &platid_mask_MACH_NEC_MCR_SIGMARION,
	 TEXT("DoCoMo sigmarion") },
	{ &platid_mask_MACH_NEC_MCR_550,
	 TEXT("NEC MC-R550") },
	{ &platid_mask_MACH_NEC_MCR_450,
	 TEXT("NEC MC-R450") },
	{ &platid_mask_MACH_NEC_MCR_SIGMARION2,
	 TEXT("DoCoMo sigmarionII") },
	{ &platid_mask_MACH_NEC_MCR_7XX,
	 TEXT("NEC MC-R700 series") },
	{ &platid_mask_MACH_NEC_MCR_700,
	 TEXT("NEC MC-R700") },
	{ &platid_mask_MACH_NEC_MCR_700A,
	 TEXT("NEC MobilePro 800") },
	{ &platid_mask_MACH_NEC_MCR_730,
	 TEXT("NEC MC-R730") },
	{ &platid_mask_MACH_NEC_MCR_730A,
	 TEXT("NEC MobilePro 880") },
#endif /* hpcmips */
#ifdef hpcmips
	{ &platid_mask_MACH_EVEREX,
	 TEXT("Everex") },
	{ &platid_mask_MACH_EVEREX_FREESTYLE,
	 TEXT("Everex Freestyle") },
	{ &platid_mask_MACH_EVEREX_FREESTYLE_AXX,
	 TEXT("Everex Freestyle AXX") },
	{ &platid_mask_MACH_EVEREX_FREESTYLE_A10,
	 TEXT("Everex Freestyle A10") },
	{ &platid_mask_MACH_EVEREX_FREESTYLE_A15,
	 TEXT("Everex Freestyle A15") },
	{ &platid_mask_MACH_EVEREX_FREESTYLE_A20,
	 TEXT("Everex Freestyle A20") },
#endif /* hpcmips */
	{ &platid_mask_MACH_CASIO,
	 TEXT("CASIO") },
#ifdef hpcmips
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE,
	 TEXT("CASIO Cassiopeia") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_EXX,
	 TEXT("CASIO Cassiopeia EXX") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E10,
	 TEXT("CASIO Cassiopeia E10") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E11,
	 TEXT("CASIO Cassiopeia E11") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E15,
	 TEXT("CASIO Cassiopeia E15") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E55,
	 TEXT("CASIO Cassiopeia E-55") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_FORDOCOMO,
	 TEXT("CASIO Cassiopeia for DoCoMo") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E65,
	 TEXT("CASIO Cassiopeia E-65") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_EXXX,
	 TEXT("CASIO Cassiopeia EXXX") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E100,
	 TEXT("CASIO Cassiopeia E100") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E105,
	 TEXT("CASIO Cassiopeia E105") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E500,
	 TEXT("CASIO Cassiopeia E500") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAE_E507,
	 TEXT("CASIO Cassiopeia E507") },
	{ &platid_mask_MACH_CASIO_POCKETPOSTPET,
	 TEXT("CASIO PocketPostPet") },
	{ &platid_mask_MACH_CASIO_POCKETPOSTPET_POCKETPOSTPET,
	 TEXT("CASIO PocketPostPet") },
#endif /* hpcmips */
#ifdef hpcsh
	{ &platid_mask_MACH_CASIO_CASSIOPEIAA,
	 TEXT("CASIO Cassiopeia") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAA_AXX,
	 TEXT("CASIO Cassiopeia AXX") },
	{ &platid_mask_MACH_CASIO_CASSIOPEIAA_A55V,
	 TEXT("CASIO Cassiopeia A-55V") },
#endif /* hpcsh */
#if defined(hpcmips) || defined(hpcarm)
	{ &platid_mask_MACH_SHARP,
	 TEXT("Sharp") },
#if defined(hpcmips)
	{ &platid_mask_MACH_SHARP_TRIPAD,
	 TEXT("Sharp Tripad") },
	{ &platid_mask_MACH_SHARP_TRIPAD_PV,
	 TEXT("Sharp Tripad PV") },
	{ &platid_mask_MACH_SHARP_TRIPAD_PV6000,
	 TEXT("Sharp Tripad PV6000") },
	{ &platid_mask_MACH_SHARP_TELIOS,
	 TEXT("Sharp Telios") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCAJ,
	 TEXT("Sharp Telios HCAJ") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCAJ1_JP,
	 TEXT("Sharp HC-AJ1 (Japanese)") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCAJ2_JP,
	 TEXT("Sharp HC-AJ2 (Japanese)") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCAJ3_JP,
	 TEXT("Sharp HC-AJ3 (Japanese)") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCVJ,
	 TEXT("Sharp Telios HCVJ") },
	{ &platid_mask_MACH_SHARP_TELIOS_HCVJ1C_JP,
	 TEXT("Sharp HC-VJ1C (Japanese)") },
	{ &platid_mask_MACH_SHARP_MOBILON,
	 TEXT("Sharp Mobilon") },
	{ &platid_mask_MACH_SHARP_MOBILON_HC,
	 TEXT("Sharp Mobilon HC") },
	{ &platid_mask_MACH_SHARP_MOBILON_HC4100,
	 TEXT("Sharp Mobilon HC4100") },
	{ &platid_mask_MACH_SHARP_MOBILON_HC4500,
	 TEXT("Sharp Mobilon HC4500") },
	{ &platid_mask_MACH_SHARP_MOBILON_HC1200,
	 TEXT("Sharp Mobilon HC1200") },
#endif /* hpcmips */
#if defined(hpcarm)
	{ &platid_mask_MACH_SHARP_WZERO3,
	 TEXT("Sharp WZERO3") },
	{ &platid_mask_MACH_SHARP_WZERO3_WS003SH,
	 TEXT("Sharp W-ZERO3 (WS003SH)") },
	{ &platid_mask_MACH_SHARP_WZERO3_WS004SH,
	 TEXT("Sharp W-ZERO3 (WS004SH)") },
	{ &platid_mask_MACH_SHARP_WZERO3_WS007SH,
	 TEXT("Sharp W-ZERO3[es] (WS007SH)") },
	{ &platid_mask_MACH_SHARP_WZERO3_WS011SH,
	 TEXT("Sharp Advanced/W-ZERO3[es] (WS011SH)") },
	{ &platid_mask_MACH_SHARP_WZERO3_WS020SH,
	 TEXT("Sharp WILLCOM 03 (WS020SH)") },
#endif /* hpcarm */
#endif /* hpcmips || hpcarm */
#ifdef hpcmips
	{ &platid_mask_MACH_FUJITSU,
	 TEXT("Fujitsu") },
	{ &platid_mask_MACH_FUJITSU_INTERTOP,
	 TEXT("Fujitsu INTERTOP") },
	{ &platid_mask_MACH_FUJITSU_INTERTOP_ITXXX,
	 TEXT("Fujitsu INTERTOP ITXXX") },
	{ &platid_mask_MACH_FUJITSU_INTERTOP_IT300,
	 TEXT("Fujitsu INTERTOP IT300") },
	{ &platid_mask_MACH_FUJITSU_INTERTOP_IT310,
	 TEXT("Fujitsu INTERTOP IT310") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA,
	 TEXT("Fujitsu PenCentra") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_130,
	 TEXT("Fujitsu PenCentra 130") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_130TM,
	 TEXT("Fujitsu PenCentra 130TM") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_130RF,
	 TEXT("Fujitsu PenCentra 130RF") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_200,
	 TEXT("Fujitsu PenCentra 200") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_200CTM,
	 TEXT("Fujitsu PenCentra 200CTM") },
	{ &platid_mask_MACH_FUJITSU_PENCENTRA_200CRF,
	 TEXT("Fujitsu PenCentra 200CRF") },
#endif /* hpcmips */
#ifdef hpcmips
	{ &platid_mask_MACH_PHILIPS,
	 TEXT("Philips") },
	{ &platid_mask_MACH_PHILIPS_NINO,
	 TEXT("Philips Nino") },
	{ &platid_mask_MACH_PHILIPS_NINO_3XX,
	 TEXT("Philips Nino 3XX") },
	{ &platid_mask_MACH_PHILIPS_NINO_312,
	 TEXT("Philips Nino 312") },
#endif /* hpcmips */
	{ &platid_mask_MACH_COMPAQ,
	 TEXT("Compaq") },
#ifdef hpcmips
	{ &platid_mask_MACH_COMPAQ_C,
	 TEXT("Compaq C") },
	{ &platid_mask_MACH_COMPAQ_C_8XX,
	 TEXT("Compaq C 8XX") },
	{ &platid_mask_MACH_COMPAQ_C_810,
	 TEXT("Compaq C 810") },
	{ &platid_mask_MACH_COMPAQ_C_201X,
	 TEXT("Compaq C 201X") },
	{ &platid_mask_MACH_COMPAQ_C_2010,
	 TEXT("Compaq C 2010") },
	{ &platid_mask_MACH_COMPAQ_C_2015,
	 TEXT("Compaq C 2015") },
	{ &platid_mask_MACH_COMPAQ_AERO,
	 TEXT("Compaq AERO") },
	{ &platid_mask_MACH_COMPAQ_AERO_15XX,
	 TEXT("Compaq AERO 15XX") },
	{ &platid_mask_MACH_COMPAQ_AERO_1530,
	 TEXT("Compaq AERO 1530") },
	{ &platid_mask_MACH_COMPAQ_AERO_21XX,
	 TEXT("Compaq AERO 21XX") },
	{ &platid_mask_MACH_COMPAQ_AERO_2110,
	 TEXT("Compaq AERO 2110") },
	{ &platid_mask_MACH_COMPAQ_AERO_2130,
	 TEXT("Compaq AERO 2130") },
	{ &platid_mask_MACH_COMPAQ_AERO_2140,
	 TEXT("Compaq AERO 2140") },
	{ &platid_mask_MACH_COMPAQ_PRESARIO,
	 TEXT("Compaq PRESARIO") },
	{ &platid_mask_MACH_COMPAQ_PRESARIO_21X,
	 TEXT("Compaq PRESARIO 21X") },
	{ &platid_mask_MACH_COMPAQ_PRESARIO_213,
	 TEXT("Compaq PRESARIO 213") },
#endif /* hpcmips */
#ifdef hpcarm
	{ &platid_mask_MACH_COMPAQ_IPAQ,
	 TEXT("Compaq iPAQ") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H31XX,
	 TEXT("Compaq iPAQ H31XX") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H3100,
	 TEXT("Compaq iPAQ H3100") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H36XX,
	 TEXT("Compaq iPAQ H36XX") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H3600,
	 TEXT("Compaq iPAQ H3600") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H3660,
	 TEXT("Compaq iPAQ H3660") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H39XX,
	 TEXT("Compaq iPAQ H39XX") },
	{ &platid_mask_MACH_COMPAQ_IPAQ_H3900,
	 TEXT("Compaq iPAQ H3900") },
#endif /* hpcarm */
#ifdef hpcsh
	{ &platid_mask_MACH_COMPAQ_AERO,
	 TEXT("Compaq Aero") },
	{ &platid_mask_MACH_COMPAQ_AERO_8000,
	 TEXT("Compaq Aero 8000") },
#endif /* hpcsh */
#ifdef hpcmips
	{ &platid_mask_MACH_VICTOR,
	 TEXT("Victor") },
	{ &platid_mask_MACH_VICTOR_INTERLINK,
	 TEXT("Victor InterLink") },
	{ &platid_mask_MACH_VICTOR_INTERLINK_MP,
	 TEXT("Victor InterLink MP") },
	{ &platid_mask_MACH_VICTOR_INTERLINK_MPC101,
	 TEXT("Victor InterLink MPC101") },
	{ &platid_mask_MACH_VICTOR_INTERLINK_MPC303,
	 TEXT("Victor InterLink MPC303") },
	{ &platid_mask_MACH_VICTOR_INTERLINK_MPC304,
	 TEXT("Victor InterLink MPC304") },
#endif /* hpcmips */
#ifdef hpcmips
	{ &platid_mask_MACH_IBM,
	 TEXT("IBM") },
	{ &platid_mask_MACH_IBM_WORKPAD,
	 TEXT("IBM WorkPad") },
	{ &platid_mask_MACH_IBM_WORKPAD_Z50,
	 TEXT("IBM WorkPad z50") },
	{ &platid_mask_MACH_IBM_WORKPAD_26011AU,
	 TEXT("IBM WorkPad z50 2601 1AU") },
#endif /* hpcmips */
#ifdef hpcmips
	{ &platid_mask_MACH_VADEM,
	 TEXT("VADEM") },
	{ &platid_mask_MACH_VADEM_CLIO,
	 TEXT("VADEM CLIO") },
	{ &platid_mask_MACH_VADEM_CLIO_C,
	 TEXT("VADEM CLIO C") },
	{ &platid_mask_MACH_VADEM_CLIO_C1000,
	 TEXT("VADEM CLIO C-1000") },
	{ &platid_mask_MACH_VADEM_CLIO_C1050,
	 TEXT("VADEM CLIO C-1050") },
#endif /* hpcmips */
	{ &platid_mask_MACH_HP,
	 TEXT("HP") },
#ifdef hpcsh
	{ &platid_mask_MACH_HP_LX,
	 TEXT("HP LX") },
	{ &platid_mask_MACH_HP_LX_620,
	 TEXT("HP 620LX") },
	{ &platid_mask_MACH_HP_LX_620JP,
	 TEXT("HP 620LX (Japanese)") },
	{ &platid_mask_MACH_HP_LX_360,
	 TEXT("HP 360LX (Ericsson MC-16)") },
#endif /* hpcsh */
	{ &platid_mask_MACH_HP_JORNADA,
	 TEXT("HP Jornada") },
#ifdef hpcsh
	{ &platid_mask_MACH_HP_JORNADA_6XX,
	 TEXT("HP Jornada 6XX") },
	{ &platid_mask_MACH_HP_JORNADA_680,
	 TEXT("HP Jornada 680 (US/UK)") },
	{ &platid_mask_MACH_HP_JORNADA_680JP,
	 TEXT("HP Jornada 680 (Japanese)") },
	{ &platid_mask_MACH_HP_JORNADA_680EU,
	 TEXT("HP Jornada 680 (European)") },
	{ &platid_mask_MACH_HP_JORNADA_680DE,
	 TEXT("HP Jornada 680 (German)") },
	{ &platid_mask_MACH_HP_JORNADA_690,
	 TEXT("HP Jornada 690 (US/UK)") },
	{ &platid_mask_MACH_HP_JORNADA_690JP,
	 TEXT("HP Jornada 690 (Japanese)") },
	{ &platid_mask_MACH_HP_JORNADA_690EU,
	 TEXT("HP Jornada 690 (European)") },
	{ &platid_mask_MACH_HP_JORNADA_690DE,
	 TEXT("HP Jornada 690 (German)") },
	{ &platid_mask_MACH_HP_JORNADA_680FR,
	 TEXT("HP Jornada 680 (French)") },
	{ &platid_mask_MACH_HP_JORNADA_690FR,
	 TEXT("HP Jornada 690 (French)") },
	{ &platid_mask_MACH_HP_JORNADA_680SV,
	 TEXT("HP Jornada 680 (Scandinavian)") },
	{ &platid_mask_MACH_HP_JORNADA_690SV,
	 TEXT("HP Jornada 690 (Scandinavian)") },
	{ &platid_mask_MACH_HP_JORNADA_680ES,
	 TEXT("HP Jornada 680 (Spanish)") },
	{ &platid_mask_MACH_HP_JORNADA_690ES,
	 TEXT("HP Jornada 690 (Spanish)") },
#endif /* hpcsh */
#ifdef hpcarm
	{ &platid_mask_MACH_HP_JORNADA_7XX,
	 TEXT("HP Jornada 7XX") },
	{ &platid_mask_MACH_HP_JORNADA_720,
	 TEXT("HP Jornada 720 (US/UK)") },
	{ &platid_mask_MACH_HP_JORNADA_720JP,
	 TEXT("HP Jornada 720 (Japanese)") },
	{ &platid_mask_MACH_HP_JORNADA_720EU,
	 TEXT("HP Jornada 720 (European)") },
	{ &platid_mask_MACH_HP_JORNADA_720DE,
	 TEXT("HP Jornada 720 (German)") },
	{ &platid_mask_MACH_HP_JORNADA_720FR,
	 TEXT("HP Jornada 720 (French)") },
	{ &platid_mask_MACH_HP_JORNADA_720SV,
	 TEXT("HP Jornada 720 (Scandinavian)") },
	{ &platid_mask_MACH_HP_JORNADA_720ES,
	 TEXT("HP Jornada 720 (Spanish)") },
	{ &platid_mask_MACH_HP_JORNADA_8XX,
	 TEXT("HP Jornada 8XX") },
	{ &platid_mask_MACH_HP_JORNADA_820,
	 TEXT("HP Jornada 820") },
	{ &platid_mask_MACH_HP_JORNADA_820JP,
	 TEXT("HP Jornada 820 (Japanese)") },
#endif /* hpcarm */
#ifdef hpcsh
	{ &platid_mask_MACH_HITACHI,
	 TEXT("HITACHI") },
	{ &platid_mask_MACH_HITACHI_PERSONA,
	 TEXT("HITACHI PERSONA") },
	{ &platid_mask_MACH_HITACHI_PERSONA_HPW230JC,
	 TEXT("HITACHI PERSONA HPW230JC") },
	{ &platid_mask_MACH_HITACHI_PERSONA_HPW50PAD,
	 TEXT("HITACHI PERSONA HPW50PAD") },
	{ &platid_mask_MACH_HITACHI_PERSONA_HPW200EC,
	 TEXT("HITACHI PERSONA HPW200EC") },
	{ &platid_mask_MACH_HITACHI_PERSONA_HPW650PA,
	 TEXT("HITACHI PERSONA HPW650PA") },
#endif /* hpcsh */
#ifdef hpcsh
	{ &platid_mask_MACH_LGE,
	 TEXT("LGE") },
	{ &platid_mask_MACH_LGE_PHENOM,
	 TEXT("LGE Phenom") },
	{ &platid_mask_MACH_LGE_PHENOM_H220C,
	 TEXT("LGE H-220C") },
#endif /* hpcsh */
#ifdef hpcmips
	{ &platid_mask_MACH_LASER5,
	 TEXT("LASER5") },
	{ &platid_mask_MACH_LASER5_L,
	 TEXT("LASER5 L-") },
	{ &platid_mask_MACH_LASER5_L_CARD,
	 TEXT("LASER5 L-CARD+") },
	{ &platid_mask_MACH_LASER5_L_BOARD,
	 TEXT("LASER5 L-BOARD") },
#endif /* hpcmips */
#ifdef hpcmips
	{ &platid_mask_MACH_AGENDA,
	 TEXT("AGENDA") },
	{ &platid_mask_MACH_AGENDA_VR,
	 TEXT("AGENDA VR") },
	{ &platid_mask_MACH_AGENDA_VR_VR3,
	 TEXT("AGENDA VR3+") },
#endif /* hpcmips */
#ifdef hpcarm
	{ &platid_mask_MACH_PSIONTEKLOGIX,
	 TEXT("PSIONTEKLOGIX") },
	{ &platid_mask_MACH_PSIONTEKLOGIX_NETBOOK,
	 TEXT("PSIONTEKLOGIX NETBOOK") },
	{ &platid_mask_MACH_PSIONTEKLOGIX_NETBOOK_PRO,
	 TEXT("PSIONTEKLOGIX NETBOOK PRO") },
#endif /* hpcarm */
};
int platid_name_table_size = sizeof(platid_name_table)/sizeof(*platid_name_table);
