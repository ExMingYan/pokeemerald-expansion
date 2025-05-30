LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
    .string "哎呀呀，你是一个人旅行吗？\n明明你才这么年轻！真了不起！\p我的孩子也该\n好好向你学习！\p我？我可是宝可方块专家。\p只要稍微认真一些，\n我就能混合出顶级的宝可方块。\p想不想向我这个宝可方块大师\n学习学习呀？$"

LilycoveCity_House3_Text_OhAreYouSure:
    .string "哦？是吗？\p不要总是试图\n独自面对一切，亲爱的！$"

LilycoveCity_House3_Text_ExplainPokeblocks:
    .string "啊，太好了！你是聪明人！\n接下来可能有点长，但请仔细听好！\p准备好了吗？\p查看宝可方块的时候，\n你会发现它们都有一个细腻度。\p这个数值越小，\n说明品质越好，要牢牢记住！\p优质宝可方块的特点是\n细腻度低，而等级高。\p而且比起普通的宝可方块，宝可梦\n能吃下更多优质的宝可方块哦！\p还有一点很重要：\p如果想制作细腻的宝可方块，\n就得使用不同种类的树果。\p不要吝啬——树果的种类\n会影响到宝可方块细腻度。\p另外还有一点：\p混合树果的人越多，\n宝可方块就越细腻，\p因此你要多和其他人交流，\n一起来制作宝可方块。\p掌握这些诀窍，\n就能做出优质宝可方块啦。\p如果每个人都有喜爱的宝可梦，\n细腻的宝可方块和幸福的家庭，\l世界该多美好啊！\p加油哦，亲爱的！$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
    .string "妻子生下四胞胎的时候，\n我真的吓了一跳。\p但现在看着他们一起玩耍，\n我觉得很幸福。$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
    .string "我们在进行多人对战，\n我肯定会赢的。$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
    .string "我们喜欢在记录角\n进行混合了，\p不过到底混合的是什么呢？$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
    .string "我们要用树果混合器\n制作出超级宝可方块！$"

LilycoveCity_House3_Text_GoingToEnterContest:
    .string "我要让大家看看我的宝可梦有多强壮，\n所以我们打算一起参加华丽大赛。$"

