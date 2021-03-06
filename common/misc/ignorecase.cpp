/*
 * This file is part of the DXX-Rebirth project <http://www.dxx-rebirth.com/>.
 * It is copyright by its individual contributors, as recorded in the
 * project's Git history.  See COPYING.txt at the top level for license
 * terms and a link to the Git history.
 */
/** \file ignorecase.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "physfsx.h"
#include "ignorecase.h"

/**
 * Please see ignorecase.h for details.
 *
 * License: this code is public domain. I make no warranty that it is useful,
 *  correct, harmless, or environmentally safe.
 *
 * This particular file may be used however you like, including copying it
 *  verbatim into a closed-source project, exploiting it commercially, and
 *  removing any trace of my name from the source (although I hope you won't
 *  do that). I welcome enhancements and corrections to this file, but I do
 *  not require you to send me patches if you make changes. This code has
 *  NO WARRANTY.
 *
 * Unless otherwise stated, the rest of PhysicsFS falls under the zlib license.
 *  Please see LICENSE in the root of the source tree.
 *
 *  \author Ryan C. Gordon.
 */

/* I'm not screwing around with stricmp vs. strcasecmp... */
static int caseInsensitiveStringCompare(const char *x, const char *y)
{
    int ux, uy;
    do
    {
        ux = toupper((int) *x);
        uy = toupper((int) *y);
        if (ux != uy)
            return((ux > uy) ? 1 : -1);
        x++;
        y++;
    } while ((ux) && (uy));

    return(0);
} /* caseInsensitiveStringCompare */


static int locateOneElement(char *buf)
{
    char *ptr;
    char **rc;
    char **i;

    if (PHYSFSX_exists(buf,0))
        return(1);  /* quick rejection: exists in current case. */

    ptr = strrchr(buf, '/');  /* find entry at end of path. */
    if (ptr == NULL)
    {
        rc = PHYSFS_enumerateFiles("/");
        ptr = buf;
    } /* if */
    else
    {
        *ptr = '\0';
        rc = PHYSFS_enumerateFiles(buf);
        *ptr = '/';
        ptr++;  /* point past dirsep to entry itself. */
    } /* else */

    for (i = rc; *i != NULL; i++)
    {
        if (caseInsensitiveStringCompare(*i, ptr) == 0)
        {
            strcpy(ptr, *i); /* found a match. Overwrite with this case. */
            PHYSFS_freeList(rc);
            return(1);
        } /* if */
    } /* for */

    /* no match at all... */
    PHYSFS_freeList(rc);
    return(0);
} /* locateOneElement */


int PHYSFSEXT_locateCorrectCase(char *buf)
{
    int rc;
    char *ptr;
    char *prevptr;

    while (*buf == '/')  /* skip any '/' at start of string... */
        buf++;

    ptr = prevptr = buf;
    if (*ptr == '\0')
        return(0);  /* Uh...I guess that's success. */

    while ((ptr = strchr(ptr + 1, '/')))
    {
        *ptr = '\0';  /* block this path section off */
        rc = locateOneElement(buf);
        *ptr = '/'; /* restore path separator */
        if (!rc)
            return(-2);  /* missing element in path. */
    } /* while */

    /* check final element... */
    return(locateOneElement(buf) ? 0 : -1);
} /* PHYSFSEXT_locateCorrectCase */


#ifdef TEST_PHYSFSEXT_LOCATECORRECTCASE
int main(int argc, char **argv)
{
    int rc;
    char buf[128];
    PHYSFS_file *f;

    if (!PHYSFS_init(argv[0]))
    {
        con_printf(CON_CRITICAL, "PHYSFS_init(): %s", PHYSFS_getLastError());
        return(1);
    } /* if */

    if (!PHYSFS_addToSearchPath(".", 1))
    {
        con_printf(CON_CRITICAL, "PHYSFS_addToSearchPath(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    if (!PHYSFS_setWriteDir("."))
    {
        con_printf(CON_CRITICAL, "PHYSFS_setWriteDir(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    if (!PHYSFS_mkdir("/a/b/c"))
    {
        con_printf(CON_CRITICAL, "PHYSFS_mkdir(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    if (!PHYSFS_mkdir("/a/b/C"))
    {
        con_printf(CON_CRITICAL, "PHYSFS_mkdir(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    f = PHYSFS_openWrite("/a/b/c/x.txt");
    PHYSFS_close(f);
    if (f == NULL)
    {
        con_printf(CON_CRITICAL, "PHYSFS_openWrite(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    f = PHYSFS_openWrite("/a/b/C/X.txt");
    PHYSFS_close(f);
    if (f == NULL)
    {
        con_printf(CON_CRITICAL, "PHYSFS_openWrite(): %s", PHYSFS_getLastError());
        PHYSFS_deinit();
        return(1);
    } /* if */

    strcpy(buf, "/a/b/c/x.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != 0) || (strcmp(buf, "/a/b/c/x.txt") != 0))
        con_printf(CON_DEBUG,"test 1 failed");

    strcpy(buf, "/a/B/c/x.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != 0) || (strcmp(buf, "/a/b/c/x.txt") != 0))
        con_printf(CON_DEBUG,"test 2 failed");

    strcpy(buf, "/a/b/C/x.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != 0) || (strcmp(buf, "/a/b/C/X.txt") != 0))
        con_printf(CON_DEBUG,"test 3 failed");

    strcpy(buf, "/a/b/c/X.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != 0) || (strcmp(buf, "/a/b/c/x.txt") != 0))
        con_printf(CON_DEBUG,"test 4 failed");

    strcpy(buf, "/a/b/c/z.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != -1) || (strcmp(buf, "/a/b/c/z.txt") != 0))
        con_printf(CON_DEBUG,"test 5 failed");

    strcpy(buf, "/A/B/Z/z.txt");
    rc = PHYSFSEXT_locateCorrectCase(buf);
    if ((rc != -2) || (strcmp(buf, "/a/b/Z/z.txt") != 0))
        con_printf(CON_DEBUG,"test 6 failed");

    con_printf(CON_DEBUG,"Testing completed.");
    con_printf(CON_DEBUG,"  If no errors were reported, you're good to go.");

    PHYSFS_delete("/a/b/c/x.txt");
    PHYSFS_delete("/a/b/C/X.txt");
    PHYSFS_delete("/a/b/c");
    PHYSFS_delete("/a/b/C");
    PHYSFS_delete("/a/b");
    PHYSFS_delete("/a");
    PHYSFS_deinit();
    return(0);
} /* main */
#endif

/* end of ignorecase.c ... */

