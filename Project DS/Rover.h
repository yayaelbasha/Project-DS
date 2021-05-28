#ifndef Rover_H
#define Rover_H

#include "Defs.H"
#include "Mission.h"

class Rover
{
private:
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
	TYPE getRovertype() {return Rovertype;}
	int getcheckDur() { return checkDur; }
	int getspeed() { return speed; }
	bool getIsCheckUp() { return IsCheckUp; }
	Mission* getMission() { return missionAssign; }

	void setRovertype(TYPE Rovertype) { this->Rovertype = Rovertype; }
	void setcheckDur(int checkDur) { this->checkDur = checkDur; }
	void setspeed(int speed) {this->speed = speed;}
	void SetMission(Mission* missionAssign) { 
		this->missionAssign = missionAssign; 
		missionsDone++;
	}

};

#endif