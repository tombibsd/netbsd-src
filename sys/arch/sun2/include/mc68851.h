/*	$NetBSD$	*/

/*
 * XXX - this is an awful hack that lets libsa/sun3x.h 
 * include arch/sun3/include/pte3x.h, which wants to 
 * include machine/mc68851.h.  NEVER INSTALL THIS FILE.
 * Better solutions gladly accepted.
 */
#include <arch/sun3/include/mc68851.h>
