#	$NetBSD$

.if ${MACHINE_ARCH} == "mips64eb"
LD+=		-m elf32btsmip
.else
LD+=		-m elf32ltsmip
.endif
.ifndef MLIBDIR
MLIBDIR=	o32

LIBGCC_MACHINE_ARCH=    ${MACHINE_ARCH:S/64//}
GOMP_MACHINE_ARCH=    ${MACHINE_ARCH:S/64//}
XORG_MACHINE_ARCH=    ${MACHINE_ARCH:S/64//}

COPTS+=		-mabi=32 -march=mips3
CPUFLAGS+=	-mabi=32 -march=mips3
LDADD+=		-mabi=32 -march=mips3
LDFLAGS+=	-mabi=32 -march=mips3
MKDEPFLAGS+=	-mabi=32 -march=mips3
.endif

.include "${.PARSEDIR}/../../Makefile.compat"
