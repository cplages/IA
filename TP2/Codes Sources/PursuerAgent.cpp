#include "PursuerAgent.h"
#include "SteeringBehaviors.h"

PursuerAgent::PursuerAgent(GameWorld* world, Vector2D position, double rotation, Vector2D velocity, double mass,double max_force,
							double max_speed, double max_turn_rate, double scale, Vehicle *target, Vector2D offset)
	:Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
	SteeringBehavior * mySteering = Steering();
	mySteering->OffsetPursuitOn(target, offset);
	mySteering->SeparationOffsetOn(offset);
}


PursuerAgent::~PursuerAgent()
{
}
