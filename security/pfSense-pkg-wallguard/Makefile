PORTNAME=               pfSense-pkg-wallguard
DISTVERSIONPREFIX=      v
DISTVERSION=            0.1.2
PORTREVISION=           1
CATEGORIES=             security

MAINTAINER=             support@nullnet.ai
COMMENT=                WallGuard pfSense package
WWW=                    https://github.com/NullNet-ai/wallguard

LICENSE=                MIT

USES=                   cargo
USE_GITHUB=             yes
GH_ACCOUNT=             NullNet-ai
GH_PROJECT=             wallguard

SUB_FILES=              pkg-install pkg-deinstall
SUB_LIST=               PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/pkg
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}/etc/inc/priv
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/wallguard.inc ${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/wallguard.xml ${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}/etc/inc/priv/wallguard.priv.inc ${STAGEDIR}/etc/inc/priv
	${INSTALL_DATA} ${FILESDIR}${DATADIR}/info.xml ${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' -e "s|%%PKGVERSION%%|${PKGVERSION}|" \
		${STAGEDIR}${DATADIR}/info.xml \
		${STAGEDIR}${PREFIX}/pkg/wallguard.xml
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/wallguard ${STAGEDIR}${PREFIX}/bin/
	
.include <bsd.port.mk>
