#include "PursuerAgent.h"
#include "SteeringBehaviors.h"

PursuerAgent::PursuerAgent(GameWorld* world, Vector2D position, double rotation, Vector2D velocity, double mass,double max_force,
							double max_speed, double max_turn_rate, double scale, Vehicle *target, Vector2D offset)
	:Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
	//define Pursuer behavior
	SteeringBehavior * mySteering = Steering();
	mySteering->OffsetPursuitOn(target, offset);
	//use the same method as separate but define the offset distance from which the vehicles should be separated of.
	mySteering->SeparationOffsetOn(offset);
}

void PursuerAgent::setOffset(Vector2D offset) 
{
	SteeringBehavior * mySteering = Steering();
	mySteering->SetOffset(offset);
}

Vector2D PursuerAgent::getOffset() 
{
	SteeringBehavior * mySteering = Steering();
	return mySteering->GetOffset();
}
PursuerAgent::~PursuerAgent()
{
}
