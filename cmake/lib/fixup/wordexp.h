#pragma once
//#include "compat.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#define wordexp compat_wordexp
//#define wordfree compat_wordfree

typedef struct {
    size_t	we_wordc;	/* count of words matched */
    char		**we_wordv;	/* pointer to list of words */
    size_t	we_offs;	/* slots to reserve in we_wordv */
    char		*we_strings;	/* storage for wordv strings */
    size_t	we_nbytes;	/* size of we_strings */
} wordexp_t;

/*
 * Flags for wordexp().
 */
#define	WRDE_APPEND	0x1		/* append to previously generated */
#define	WRDE_DOOFFS	0x2		/* we_offs member is valid */
#define	WRDE_NOCMD	0x4		/* disallow command substitution */
#define	WRDE_REUSE	0x8		/* reuse wordexp_t */
#define	WRDE_SHOWERR	0x10		/* don't redirect stderr to /dev/null */
#define	WRDE_UNDEF	0x20		/* disallow undefined shell vars */

 /*
  * Return values from wordexp().
  */
#define	WRDE_BADCHAR	1		/* unquoted special character */
#define	WRDE_BADVAL	2		/* undefined variable */
#define	WRDE_CMDSUB	3		/* command substitution not allowed */
#define	WRDE_NOSPACE	4		/* no memory for result */
#if __XSI_VISIBLE
#define	WRDE_NOSYS	5		/* obsolete, reserved */
#endif
#define	WRDE_SYNTAX	6		/* shell syntax error */

void wordfree(wordexp_t *pwordexp);
//{
//    free(pwordexp->we_wordv[0]);
//    free(pwordexp->we_wordv);
//}

int wordexp(const char *words, wordexp_t *pwordexp, int flags);
#if 0
{
    //printf("IMPORTANT, compat_wordexp DOESN'T DO MUCH\n");
    char *expanded = NULL;
    const char *home = getenv("HOME");

    if (home && words[0] == '~' && (words[1] == '/' || words[1] == 0)) {
        size_t len = strlen(home) + strlen(words + 1) + 1;
        if ((expanded = (char*)malloc(len)) && !snprintf(expanded, len, "%s%s", home, words + 1)) {
            free(expanded);
            return -1;
        }
    }
    else {
        expanded = strdup(words);
    }

    if (!expanded)
        return -1;

    pwordexp->we_wordv = (char**)calloc(2, sizeof(*pwordexp->we_wordv));
    if (!pwordexp->we_wordv) {
        free(expanded);
        return -1;
    }
    pwordexp->we_wordv[0] = expanded;

    return 0;
}
#endif