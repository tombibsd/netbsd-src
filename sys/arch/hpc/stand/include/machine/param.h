/*	$NetBSD$	*/

/* Windows CE architecture */

#define	DEV_BSIZE	512
#define	DEV_BSHIFT	9		/* log2(DEV_BSIZE) */
#define	BLKDEV_IOSIZE	2048
#define	MAXPHYS		(64 * 1024)	/* max raw I/O transfer size */

/* bytes to disk blocks */
#define	btodb(x)	((x) >> DEV_BSHIFT)
