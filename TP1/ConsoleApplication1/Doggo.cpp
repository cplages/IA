#include "stdafx.h"
#include "Doggo.h"

// Constructor
Doggo::Doggo(int id) : m_Location(shack), m_iFatigue(0), BaseGameEntity(id)
{
	//set up state machine
	m_pStateMachine = new StateMachine<Doggo>(this);
	//at first the dog rests
	m_pStateMachine->SetCurrentState(GoHomeAndRest::Instance());
	// global state is defined but unused
	m_pStateMachine->SetGlobalState(DoggosGlobalState::Instance());
}

bool Doggo::HandleMessage(const Telegram &msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void Doggo::Update()
{
	//set text color to blue
	SetTextColor(0x0000 | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}

bool Doggo::Fatigued() const
{
	if (m_iFatigue > DoggoTirednessThreshold)
	{
		return true;
	}

	return false;
}

bool Doggo::IsRested() const
{
	if (m_iFatigue == 0)
	{
		return true;
	}

	return false;
}