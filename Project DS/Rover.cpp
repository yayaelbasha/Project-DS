#include "Rover.h"

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