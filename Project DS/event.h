#ifndef EVENT_H
#define EVENT_H

#include "Mission.h"

class event
{
public:
	event();
	virtual Mission* Execute() = 0;
};

#endif
