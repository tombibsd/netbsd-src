/*	$NetBSD$	*/
#ifndef _EVBSH3_DISKLABEL_H_
#define _EVBSH3_DISKLABEL_H_

#define LABELUSESMBR	1
#if HAVE_NBTOOL_CONFIG_H
#include <nbinclude/sh3/disklabel.h>
#else
#include <sh3/disklabel.h>
#endif /* HAVE_NBTOOL_CONFIG_H */

#endif /* _EVBSH3_DISKLABEL_H_ */
