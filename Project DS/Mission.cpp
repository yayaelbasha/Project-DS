#include "Mission.h"
#include "Rover.h"



Mission::Mission() {

}

Mission::Mission(int id, TYPE Type, int FD, int TargetLoc, int duration, int Sign, Rover* roverAssign) {
	this->id = id;
	this->Type = Type;
	this->FD = FD;
	this->TargetLoc = TargetLoc;
	this->duration = duration;
	this->Sign = Sign;
	this->roverAssign = roverAssign;
	WD = 0;
}

/// Set and Get for Data members

//GET
TYPE Mission::getType() { return Type; }
int Mission::getID() { return id; }
int Mission::getFD() { return FD; }
int Mission::getTargetLoc() { return TargetLoc; }
int Mission::getduration() { return duration; }
int Mission::getSign() { return Sign; }
Rover* Mission::getRover() { return roverAssign; }
int Mission::getCD() {
	calcED();
	calcCD();
	return CD;
}
int Mission::getWD() { return WD; }
int Mission::getED() {
	calcED();
	return ED;
}

//SET
void Mission::setType(TYPE Rovertype) { this->Type = Type; }
void Mission::setFD(int FD) { this->FD = FD; }
void Mission::setTargetLoc(int TargetLoc) { this->TargetLoc = TargetLoc; }
void Mission::setduration(int duration) { this->duration = duration; }
void Mission::setSign(int Signif) {
	if (Type == Emergency)
		Sign = 10000 * (Signif * Signif) / (TargetLoc * duration * FD) ;
	else
		Sign = Signif;
}
void Mission::setRover(Rover* roverAssign) { this->roverAssign = roverAssign; }
void Mission::setCD(int CD) { this->CD = CD; }
void Mission::setWD(int WD) { this->WD = WD; }
void Mission::setED(int ED) { this->ED = ED; }


void Mission::calcED() {
	ED = duration + ceil(((float)2 * TargetLoc / roverAssign->getspeed()) / 25);
}

void Mission::calcCD() {
	CD = FD + ED + WD;
}