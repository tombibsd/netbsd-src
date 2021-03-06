/*	$NetBSD$	*/

/*
 * Copyright (c) 1985, Stichting Centrum voor Wiskunde en Informatica,
 * Amsterdam
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the Stichting Centrum voor Wiskunde en
 * Informatica, nor the names of its contributors may be used to endorse or
 * promote products derived from this software without specific prior
 * written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright (c) 1982 Jay Fenlason <hack@gnu.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
__RCSID("$NetBSD$");
#endif				/* not lint */

#include <stdlib.h>
#include <unistd.h>
#include "hack.h"
#include "extern.h"
#include "def.mkroom.h"

#ifndef NOWORM
#include	"def.wseg.h"
#endif				/* NOWORM */

boolean         level_exists[MAXLEVEL + 1];

static void savegoldchn(int, struct gold *);
static void savetrapchn(int, struct trap *);

void
savelev(int fd, xchar lev)
{
#ifndef NOWORM
	struct wseg    *wtmp, *wtmp2;
	int tmp;
#endif	/* NOWORM */

	if (fd < 0)
		panic("Save on bad file!");	/* impossible */
	if (lev >= 0 && lev <= MAXLEVEL)
		level_exists[lev] = TRUE;

	bwrite(fd, &hackpid, sizeof(hackpid));
	bwrite(fd, &lev, sizeof(lev));
	bwrite(fd, levl, sizeof(levl));
	bwrite(fd, &moves, sizeof(long));
	bwrite(fd, &xupstair, sizeof(xupstair));
	bwrite(fd, &yupstair, sizeof(yupstair));
	bwrite(fd, &xdnstair, sizeof(xdnstair));
	bwrite(fd, &ydnstair, sizeof(ydnstair));
	savemonchn(fd, fmon);
	savegoldchn(fd, fgold);
	savetrapchn(fd, ftrap);
	saveobjchn(fd, fobj);
	saveobjchn(fd, billobjs);
	billobjs = 0;
	save_engravings(fd);
#ifndef QUEST
	bwrite(fd, rooms, sizeof(rooms));
	bwrite(fd, doors, sizeof(doors));
#endif	/* QUEST */
	fgold = 0;
	ftrap = 0;
	fmon = 0;
	fobj = 0;
#ifndef NOWORM
	bwrite(fd, wsegs, sizeof(wsegs));
	for (tmp = 1; tmp < 32; tmp++) {
		for (wtmp = wsegs[tmp]; wtmp; wtmp = wtmp2) {
			wtmp2 = wtmp->nseg;
			bwrite(fd, wtmp, sizeof(struct wseg));
		}
		wsegs[tmp] = 0;
	}
	bwrite(fd, wgrowtime, sizeof(wgrowtime));
#endif	/* NOWORM */
}

void
bwrite(int fd, const void *loc, size_t num)
{
	/* lint wants the 3rd arg of write to be an int; lint -p an unsigned */
	if ((size_t)write(fd, loc, num) != num)
		panic("cannot write %zu bytes to file #%d", num, fd);
}

void
saveobjchn(int fd, struct obj *otmp)
{
	struct obj     *otmp2;
	unsigned        xl;
	int             minusone = -1;

	while (otmp) {
		otmp2 = otmp->nobj;
		xl = otmp->onamelth;
		bwrite(fd, &xl, sizeof(int));
		bwrite(fd, otmp, xl + sizeof(struct obj));
		free(otmp);
		otmp = otmp2;
	}
	bwrite(fd, &minusone, sizeof(int));
}

void
savemonchn(int fd, struct monst *mtmp)
{
	struct monst   *mtmp2;
	unsigned        xl;
	int             minusone = -1;
	const struct permonst *monbegin = &mons[0];

	bwrite(fd, &monbegin, sizeof(monbegin));

	while (mtmp) {
		mtmp2 = mtmp->nmon;
		xl = mtmp->mxlth + mtmp->mnamelth;
		bwrite(fd, &xl, sizeof(int));
		bwrite(fd, mtmp, xl + sizeof(struct monst));
		if (mtmp->minvent)
			saveobjchn(fd, mtmp->minvent);
		free(mtmp);
		mtmp = mtmp2;
	}
	bwrite(fd, &minusone, sizeof(int));
}

static void
savegoldchn(int fd, struct gold *gold)
{
	struct gold    *gold2;
	while (gold) {
		gold2 = gold->ngold;
		bwrite(fd, gold, sizeof(struct gold));
		free(gold);
		gold = gold2;
	}
	bwrite(fd, nul, sizeof(struct gold));
}

