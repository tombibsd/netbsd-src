/*	$NetBSD$	*/

/*
 * Copyright (C) 2012 by Darren Reed.
 *
 * See the IPFILTER.LICENCE file for details on licencing.
 *
 * Id: alist_free.c,v 1.1.1.2 2012/07/22 13:44:38 darrenr Exp $
 */
#include "ipf.h"

void
alist_free(hosts)
	alist_t *hosts;
{
	alist_t *a, *next;

	for (a = hosts; a != NULL; a = next) {
		next = a->al_next;
		free(a);
	}
}
