.set LOCALID_NURSE, 1
.set LOCALID_NURSE_2, 5

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

@ MattEmerald
OldaleTown_PokemonCenter_1F_EventScript_InfiniteRareCandiesAndFullRestore::
	lockall
	msgbox OldaleTown_PokemonCenter_1F_Text_FreeItems, MSGBOX_NPC
	closemessage
	giveitem ITEM_RARE_CANDY
	giveitem ITEM_FULL_RESTORE
	goto OldaleTown_PokemonCenter_1F_NurseExit
	end

OldaleTown_PokemonCenter_1F_Text_FreeItems:
	.string "There's been overcrowding of\n"
	.string "POKéMON CENTERS due to COVID-19!\l"
	.string "Please take government subsidized\l"
	.string "Rare Candies and Full Restores!$"

OldaleTown_PokemonCenter_1F_NurseExit::
	closemessage
	switch VAR_FACING
	case DIR_NORTH, OldaleTown_PokemonCenter_1F_NurseExitFacingNorth
	case DIR_WEST, OldaleTown_PokemonCenter_1F_NurseExitFacingEastOrWest
	case DIR_EAST, OldaleTown_PokemonCenter_1F_NurseExitFacingEastOrWest
	end

OldaleTown_PokemonCenter_1F_NurseExitFacingNorth::
	applymovement LOCALID_NURSE_2, Movement_NurseExit_FacingNorth
	waitmovement 0
	goto Event_NurseEnd
	end

OldaleTown_PokemonCenter_1F_NurseExitFacingEastOrWest::
	applymovement LOCALID_NURSE_2, Movement_NurseExit_FacingEastOrWest
	waitmovement 0
	goto Event_NurseEnd
	end

Movement_NurseExit_FacingNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

Movement_NurseExit_FacingEastOrWest:
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

Event_NurseEnd::
	removeobject LOCALID_NURSE_2
	releaseall
	end



