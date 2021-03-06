# $NetBSD$

.include <bsd.own.mk>

DIST=		${NETBSDSRCDIR}/external/bsd/elftosb/dist

.PATH:		${DIST}/common

LIBELFTOSBOBJDIR!=	cd ${DIST}/../lib && ${PRINTOBJDIR}

.ifndef HOSTPROG
DPADD+=		${LIBELFTOSBOBJDIR}/libelftosb.a
LDADD+=		-L${LIBELFTOSBOBJDIR} -lelftosb
.endif

CPPFLAGS+=	-I${DIST}/common
CPPFLAGS+=	-I${DIST}/elftosb2
CPPFLAGS+=	-DLinux

CWARNFLAGS+=	-Wno-multichar
CWARNFLAGS.clang+=	-Wno-switch -Wno-error=delete-non-virtual-dtor \
			-Wno-bitwise-op-parentheses -Wno-parentheses \
			-Wno-tautological-compare

LIBISCXX=	yes

BINDIR=		/usr/sbin

