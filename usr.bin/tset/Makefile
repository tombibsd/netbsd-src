#	$NetBSD$
#	@(#)Makefile	8.1 (Berkeley) 6/9/93

PROG=	tset
SRCS=	map.c misc.c set.c term.c tset.c

DPADD=	${LIBTERMINFO}
LDADD=	-lterminfo
LINKS=	${BINDIR}/tset ${BINDIR}/reset
MLINKS=	tset.1 reset.1

.include <bsd.prog.mk>
