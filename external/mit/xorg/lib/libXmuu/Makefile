#	$NetBSD$

.include <bsd.own.mk>

LIB=	Xmuu
.PATH:	${X11SRCDIR.Xmu}/src

SRCS=	ClientWin.c CursorName.c DefErrMsg.c GetHost.c Lower.c

CPPFLAGS+=-DHAS_SNPRINTF

LIBDPLIBS=\
	Xt	${.CURDIR}/../libXt \
	SM	${.CURDIR}/../libSM \
	ICE	${.CURDIR}/../libICE \
	Xext	${.CURDIR}/../libXext \
	X11	${.CURDIR}/../libX11/dynamic

.include <bsd.x11.mk>
.include <bsd.lib.mk>
