#ifndef Rover_H
#define Rover_H

#include "Defs.H"
#include "Mission.h"

class Mission;

class Rover
{
private:
	int Id;
	TYPE Rovertype;
	int checkDur;
	int speed;
	int missionLimit;
	bool IsCheckUp;
	int missionsDone;
	Mission* missionAssign;

public:
	Rover();
	Rover(TYPE Rovertype,int checkDur,int speed, int missionLimit);

	// Set And Get for Data members
	TYPE getRovertype();
	int getcheckDur();
	int getspeed();
	bool getIsCheckUp();
	Mission* getMission();
	int getId();

	void setRovertype(TYPE Rovertype);
	void setcheckDur(int checkDur);
	void setspeed(int speed);
	void SetMission(Mission* missionAssign);
	void setId(int Id);
};

#endif