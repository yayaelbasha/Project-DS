#include "Rover.h"
#include "Mission.h"

Rover::Rover() {
	missionsDone = 0; 
}

Rover::Rover(TYPE Rovertype, int checkDur, int speed, int missionLimit) {
	this->Rovertype = Rovertype;
	this->checkDur = checkDur;
	this->speed = speed;
	this->missionLimit = missionLimit;
	missionsDone = 0;
}

// Get for Data members
int Rover::getId() { return Id; }
TYPE Rover::getRovertype() { return Rovertype; }
int Rover::getcheckDur() { return checkDur; }
int Rover::getspeed() { return speed; }
bool Rover::getIsCheckUp() { return IsCheckUp; }
Mission* Rover::getMission() { return missionAssign; }

// Set for Data members
void Rover::setId(int Id) { this->Id = Id; }
void Rover::setRovertype(TYPE Rovertype) { this->Rovertype = Rovertype; }
void Rover::setcheckDur(int checkDur) { this->checkDur = checkDur; }
void Rover::setspeed(int speed) { this->speed = speed; }
void Rover::SetMission(Mission* missionAssign) {
	this->missionAssign = missionAssign;
	missionsDone++;
}


