#ifndef EVENT_H
#define EVENT_H

class station;

class event
{
protected:
	station* pStation;	

public:
	event(station* pStation) {
		this->pStation = pStation; 
	}

	virtual void Execute() = 0;
};

#endif
