#include "stdafx.h"
#include "DoggoOwnedStates.h"
#include "DoggoOwnedStates.h"
#include "Doggo.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "misc/utils.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

DoggosGlobalState *DoggosGlobalState::Instance()
{
	static DoggosGlobalState instance;

	return &instance;
}

void DoggosGlobalState::Execute(Doggo *dog)
{
	//nothing to do
}

bool DoggosGlobalState::OnMessage(Doggo *dog, const Telegram &msg)
{
	//nothing to do
	return false;
}

//-------------------------------------------------------------------------PlayInFarm

PlayInFarm *PlayInFarm::Instance()
{
	static PlayInFarm instance;

	return &instance;
}

void PlayInFarm::Enter(Doggo *dog)
{
	if (dog->Location() != farm)
	{
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Time to run after EVERYTHING!";

		dog->ChangeLocation(farm);
	}
}

void PlayInFarm::Execute(Doggo *dog)
{
	dog->IncreaseFatigue();

	switch (RandInt(0, 3))
	{
	case 0:
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Oh, a butterfly! Oh, a squirrel! Oh, a rock!";
		break;

	case 1:
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Catchin' that fluffy tail";
		break;

	case 2:
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Runnin' after the milk driver";
		break;
	case 3:
		cout << "\n"
			<< GetNameOfEntity(dog->ID()) << ": Bein' a good doggo. *Bark at squirrel*";
		break;
	}

	if(dog->Fatigued())
		dog->GetFSM()->ChangeState(GoHomeAndRest::Instance());
}

void PlayInFarm::Exit(Doggo *dog)
{
}

bool PlayInFarm::OnMessage(Doggo *dog, const Telegram &msg)
{
	return false;
}

//------------------------------------------------------------------------GoHomeAndRest

GoHomeAndRest *GoHomeAndRest::Instance()
{
	static GoHomeAndRest instance;

	return &instance;
}

void GoHomeAndRest::Enter(Doggo *dog)
{
	if (dog->Location() != shack)
	{
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Trottin' home. Wouaf.";

		dog->ChangeLocation(shack);

		//let the owner know I'm home
		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
								  dog->ID(),			//ID of sender
								  ent_Miner_Bob,		//ID of recipient
								  Msg_ImAGoodBoy,		//the message
								  NO_ADDITIONAL_INFO);
	}
}

void GoHomeAndRest::Execute(Doggo *dog)
{
	//if doggo is not fatigued go play in the farm again again.
	if (dog->IsRested())
	{
		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": Nice nap. Goin' outside doin' by good boy duty. *Bark*";

		dog->GetFSM()->ChangeState(PlayInFarm::Instance());
	}
	else
	{
		//rest
		dog->DecreaseFatigue();

		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": ZZZZ... *Snoring*";
	}
}

void GoHomeAndRest::Exit(Doggo *dog)
{
}

bool GoHomeAndRest::OnMessage(Doggo *dog, const Telegram &msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_WhosAGoodBoy:

		cout << "\nMessage handled by " << GetNameOfEntity(dog->ID())
			 << " at time: " << Clock->GetCurrentTime();

		SetTextColor(0x0000 | FOREGROUND_INTENSITY);

		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": IMA GOOD BOY!!";

		dog->GetFSM()->ChangeState(GetPattedByOwner::Instance());

		return true;

	case Msg_GetThatBone:

		cout << "\nMessage handled by " << GetNameOfEntity(dog->ID())
			 << " at time: " << Clock->GetCurrentTime();

		SetTextColor(0x0000 | FOREGROUND_INTENSITY);

		cout << "\n"
			 << GetNameOfEntity(dog->ID()) << ": *Grab the bone mid-air and swallow it before landing*";

		dog->GetFSM()->ChangeState(EatRemains::Instance());

		return true;

	} //end switch

	return false; //send message to global message handler
}

//------------------------------------------------------------------------GetPattedByOwner

GetPattedByOwner *GetPattedByOwner::Instance()
{
	static GetPattedByOwner instance;

	return &instance;
}

void GetPattedByOwner::Enter(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": PAT PAT PAT PAT PAT PAT PAT!! (x1000)";
}

void GetPattedByOwner::Execute(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": My lord it's heaven...";

	dog->GetFSM()->RevertToPreviousState();
}

void GetPattedByOwner::Exit(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": *Joy power 1000*";
}

bool GetPattedByOwner::OnMessage(Doggo *dog, const Telegram &msg)
{
	//send msg to global message handler
	return false;
}


//------------------------------------------------------------------------EatRemains

EatRemains *EatRemains::Instance()
{
	static EatRemains instance;

	return &instance;
}

void EatRemains::Enter(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": Is that a bird? A plane? No it's a bone!";
}

void EatRemains::Execute(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": What a bone!!!";

	dog->GetFSM()->RevertToPreviousState();
}

void EatRemains::Exit(Doggo *dog)
{
	cout << "\n"
		 << GetNameOfEntity(dog->ID()) << ": Best bone in world. *Bark*";
}

bool EatRemains::OnMessage(Doggo *dog, const Telegram &msg)
{
	//send msg to global message handler
	return false;
}