#include "LeaderAgent.h"
#include "SteeringBehaviors.h"


LeaderAgent::LeaderAgent(GameWorld* world, Vector2D position, double rotation, Vector2D velocity, double mass, double max_force,
						double max_speed, double max_turn_rate, double scale, bool human)
						:Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
	//define the vehicle behavior.
	this->mySteering = Steering();

	if (human) 
	{
		this->mySteering->HumanOn();
	}
	else
	{
		this->mySteering->WanderOn();
	}
}

void LeaderAgent::SetHumanBehaviour(bool isHuman)
{
	if (isHuman)
	{
		this->mySteering->WanderOff();
		this->mySteering->HumanOn();
	}
	else
	{
		this->mySteering->HumanOff();
		this->mySteering->WanderOn();
	}
}


LeaderAgent::~LeaderAgent()
{
}
