#pragma once
#include "event.h"
#include "Mission.h"
#include "Defs.H"

class Formulation {

private:
	TYPE missionType;
	int ED;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;

public:
	Formulation();

	void setMissionType(char MT) ;
	void setED(int ED) ;
	void setID(int ID) ;
	void setTLOC(int TLOC) ;
	void setMDUR(int MDUR) ;
	void setSIG(int SIG);

	TYPE getMissionType();
	int getED() ;
	int getID() ;
	int getTLOC();
	int getMDUR();
	int getSIG() ;

	Mission* Execute(LinkedQueue<Mission*>& WaitMissionsP, LinkedPriQueue<Mission*>& WaitMissionsE);

	~Formulation();
};

