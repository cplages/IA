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
	case 0:

		return "HiHoneyImHome";

	case 1:

		return "StewReady";

	case 2:

		return "WhosAGoodBoy";

	case 3:

		return "ImAGoodBoy";

	case 4:

		return "GetThatBone";

	default:

		return "Not recognized!";
	}
}

#endif