#pragma once

#include "Defs.H"

template <typename T>
class Mission{

private:
	int id;
	TYPE Rovertype;
	int FD;
	T TargetLoc;
	T duration;
	int Sign;

public:
	Mission(){}
	Mission(int id, TYPE Rovertype, int FD, T TargetLoc, T duration, int Sign) {
		this->id = id;
		this->Rovertype = Rovertype;
		this->FD = FD;
		this->TargetLoc = TargetLoc;
		this->duration = duration;
		this->Sign = Sign;
	}

	/// Set and Get for Data members

	//GET
	TYPE getRovertype() { return Rovertype; }
	int getFD() { return FD; }
	T getTargetLoc() { return TargetLoc; }
	T getduration() { return duration; }
	int getSign() { return Sign; }

	//SET
	void setRovertype(TYPE Rovertype) { this->Rovertype = Rovertype; }
	void setFD(int FD) { this->FD = FD; }
	void setTargetLoc(T TargetLoc) { this->TargetLoc = TargetLoc; }
	void setduration(T duration) { this->duration = duration; }
	void getSign(int Sign) { this->Sign = Sign; }
};

