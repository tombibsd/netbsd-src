#	$NetBSD$

DRIVER=		xf86-video-intel-old
DRIVER_NAME=	tfp410_drv


SRCS=		tfp410_module.c tfp410.c

CPPFLAGS+=      -I${DESTDIR}${X11INCDIR}/X11
CPPFLAGS+=      -I${DESTDIR}${X11INCDIR}/X11/dri

.include "../../Makefile.xf86-driver"
.PATH: ${X11SRCDIR.${DRIVER}}/src/tfp410
