/* $Id: kdefs.h,v 1.1.1.1 2006/03/17 19:58:13 zicodxx Exp $ */
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

#ifdef __cplusplus

// In khelp.c
int DoHelp();

// In kcurve.c
int InitCurve();
int GenerateCurve();
int DecreaseR4();
int IncreaseR4();
int DecreaseR1();
int IncreaseR1();
int DeleteCurve();
int SetCurve();

// In kmine.c
int SaveMine();
int LoadMine();
int MineMenu();
int CreateNewMine();
int LoadOldMine();

int SaveSituation();
int LoadSituation();

struct PHYSFS_File;
int save_mine_data_compiled(struct PHYSFS_File *SaveFile);

// In kgame.c
int SetPlayerPosition(void);
int SaveGameData();
int LoadGameData();
int LoadMineOnly();
void ResetFilename();

// In group.c
int LoadGroup();
int SaveGroup();
int PrevGroup(void);
int NextGroup(void);
int CreateGroup();
int SubtractFromGroup();
int DeleteGroup();
int MarkGroupSegment();
int MoveGroup(void);
int CopyGroup(void);
int AttachSegmentNew(void);
int UngroupSegment();
int GroupSegment();
int Degroup();
int RotateGroup();

// In segment.c
int ToggleBottom();
void make_curside_bottom_side();
int select_segment_by_number();
int select_segment_with_powerup();

// In editor.c
int UndoCommand();

// In kview.c
int ZoomOut();
int ZoomIn();
int MoveAway();
int MoveCloser();
int ToggleChaseMode();

// In kbuild.c
int CreateBridge();
int FormJoint();
int CreateAdjacentJoint();
int CreateAdjacentJointsSegment();
int CreateAdjacentJointsAll();
int CreateSloppyAdjacentJoint();
int CreateSloppyAdjacentJointsGroup();

// In ksegmove.c
int DecreaseHeading();
int IncreaseHeading();
int DecreasePitch();
int IncreasePitch();
int DecreaseBank();
int IncreaseBank();

// In ksegsel.c
int SelectCurrentSegForward();
int SelectCurrentSegBackward();
int SelectNextSide();
int SelectPrevSide();
int CopySegToMarked();
int SelectBottom();
int SelectFront();
int SelectTop();
int SelectBack();
int SelectLeft();
int SelectRight();

// In ksegsize.c
int IncreaseSegLength();
int DecreaseSegLength();
int DecreaseSegWidth();
int IncreaseSegWidth();
int IncreaseSegHeight();
int DecreaseSegHeight();
int ToggleSegSizeMode();
int PerturbCurside();
int PerturbCursideBig();

int IncreaseSegLengthBig();
int DecreaseSegLengthBig();
int DecreaseSegWidthBig();
int IncreaseSegWidthBig();
int IncreaseSegHeightBig();
int DecreaseSegHeightBig();

int IncreaseSegLengthDefault();
int DecreaseSegLengthDefault();
int IncreaseSegWidthDefault();
int DecreaseSegWidthDefault();
int IncreaseSegHeightDefault();
int DecreaseSegHeightDefault();

//	In ktmap.c
int AssignTexture();
int AssignTexture2();
int ClearTexture2();
int PropagateTextures();
int PropagateTexturesMove();
int PropagateTexturesMoveUVs();
int PropagateTexturesUVs();
int PropagateTexturesSelected();

//--//// In macro.c
//--//int MacroMenu();
//--//int MacroPlayFast();
//--//int MacroPlayNormal();
//--//int MacroRecordAll();
//--//int MacroRecordKeys();
//--//int MacroSave();
//--//int MacroLoad();

// In editor.c
int medlisp_add_segment();
int AttachSegment();
int DeleteSegment();
int DosShell();
int CallLisp();
int ExitEditor();
int ShowAbout();
int ExchangeMarkandCurseg();
int CopySegtoMarked();
int med_keypad_goto_prev();
int med_keypad_goto_next();
int med_keypad_goto();
int med_increase_tilings();
int med_decrease_tilings();
int ToggleAutosave();
int MarkStart();
int MarkEnd();

