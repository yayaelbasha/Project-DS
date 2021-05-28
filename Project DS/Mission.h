#pragma once

#include "Mission.h"
#include "Defs.H"
#include "Rover.h"
#include <cmath>

class Mission{

private:
	int id;
	TYPE Type;
	int FD;
	int TargetLoc;
	int duration;
	int Sign;
	int WD;
	int ED;
	int CD;
	Rover* roverAssign;

	void calcED() {
		ED = duration + 2 * ceil((TargetLoc / roverAssign->getspeed()) / 25);
	}
	void calcCD() {
		CD = FD + ED + WD;
	}

public:
	Mission(){}
	Mission(int id, TYPE Type, int FD, int TargetLoc, int duration, int Sign, Rover* roverAssign = nullptr) {
		this->id = id;
		this->Type = Type;
		this->FD = FD;
		this->TargetLoc = TargetLoc;
		this->duration = duration;
		this->Sign = Sign;
		WD = 0;
	}

	/// Set and Get for Data members

	//GET
	TYPE getType() { return Type; }
	int getFD() { return FD; }
	int getTargetLoc() { return TargetLoc; }
	int getduration() { return duration; }
	int getSign() { return Sign; }
	Rover* getRover() { return roverAssign; }
	int getCD() {
		calcED();
		calcCD();
		return CD; 
	}
	int getWD() { return WD; }
	int getED() { 
		calcED();
		return ED; 
	}

	//SET
	void setType(TYPE Rovertype) { this->Type = Type; }
	void setFD(int FD) { this->FD = FD; }
	void setTargetLoc(int TargetLoc) { this->TargetLoc = TargetLoc; }
	void setduration(int duration) { this->duration = duration; }
	void setSign(int Sign) { this->Sign = Sign; }
	void setRover(Rover* roverAssign) { this-> roverAssign = roverAssign; }
	void setCD(int CD) { this->CD = CD; }
	void setWD(int WD) { this->WD = WD; }
	void setED(int ED) { this->ED = ED; }
};

