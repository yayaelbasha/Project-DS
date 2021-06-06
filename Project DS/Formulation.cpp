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

TYPE Formulation::getMissionType() {
	return missionType;
}

int Formulation::getED() {
	return ED;
}
int Formulation::getID() {
	return ID;
}
int Formulation::getTLOC() {
	return TLOC;
}
int Formulation::getMDUR() {
	return MDUR;
}
int Formulation::getSIG() {
	return SIG;
}

Mission* Formulation::Execute(LinkedQueue<Mission*>& WaitMissionsP, LinkedPriQueue<Mission*>& WaitMissionsE) {

	Mission* mission = new Mission(ID, missionType, ED, TLOC, MDUR, SIG);
	mission->setSign(SIG);

	if (this->getMissionType() == Polar)
		WaitMissionsP.enqueue(mission);
	else if (this->getMissionType() == Emergency)
		WaitMissionsE.enqueueDesc(mission, mission->getSign());

	return mission;
}

Formulation::~Formulation() {

}