//	Texture.c
int	TexFlipX();
int	TexFlipY();
int	TexSlideUp();
int	TexSlideLeft();
int	TexSetDefault();
int	TexSetDefaultSelected();
int	TexSlideRight();
int	TexRotateLeft();
int	TexSlideDown();
int	TexRotateRight();
int	TexSelectActiveEdge();
int	TexRotate90Degrees();
int	TexIncreaseTiling();
int	TexDecreaseTiling();
int	TexSlideUpBig();
int	TexSlideLeftBig();
int	TexSlideRightBig();
int	TexRotateLeftBig();
int	TexSlideDownBig();
int	TexRotateRightBig();
int	TexStretchDown();
int	TexStretchUp();
int	TexChangeAll();
int	TexChangeAll2();

//	object.c
int	ObjectPlaceObject();
int	ObjectMakeCoop();
int	ObjectPlaceObjectTmap();
int	ObjectDelete();
int	ObjectMoveForward();
int	ObjectMoveLeft();
int	ObjectSetDefault();
int	ObjectMoveRight();
int	ObjectMoveBack();
int	ObjectMoveDown();
int	ObjectMoveUp();
int	ObjectMoveNearer();
int	ObjectMoveFurther();
int	ObjectSelectNextinSegment();
int	ObjectSelectNextType();
int	ObjectDecreaseBank();
int	ObjectIncreaseBank();
int	ObjectDecreasePitch();
int	ObjectIncreasePitch();
int	ObjectDecreaseHeading();
int	ObjectIncreaseHeading();
int  	ObjectResetObject();


//	elight.c
int	LightSelectNextVertex();
int	LightSelectNextEdge();
int	LightCopyIntensity();
int	LightCopyIntensitySegment();
int	LightDecreaseLightVertex();
int	LightIncreaseLightVertex();
int	LightDecreaseLightSide();
int	LightIncreaseLightSide();
int	LightDecreaseLightSegment();
int	LightIncreaseLightSegment();
int	LightSetMaximum();
int	LightSetDefault();
int	LightSetDefaultAll();
int	LightAmbientLighting();

// seguvs.c
int fix_bogus_uvs_on_side();
int fix_bogus_uvs_all();
int set_average_light_on_curside(void);
int set_average_light_on_all(void);
int set_average_light_on_all_quick(void);

// Miscellaneous, please put in correct file if you have time
int GotoMainMenu();
int GotoGameScreen();
int DropIntoDebugger();
int CreateDefaultNewSegment();
int CreateDefaultNewSegmentandAttach();
int ClearSelectedList();
int ClearFoundList();
int SortSelectedList();
int SetPlayerFromCurseg();
int SetPlayerFromCursegAndRotate();
int SetPlayerFromCursegMinusOne();
int FindConcaveSegs();
int SelectNextFoundSeg();
int do_reset_orient();
int GameZoomOut();
int GameZoomIn();

// John's temp page stuff
int medtmp_set_page();

// In objpage.c
int objpage_goto_next_object();

// In medsel.c
int SelectPreviousFoundSeg(void);

// In wall.c
extern int wall_add_blastable(void);
extern int wall_add_closed_wall(void);
extern int wall_add_external_wall(void);
extern int wall_lock_door(void);
extern int wall_unlock_door(void);
extern int wall_automate_door(void);
extern int wall_deautomate_door(void);
extern int wall_assign_door_1(void);
extern int wall_assign_door_2(void);
extern int wall_assign_door_3(void);
extern int wall_assign_door_4(void);
extern int wall_assign_door_5(void);
extern int wall_assign_door_6(void);
extern int wall_assign_door_7(void);
extern int wall_assign_door_8(void);
extern int do_wall_dialog(void);
extern int do_trigger_dialog(void);
extern int check_walls(void);
extern int delete_all_walls(void);
extern int delete_all_controlcen_triggers(void);

// In centers.c
int do_centers_dialog(void);

// In switch.c
//extern int trigger_add_damage(void);
//extern int trigger_add_blank(void);
//extern int trigger_add_exit(void);
//extern int trigger_add_repair(void);
//extern int trigger_control(void);
//extern int trigger_remove(void);
//extern int trigger_add_if_control_center_dead(void);
int bind_wall_to_control_trigger(void);

// In med.c
int fuelcen_create_from_curseg();
int repaircen_create_from_curseg();
int controlcen_create_from_curseg();
int robotmaker_create_from_curseg();
int fuelcen_reset_all();
int RestoreGameState();
int fuelcen_delete_from_curseg();
int goal_blue_create_from_curseg();
int goal_red_create_from_curseg();

// In editor\robot.c
int do_robot_dialog();
int do_object_dialog();

#endif
