#pragma once

using caddr_t = unsigned int;

#define	PROT_READ	0x04	/* pages can be read */
#define	PROT_WRITE	0x02	/* pages can be written */
#define	PROT_EXEC	0x01	/* pages can be executed */

/*
 * Flags contain mapping type, sharing type and options.
 * Mapping type; choose one
 */
#define	MAP_FILE	0x0001	/* mapped from a file or device */
#define	MAP_ANON	0x0002	/* allocated from memory, swap space */
#define	MAP_TYPE	0x000f	/* mask for type field */

 /*
  * Sharing types; choose one
  */    
#define	MAP_COPY	0x0020	/* "copy" region at mmap time */
#define	MAP_SHARED	0x0010	/* share changes */
#define	MAP_PRIVATE	0x0000	/* changes are private */

  /*
   * Other flags
   */
#define	MAP_FIXED	0x0100	/* map addr must be exactly as requested */
#define	MAP_NOEXTEND	0x0200	/* for MAP_FILE, don't change file size */
#define	MAP_HASSEMPHORE	0x0400	/* region may contain semaphores */
#define	MAP_INHERIT	0x0800	/* region is retained after exec */

#define MAP_ANONYMOUS   0x1000 // hack

   /*
    * Advice to madvise
    */
#define	MADV_NORMAL	0	/* no further special treatment */
#define	MADV_RANDOM	1	/* expect random page references */
#define	MADV_SEQUENTIAL	2	/* expect sequential page references */
#define	MADV_WILLNEED	3	/* will need these pages */
#define	MADV_DONTNEED	4	/* dont need these pages */

    /* Flags for msync. */
#define MS_ASYNC        1
#define MS_SYNC         2
#define MS_INVALIDATE   4

#define MAP_FAILED      ((void *)-1)

static caddr_t mmap(caddr_t, size_t, int, int, int, off_t)
{
    printf("mmap\n");
    return 0;
}

static int	munmap(void*, int)
{
    printf("munmap\n");
    return 0;
}

static int	msync(void*, size_t, int flags)
{
    printf("msync\n");
    return 0;
}