static void
savetrapchn(int fd, struct trap *trap)
{
	struct trap    *trap2;
	while (trap) {
		trap2 = trap->ntrap;
		bwrite(fd, trap, sizeof(struct trap));
		free(trap);
		trap = trap2;
	}
	bwrite(fd, nul, sizeof(struct trap));
}

void
getlev(int fd, int pid, xchar lev)
{
	struct gold    *gold;
	struct trap    *trap;
#ifndef NOWORM
	struct wseg    *wtmp;
#endif	/* NOWORM */
	int		tmp;
	long            omoves;
	int             hpid;
	xchar           dlvl;

	/* First some sanity checks */
	mread(fd, &hpid, sizeof(hpid));
	mread(fd, &dlvl, sizeof(dlvl));
	if ((pid && pid != hpid) || (lev && dlvl != lev)) {
		pline("Strange, this map is not as I remember it.");
		pline("Somebody is trying some trickery here ...");
		pline("This game is void ...");
		done("tricked");
	}
	fgold = 0;
	ftrap = 0;
	mread(fd, levl, sizeof(levl));
	mread(fd, &omoves, sizeof(omoves));
	mread(fd, &xupstair, sizeof(xupstair));
	mread(fd, &yupstair, sizeof(yupstair));
	mread(fd, &xdnstair, sizeof(xdnstair));
	mread(fd, &ydnstair, sizeof(ydnstair));

	fmon = restmonchn(fd);

	/* regenerate animals while on another level */
	{
		long            tmoves = (moves > omoves) ? moves - omoves : 0;
		struct monst   *mtmp, *mtmp2;

		for (mtmp = fmon; mtmp; mtmp = mtmp2) {
			long            newhp;	/* tmoves may be very large */

			mtmp2 = mtmp->nmon;
			if (strchr(genocided, mtmp->data->mlet)) {
				mondead(mtmp);
				continue;
			}
			if (mtmp->mtame && tmoves > 250) {
				mtmp->mtame = 0;
				mtmp->mpeaceful = 0;
			}
			newhp = mtmp->mhp +
				(strchr(MREGEN, mtmp->data->mlet) ? tmoves : tmoves / 20);
			if (newhp > mtmp->mhpmax)
				mtmp->mhp = mtmp->mhpmax;
			else
				mtmp->mhp = newhp;
		}
	}

	setgd();
	gold = newgold();
	mread(fd, gold, sizeof(struct gold));
	while (gold->gx) {
		gold->ngold = fgold;
		fgold = gold;
		gold = newgold();
		mread(fd, gold, sizeof(struct gold));
	}
	free(gold);
	trap = newtrap();
	mread(fd, trap, sizeof(struct trap));
	while (trap->tx) {
		trap->ntrap = ftrap;
		ftrap = trap;
		trap = newtrap();
		mread(fd, trap, sizeof(struct trap));
	}
	free(trap);
	fobj = restobjchn(fd);
	billobjs = restobjchn(fd);
	rest_engravings(fd);
#ifndef QUEST
	mread(fd, rooms, sizeof(rooms));
	mread(fd, doors, sizeof(doors));
#endif	/* QUEST */
#ifndef NOWORM
	mread(fd, wsegs, sizeof(wsegs));
	for (tmp = 1; tmp < 32; tmp++)
		if (wsegs[tmp]) {
			wheads[tmp] = wsegs[tmp] = wtmp = newseg();
			while (1) {
				mread(fd, wtmp, sizeof(struct wseg));
				if (!wtmp->nseg)
					break;
				wheads[tmp]->nseg = wtmp = newseg();
				wheads[tmp] = wtmp;
			}
		}
	mread(fd, wgrowtime, sizeof(wgrowtime));
#endif	/* NOWORM */
}

void
mread(int fd, void *buf, size_t len)
{
	ssize_t rlen;

	rlen = read(fd, buf, len);
	if (rlen < 0 || (size_t)rlen != len) {
		pline("Read %zd instead of %zu bytes.\n", rlen, len);
		if (restoring) {
			(void) unlink(SAVEF);
			error("Error restoring old game.");
		}
		panic("Error reading level file.");
	}
}

void
mklev(void)
{
	if (getbones())
		return;

	in_mklev = TRUE;
	makelevel();
	in_mklev = FALSE;
}
