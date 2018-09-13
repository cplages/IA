#ifndef DOGGO_OWNED_STATES_H
#define DOGGO_OWNED_STATES_H

#include "fsm/State.h"

class Doggo;

//------------------------------------------------------------------------
//

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
//

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
//

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
//

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
//

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