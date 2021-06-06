#ifndef EVENT_H
#define EVENT_H

#include "Mission.h"
#include "LinkedPriQueue.h"
#include "LinkedQueue.h"

class event
{

protected:
	TYPE missionType;
	int ED;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;

public:

	virtual void setMissionType(char MT) = 0;
	virtual void setED(int ED) = 0;
	virtual void setID(int ID) = 0;
	virtual void setTLOC(int TLOC) = 0;
	virtual void setMDUR(int MDUR) = 0;
	virtual void setSIG(int SIG) = 0;

	virtual TYPE getMissionType() = 0;
	virtual int getED() = 0;
	virtual int getID() = 0;
	virtual int getTLOC() = 0;
	virtual int getMDUR() = 0;
	virtual int getSIG() = 0;

	virtual Mission* Execute(LinkedQueue<Mission*> & WaitMissionsP, LinkedPriQueue<Mission*> & WaitMissionsE) = 0;

	virtual ~event();
};

#endif
