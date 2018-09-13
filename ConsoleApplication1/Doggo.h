#ifndef DOGGO_H
#define DOGGO_H

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "DoggoOwnedStates.h"
#include "fsm/StateMachine.h"


//above this value a doggo is sleepy
const int DoggoTirednessThreshold = 3;

class Doggo : public BaseGameEntity
{
  private:
	//an instance of the state machine class
	StateMachine<Doggo> *m_pStateMachine;

	location_type m_Location;

	//the higher the value, the more tired the doggo
	int m_iFatigue;

  public:
	  Doggo(int id);

	~Doggo() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool HandleMessage(const Telegram &msg);

	StateMachine<Doggo> *GetFSM() const { return m_pStateMachine; }

	//-------------------------------------------------------------accessors
	location_type Location() const { return m_Location; }
	void ChangeLocation(location_type loc) { m_Location = loc; }

	bool Fatigued() const;
	bool IsRested() const;
	void DecreaseFatigue() { m_iFatigue -= 1; }
	void IncreaseFatigue() { m_iFatigue += 1; }
};

#endif
