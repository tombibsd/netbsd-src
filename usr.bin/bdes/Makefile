#	$NetBSD$
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

USE_FORT?=	yes	# cryptographic software

PROG=	bdes

LDADD+=	-lcrypt
DPADD+=	${LIBCRYPT}

.include <bsd.prog.mk>
