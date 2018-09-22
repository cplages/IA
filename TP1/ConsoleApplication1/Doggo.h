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

/* New agent Doggo interacting with the Miner. 
Depending on the value of m_iFatigue, Doggo plays in farm or rests at home */

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

	void Update();

	virtual bool HandleMessage(const Telegram &msg);

	StateMachine<Doggo> *GetFSM() const { return m_pStateMachine; }

	location_type Location() const { return m_Location; }
	void ChangeLocation(location_type loc) { m_Location = loc; }

	bool Fatigued() const;
	bool IsRested() const;
	void DecreaseFatigue() { m_iFatigue -= 1; }
	void IncreaseFatigue() { m_iFatigue += 1; }
};

#endif
