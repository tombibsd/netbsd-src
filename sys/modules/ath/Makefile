#	$NetBSD$

.include "../Makefile.inc"

.PATH:	${S}/dev/ic

KMOD=	ath

SRCS=	ath.c \
	ath_netbsd.c \
	athrate-sample.c

CPPFLAGS+=	-DINET

.include "../ath_hal/Makefile.inc"
.include <bsd.kmodule.mk>
