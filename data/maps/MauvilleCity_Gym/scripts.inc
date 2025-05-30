MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
    .string "嗨，怎么样，向冠军的目标\n冲刺的{PLAYER}？\p紫堇市道馆的馆主铁旋\n使用电属性宝可梦。\p如果用水属性宝可梦\n挑战他，会被他电麻的！吱——\p还有，他在自己的道馆里设置了一大堆\n由开关控制的电子屏障！怪人！\p好了，加油吧！$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
    .string "哇，真让人吃惊！\n你打开了屏障！$"

MauvilleCity_Gym_Text_KirkIntro:
    .string "让我的电之魂\n粉碎你的梦想吧，哦——耶！$"

MauvilleCity_Gym_Text_KirkDefeat:
    .string "插上了电源，\n但电流过载了！$"

MauvilleCity_Gym_Text_KirkPostBattle:
    .string "宝可梦和摇滚，\n都要用心来表现，哦——耶！$"

MauvilleCity_Gym_Text_ShawnIntro:
    .string "我跟着铁旋训练，\n不会轻易输给你的！$"

MauvilleCity_Gym_Text_ShawnDefeat:
    .string "电源被拔掉了……$"

MauvilleCity_Gym_Text_ShawnPostBattle:
    .string "我们的道馆馆主铁旋\n在这里已经很久很久了，\p你爸爸出生前\n他就在战斗。$"

MauvilleCity_Gym_Text_BenIntro:
    .string "道馆里有谜题！\n很好玩吧？$"

MauvilleCity_Gym_Text_BenDefeat:
    .string "输了一点也不好玩……$"

MauvilleCity_Gym_Text_BenPostBattle:
    .string "铁旋说他喜欢\n弄些开关控制的小机关。$"

MauvilleCity_Gym_Text_VivianIntro:
    .string "我的魅力和宝可梦的招式\n会让你大吃一惊！$"

MauvilleCity_Gym_Text_VivianDefeat:
    .string "你的力量令我十分吃惊！$"

MauvilleCity_Gym_Text_VivianPostBattle:
    .string "听说紫堇市是由\n铁旋建立起来的。\p在我们成为训练家之前，\n他已经做了很久的训练家了。\l他一定知道很多很多事情！$"

MauvilleCity_Gym_Text_AngeloIntro:
    .string "我喜欢闪光的东西！$"

MauvilleCity_Gym_Text_AngeloDefeat:
    .string "呀……\n眼睛花了……$"

MauvilleCity_Gym_Text_AngeloPostBattle:
    .string "紫堇市道馆的铁旋额头上\n总是闪着光，我好兴奋！$"

MauvilleCity_Gym_Text_WattsonIntro:
    .string "我放弃了自己改建城市的计划，\n而是将时间花在了道馆内，\l制作了这个电门迷宫。\p哦？\n你是怎么走到这里来的？\p是吗？\n你是说你已经破解了我的迷宫？\p哇哈哈哈！\n太有趣了！\p那么，我——\n紫堇市宝可梦道馆的馆主——铁旋，\l就让你见识一下电气的威力吧！$"

MauvilleCity_Gym_Text_WattsonDefeat:
    .string "哇哈哈哈！\n好，我输了！\p你让我兴奋极了！\n收下这枚徽章！$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
    .string "{PLAYER}从铁旋那里\n得到了电力徽章。$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
    .string "有了这个电力徽章，\n宝可梦就可以在对战外使用碎岩了，\p而且你的宝可梦的速度也会\n变得稍微快一点。\p嗯……\n你也收下这个吧！$"

MauvilleCity_Gym_Text_ExplainShockWave:
    .string "那是招式学习器34电击波，\n是永远不会打偏的可靠招式！\l你可以信赖它！\p…… …… ……$"

MauvilleCity_Gym_Text_RegisteredWattson:
    .string "把道馆馆主铁旋\n登记到宝可导航里了。$"

MauvilleCity_Gym_Text_WattsonPostBattle:
    .string "能看到像你这样前途无量的年轻\n训练家，我真高兴呀！$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
    .string "哇哈哈哈！\n年轻人，向前进，努力吧！$"

MauvilleCity_Gym_Text_GymStatue:
    .string "紫堇市宝可梦道馆$"

MauvilleCity_Gym_Text_GymStatueCertified:
    .string "紫堇市宝可梦道馆\p铁旋认可的训练家：\n{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
    .string "铁旋：啊哈！你终于来了！\n我知道你想要什么。\l你想和我的宝可梦对战！\p哇哈哈哈哈！\p别说我没警告你，\l我会让你火花四溅的！$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
    .string "噢……\n我们的电池没电了……$"

MauvilleCity_Gym_Text_WattsonPostRematch:
    .string "铁旋：我们又要给我们的\n电池充电了。\p等我们充好电，\n我们会很高兴接受你的挑战。\p所以，有时间的话再来吧，\n好吗？$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
    .string "铁旋：啊哈！你终于来了！\n我知道你想要什么。\l你想和我的宝可梦对战！\p哇哈哈哈哈！\p哎，等等！\n你只带了1只宝可梦！\p带2只以上宝可梦\n再来吧，好吗？$"

