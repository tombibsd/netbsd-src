# $NetBSD$

.include <bsd.init.mk>

.PATH:	${SRCDIR}/doc

.for name in kyua.conf.5 kyuafile.5
MAN+=	${name}
${name}: ${name}.in ${MANPAGE_DEPS}
	name=${name}; ${BUILD_MANPAGE}
.endfor

.include <bsd.man.mk>
