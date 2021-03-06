/*	$NetBSD$	*/

/*-
 * Copyright (c) 2013 NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_NBTOOL_CONFIG_H
#include "nbtool_config.h"
#endif

#if !HAVE_DPRINTF
#include <stdlib.h>
#ifndef HAVE_NBTOOL_CONFIG_H
/* These headers are required, but included from nbtool_config.h */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#endif

int
dprintf(int fd, const char *fmt, ...)
{
	FILE *fp;
	int e;
	va_list ap;

	if ((e = dup(fd)) == -1)
		return -1;

	if ((fp = fdopen(e, "r+")) == NULL) {
		(void)close(e);
		return -1;
	}

	va_start(ap, fmt);
	e = vfprintf(fp, fmt, ap);
	va_end(ap);

	(void)fclose(fp);
	return e;
}

#endif	/* HAVE_DPRINTF */

#ifdef TEST
int
main(int argc, char *argv[])
{
	dprintf(1, "Hello %s\n", "world");
	return 0;
}
#endif
