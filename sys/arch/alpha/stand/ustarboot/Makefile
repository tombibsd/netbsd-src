# $NetBSD$

PROG = ustarboot

SRCS = start.S boot.c blkdev.c prom.c prom_disp.S OSFpal.c
SRCS+= prom_swpal.S booted_dev.c

BOOT_RELOC = ${UNIFIED_LOAD_ADDRESS}

CPPFLAGS += ${UNIFIED_CPPFLAGS} \
		-DBOOT_TYPE_NAME='"ustar"' \
		-DLIBSA_SINGLE_DEVICE=blkdev \
		  -D"blkdevioctl(x,y,z)=EINVAL" \
		-DLIBSA_SINGLE_FILESYSTEM=ustarfs \
		-DNO_LOAD_BACKWARDS

CLEANFILES+= ${PROG}.sym

${PROG}: ${PROG}.sym
	${_MKTARGET_CREATE}
	@${OBJCOPY} --output-target=binary ${PROG}.sym ${PROG}
	@chmod 644 ${PROG}
	@ls -l ${PROG}
	@${CHECKSIZE_CMD} ${PROG}.sym ${PROG} ${UNIFIED_MAX_LOAD} \
	    ${UNIFIED_MAX_TOTAL} || (rm -f ${PROG} ; false)

SAMISCMAKEFLAGS= SA_INCLUDE_NET=no SA_USE_CREAD=yes
.include "../Makefile.bootprogs"

${PROG}.sym: ${OBJS} ${LIBSA} ${LIBZ} ${LIBKERN}
	${_MKTARGET_LINK}
	${LD} -Ttext ${BOOT_RELOC} -N -e start -o ${PROG}.sym \
	    ${OBJS} ${LIBSA} ${LIBZ} ${LIBSA} ${LIBKERN}
	${SIZE} ${PROG}.sym
