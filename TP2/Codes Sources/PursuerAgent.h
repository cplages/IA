#ifndef PURSUER_AGENT_H
#define PURSUER_AGENT_H

#include "Vehicle.h"

/* class describing a vehicule type which is following another vehicle from a distance given(offset) and keep a distance (offset) between itself and it neighbors.*/

class PursuerAgent : public Vehicle
{
private:
	SteeringBehavior *mySteering;
	std::vector<Vehicle *> targets;

public:
	PursuerAgent(GameWorld* world,
				Vector2D position,
				double    rotation,
				Vector2D velocity,
				double    mass,
				double    max_force,
				double    max_speed,
				double    max_turn_rate,
				double    scale,
				Vehicle *target,
				Vector2D offset);

	
	void        Update(double time_elapsed);
	
	//offset accessors
	Vector2D getOffset();
	void setOffset(Vector2D offset);

	void findClosestTarget();

	void setNewTarget(Vehicle *target);
	void removeTarget(int index);


	~PursuerAgent();
};


#endif 

