#ifndef DOGGO_OWNED_STATES_H
#define DOGGO_OWNED_STATES_H

#include "fsm/State.h"

class Doggo;

//------------------------------------------------------------------------
// Global state in case of futures implementations 
//------------------------------------------------------------------------
class DoggosGlobalState : public State<Doggo>
{
  private:
	DoggosGlobalState() {}

	//copy ctor and assignment should be private
	DoggosGlobalState(const DoggosGlobalState &);
	DoggosGlobalState &operator=(const DoggosGlobalState &);

  public:
	//this is a singleton
	static DoggosGlobalState *Instance();

	virtual void Enter(Doggo *dog) {}

	virtual void Execute(Doggo *dog);

	virtual void Exit(Doggo *dog) {}

	virtual bool OnMessage(Doggo *dog, const Telegram &msg);
};

//------------------------------------------------------------------------
// The dog is going to play in the farm when is rested. 
// After a moment, the dog will be tired and go back to the home to rest.
//------------------------------------------------------------------------
class PlayInFarm : public State<Doggo>
{
  private:
	PlayInFarm() {}

	//copy ctor and assignment should be private
	PlayInFarm(const PlayInFarm &);
	PlayInFarm &operator=(const PlayInFarm &);

  public:
	//this is a singleton
	static PlayInFarm *Instance();

	virtual void Enter(Doggo *dog);

	virtual void Execute(Doggo *dog);

	virtual void Exit(Doggo *dog);

	virtual bool OnMessage(Doggo *dog, const Telegram &msg);
};

//------------------------------------------------------------------------
// If the miner gives a bone to the dog, Doggo eats the bone remains.
//------------------------------------------------------------------------
class EatRemains : public State<Doggo>
{
  private:
	EatRemains() {}

	//copy ctor and assignment should be private
	EatRemains(const EatRemains &);
	EatRemains &operator=(const EatRemains &);

  public:
	//this is a singleton
	static EatRemains *Instance();

	virtual void Enter(Doggo *dog);

	virtual void Execute(Doggo *dog);

	virtual void Exit(Doggo *dog);

	virtual bool OnMessage(Doggo *dog, const Telegram &msg);
};

//------------------------------------------------------------------------
// When the dog is tired, it rests at home for a while. It can interact
// with the miner : getting patted or eating a bone. 
//------------------------------------------------------------------------
class GoHomeAndRest : public State<Doggo>
{
  private:
	GoHomeAndRest() {}

	//copy ctor and assignment should be private
	GoHomeAndRest(const GoHomeAndRest &);
	GoHomeAndRest &operator=(const GoHomeAndRest &);

  public:
	//this is a singleton
	static GoHomeAndRest *Instance();

	virtual void Enter(Doggo *dog);

	virtual void Execute(Doggo *dog);

	virtual void Exit(Doggo *dog);

	virtual bool OnMessage(Doggo *dog, const Telegram &msg);
};

//------------------------------------------------------------------------
// At home, by sending a message "I am a good boy" to the miner, Doggo
// get patted.
//------------------------------------------------------------------------
class GetPattedByOwner : public State<Doggo>
{
  private:
	GetPattedByOwner() {}

	//copy ctor and assignment should be private
	GetPattedByOwner(const GetPattedByOwner &);
	GetPattedByOwner &operator=(const GetPattedByOwner &);

  public:
	//this is a singleton
	static GetPattedByOwner *Instance();

	virtual void Enter(Doggo *dog);

	virtual void Execute(Doggo *dog);

	virtual void Exit(Doggo *dog);

	virtual bool OnMessage(Doggo *dog, const Telegram &msg);
};

#endif