#	$NetBSD$

DRIVER=		xf86-input-synaptics
DRIVER_NAME=	synaptics_drv

SRCS=		synaptics.c alpscomm.c ps2comm.c properties.c
#SRCS+=		psmcomm.c

CPPFLAGS+=	-I${X11SRCDIR.${DRIVER}}/include
CPPFLAGS+=	-DHAVE_CONFIG_H -I${X11SRCDIR.${DRIVER}}/../include

MAN=		synaptics.4

.include "../Makefile.xf86-driver"
