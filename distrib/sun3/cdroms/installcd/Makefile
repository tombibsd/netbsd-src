#	$NetBSD$
CDBASE=		sun3cd			# gives ${CDBASE}.iso
CDRELEASE=	true			# include $RELEASEDIR/$MACHINE

# for PRINTOBJDIR
.include <bsd.own.mk>

CDBOOTIMAGEDIR!= cd ${NETBSDSRCDIR}/distrib/sun3/miniroot && ${PRINTOBJDIR}
CDBOOTIMAGE=    ${CDBOOTIMAGEDIR}/miniroot.fs
SUN_BOOT_ARGS:= - - - ${CDBOOTIMAGE} ${CDBOOTIMAGE}

image_md_post:
	SUNLABEL=${TOOL_SUNLABEL:Q} \
		${HOST_SH} ${NETBSDSRCDIR}/distrib/common/sunbootcd.sh \
		${CDIMAGE} ${SUN_BOOT_ARGS}
	

.include "${.CURDIR}/../../../common/Makefile.bootcd"
