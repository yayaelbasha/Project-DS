#pragma once

#include "Mission.h"
#include "Defs.H"
#include "Rover.h"

class Mission{

private:
	int id;
	TYPE Type;
	int FD;
	int TargetLoc;
	int duration;
	int Sign;
	Rover* roverAssign;

public:
	Mission(){}
	Mission(int id, TYPE Type, int FD, int TargetLoc, int duration, int Sign, Rover* roverAssign = NULL) {
		this->id = id;
		this->Type = Type;
		this->FD = FD;
		this->TargetLoc = TargetLoc;
		this->duration = duration;
		this->Sign = Sign;
	}

	/// Set and Get for Data members

	//GET
	TYPE getType() { return Type; }
	int getFD() { return FD; }
	int getTargetLoc() { return TargetLoc; }
	int getduration() { return duration; }
	int getSign() { return Sign; }
	Rover* getRover() { return roverAssign; }

	//SET
	void setType(TYPE Rovertype) { this->Type = Type; }
	void setFD(int FD) { this->FD = FD; }
	void setTargetLoc(int TargetLoc) { this->TargetLoc = TargetLoc; }
	void setduration(int duration) { this->duration = duration; }
	void getSign(int Sign) { this->Sign = Sign; }
	void setRover(Rover* roverAssign) { this-> roverAssign = roverAssign; }
};

