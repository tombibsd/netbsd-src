#	$NetBSD$

NOMAN=
MAKEDOC=
.include <bsd.init.mk>

HOSTPROG=	makedoc
SRCS=		makedoc.c xexit.c xmalloc.c xstrdup.c

.PATH: ${IDIST}/info ${IDIST}/lib
HOST_CPPFLAGS+= -I${IDIST}/info -I${IDIST}/lib -I${.CURDIR}/../include
HOST_CPPFLAGS+= -DHOSTTOOL

.include <bsd.hostprog.mk>
