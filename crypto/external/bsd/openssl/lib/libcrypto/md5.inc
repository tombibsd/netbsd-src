#	$NetBSD$
#
#	@(#) Copyright (c) 1995 Simon J. Gerraty
#
#	SRCS extracted from src/crypto/dist/openssl/crypto/md5/Makefile
#

.PATH:	${OPENSSLSRC}/crypto/md5


MD5_SRCS += md5_dgst.c md5_one.c $(MD5_ASM_OBJ)
SRCS += ${MD5_SRCS}

.for cryptosrc in ${MD5_SRCS}
CPPFLAGS.${cryptosrc} = -I${OPENSSLSRC}/crypto/md5 ${MD5CPPFLAGS}
.endfor
