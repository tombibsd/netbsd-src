#	$NetBSD$

LIB=	LLVMAArch64AsmPrinter

.include <bsd.init.mk>

AARCH64_OBJDIR!=	cd ${.CURDIR}/../libLLVMAArch64CodeGen && ${PRINTOBJDIR}
CPPFLAGS+=	-I${AARCH64_OBJDIR} -I${LLVM_SRCDIR}/lib/Target/AArch64

.PATH: ${LLVM_SRCDIR}/lib/Target/AArch64/InstPrinter

SRCS+=	AArch64InstPrinter.cpp

.if defined(HOSTLIB)
.include <bsd.hostlib.mk>
.else
.include <bsd.lib.mk>
.endif
