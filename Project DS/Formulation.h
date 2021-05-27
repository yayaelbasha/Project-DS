#ifndef Formulation_H
#define Formulation_H

#include "event.h"
#include "Defs.H"

class Formulation : public event {

private:
	TYPE missionType;
	int ED;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;

public:
	Formulation();

	void setMissionType(char MT);
	void setED(int ED);
	void setID(int ID);
	void setTLOC(int TLOC);
	void setMDUR(int MDUR);
	void setSIG(int SIG);


	virtual void Execute();
	
	~Formulation();

};

#endif