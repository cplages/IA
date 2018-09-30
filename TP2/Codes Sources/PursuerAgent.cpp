#include "PursuerAgent.h"
#include "SteeringBehaviors.h"

PursuerAgent::PursuerAgent(GameWorld* world, Vector2D position, double rotation, Vector2D velocity, double mass,double max_force,
							double max_speed, double max_turn_rate, double scale, Vehicle *target, Vector2D offset)
	:Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
	//define Pursuer behavior
	this->mySteering = Steering();
	this->mySteering->OffsetPursuitOn(target, offset);
	//use the same method as separate but define the offset distance from which the vehicles should be separated of.
	this->mySteering->SeparationOffsetOn(offset);

	this->targets.emplace(this->targets.begin(), target);
}

void PursuerAgent::Update(double time_elapsed) 
{
	this->Vehicle::Update(time_elapsed);
	this->findClosestTarget();
}

void PursuerAgent::setOffset(Vector2D offset) 
{
	this->mySteering->SetOffset(offset);
}

Vector2D PursuerAgent::getOffset() 
{
	return this->mySteering->GetOffset();
}

void PursuerAgent::findClosestTarget() 
{
	if (targets.size() > 1) 
	{
		Vehicle *closer_target = (*targets.begin());
		double distance_min = (this->Pos()).Distance(closer_target->Pos()) ;
		for(std::vector<Vehicle *>::iterator it = targets.begin() + 1 ; it != targets.end(); ++it) 
		{
			double tmp = (this->Pos()).Distance((*it)->Pos());
			if (tmp < distance_min) {
				closer_target = (*it);
				distance_min = tmp;
			}
		}

		this->mySteering->SetTargetAgent1(closer_target);
	}
}

void PursuerAgent::setNewTarget(Vehicle *target) 
{
	this->targets.emplace(this->targets.begin(), target);
}

void PursuerAgent::removeTarget(int index)
{
	std::vector<Vehicle *>::iterator it = targets.begin() + index;
	this->targets.erase(it);
}


PursuerAgent::~PursuerAgent()
{
}
