#include "Rover.h"
#include "Mission.h"

int Rover::NewId = 1;

Rover::Rover() : Id(NewId++) {
	missionsDone = 0; 
}

Rover::Rover(TYPE Rovertype, int checkDur, int speed, int missionLimit) : Id(NewId++) {
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
int Rover::getMissionsDone() { return missionsDone;}
int Rover::getMissionLimit() { return missionLimit; }
int Rover::getReleaseDay() { return ReleaseDay; }



// Set for Data members
void Rover::setRovertype(TYPE Rovertype) { this->Rovertype = Rovertype; }
void Rover::setcheckDur(int checkDur) { this->checkDur = checkDur; }
void Rover::setspeed(int speed) { this->speed = speed; }
void Rover::SetMission(Mission* missionAssign) {
	this->missionAssign = missionAssign;
	missionsDone++;
}
void Rover::setMissionsDone(int missionsDone) {this->missionsDone = missionsDone;}
void Rover::setMissionLimit(int missionLimit) { this->missionLimit = missionLimit; }
void Rover::setReleaseDay(int Day) { ReleaseDay = Day + checkDur; }




