#	$NetBSD$

LD+=			-m elf32_sparc
MLIBDIR=		sparc
LIBC_MACHINE_ARCH=	${MLIBDIR}
COMMON_MACHINE_ARCH=	${MLIBDIR}
KVM_MACHINE_ARCH=	${MLIBDIR}
PTHREAD_MACHINE_ARCH=	${MLIBDIR}
BFD_MACHINE_ARCH=	${MLIBDIR}
CSU_MACHINE_ARCH=	${MLIBDIR}
CRYPTO_MACHINE_CPU=	${MLIBDIR}
LDELFSO_MACHINE_CPU=	${MLIBDIR}
GOMP_MACHINE_ARCH=	${MLIBDIR}
XORG_MACHINE_ARCH=	${MLIBDIR}

.include "${.PARSEDIR}/../../m32.mk"
