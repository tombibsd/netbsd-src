# $NetBSD$

PROG = netboot

SRCS = start.S boot.c prom.c prom_disp.S OSFpal.c prom_swpal.S
SRCS+= rpcc.S
SRCS+= dev_net.c conf.c devopen.c
SRCS+= if_prom.c getsecs.c booted_dev.c

BOOT_RELOC = ${UNIFIED_LOAD_ADDRESS}

CLEANFILES+= ${PROG}.sym

CPPFLAGS += ${UNIFIED_CPPFLAGS} -DSUPPORT_DHCP \
		-DBOOT_TYPE_NAME='"Network"'

${PROG}: ${PROG}.sym
	${_MKTARGET_CREATE}
	@${OBJCOPY} --output-target=binary ${PROG}.sym ${PROG}
	@chmod 644 ${PROG}
	@ls -l ${PROG}
	@${CHECKSIZE_CMD} ${PROG}.sym ${PROG} ${UNIFIED_MAX_LOAD} \
	    ${UNIFIED_MAX_TOTAL} || (rm -f ${PROG} ; false)

SAMISCMAKEFLAGS= SA_INCLUDE_NET=yes SA_USE_CREAD=yes
.include "../Makefile.bootprogs"

${PROG}.sym: ${OBJS} ${LIBSA} ${LIBZ} ${LIBKERN}
	${_MKTARGET_LINK}
	${LD} -Ttext ${BOOT_RELOC} -N -e start -o ${PROG}.sym \
	    ${OBJS} ${LIBSA} ${LIBZ} ${LIBSA} ${LIBKERN}
	${SIZE} ${PROG}.sym

release: check_RELEASEDIR .WAIT ${PROG}
	${HOST_INSTALL_FILE} -m ${NONBINMODE} ${PROG} \
	    ${RELEASEDIR}/${MACHINE}/installation/netboot
