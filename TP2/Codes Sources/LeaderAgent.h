#ifndef LEADER_AGENT_H
#define LEADER_AGENT_H

#include "Vehicle.h"

/*a vehicle which is just wandering */

class LeaderAgent : public Vehicle
{
private:
	SteeringBehavior *mySteering;
	bool isHuman;

public:
	LeaderAgent(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		double    mass,
		double    max_force,
		double    max_speed,
		double    max_turn_rate,
		double    scale,
		bool human);

	void SetHumanBehaviour(bool isHuman);

	~LeaderAgent();
};


#endif 

