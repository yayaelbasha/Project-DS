#pragma once

#include "Mission.h"
#include "Defs.H"
#include "Rover.h"
#include <cmath>

class Rover;

class Mission{

private:
	int id;
	TYPE Type;
	int TargetLoc;
	int duration;
	int Sign;
	Rover* roverAssign;

	int FD;
	int WD;
	int ED;
	int CD;

	void calcED();
	void calcCD();

public:
	Mission();
	Mission(int id, TYPE Type, int FD, int TargetLoc, int duration, int Sign, Rover* roverAssign = nullptr);


	/// Set and Get for Data members
	//GET
	TYPE getType();
	int getID();
	int getFD();
	int getTargetLoc();
	int getduration();
	int getSign();
	Rover* getRover();
	int getCD();
	int getWD();
	int getED();

	//SET
	void setType(TYPE Rovertype);
	void setFD(int FD);
	void setTargetLoc(int TargetLoc);
	void setduration(int duration);
	void setSign(int Sign);
	void setRover(Rover* roverAssign);
	void setCD(int CD);
	void setWD(int WD);
	void setED(int ED);
};

