# $NetBSD$

PRIMARY_PROG=	bootxx_ffs
CPPFLAGS+=	-DLIBSA_SINGLE_FILESYSTEM=ffsv1 \
		-DBOOTXX_FS_NAME='"FFSv1"'
# Use small daddr_t to avoid code bloat
CPPFLAGS+=	-D__daddr_t=int32_t

PRIMARY_MAX_LOAD!=	expr 8192 - 512

.include "../Makefile.booters"
