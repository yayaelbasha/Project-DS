#ifndef Rover_H
#define Rover_H

#include "Defs.H"


template <typename T>
class Rover
{
private:
	TYPE Rovertype;
	int checkDur;
	T speed;

public:
	// Set And Get for Data members
	TYPE getRovertype() {return Rovertype;}
	int getcheckDur() { return checkDur; }
	T getspeed() { return speed; }

	void setRovertype(TYPE Rovertype) { this->Rovertype = Rovertype; }
	void setcheckDur(int checkDur) { this->checkDur = checkDur; }
	void setspeed(T speed) {this->speed = speed;}

};

#endif