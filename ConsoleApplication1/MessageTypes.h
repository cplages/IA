#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
	Msg_WhosAGoodBoy,
	Msg_ImAGoodBoy,
	Msg_GetThatBone
};

inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case 1:

		return "HiHoneyImHome";

	case 2:

		return "StewReady";

	case 3:

		return "WhosAGoodBoy";

	case 4:

		return "ImAGoodBoy";

	case 5:

		return "GetThatBone";

	default:

		return "Not recognized!";
	}
}

#endif