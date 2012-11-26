/* $Id: gamesave.h,v 1.1.1.1 2006/03/17 19:57:20 zicodxx Exp $ */
/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1999 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/

/*
 *
 * Headers for gamesave.c
 *
 */


#ifndef _GAMESAVE_H
#define _GAMESAVE_H

#ifdef __cplusplus

void LoadGame(void);
void SaveGame(void);
int get_level_name(void);

extern int load_level(const char *filename);
extern int save_level(const char *filename);

extern char Gamesave_current_filename[PATH_MAX];

extern int Gamesave_current_version;

extern int Gamesave_num_org_robots;

// In dumpmine.c
extern void write_game_text_file(const char *filename);

extern int Errors_in_mine;

#endif

#endif /* _GAMESAVE_H */
