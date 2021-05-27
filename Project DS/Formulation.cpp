#include "Formulation.h"

Formulation::Formulation() {
}

void Formulation::setMissionType(char MT) {
	
	if (MT == 'E')
	{
		missionType = Emergency;
	}
	else if (MT == 'P')
	{
		missionType = Polar;
	}

}

void Formulation::setED(int ED) {
	this->ED = ED;
}

void Formulation::setID(int ID){
	this->ID = ID;
}

void Formulation::setTLOC(int TLOC){
	this->TLOC = TLOC;
}

void Formulation::setMDUR(int MDUR){
	this->MDUR = MDUR;
}

void Formulation::setSIG(int SIG) {
	this->SIG = SIG;
}

void Formulation::Execute() {

}
