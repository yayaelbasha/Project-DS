#ifndef C_UI
#define C_UI

#include "Formulation.h"
#include "LinkedQueue.h"
#include "LinkedPriQueue.h"


// template <typename T>
class UIclass
{
public:
	
public:
	UIclass();
	int start();
	void InputFile(int& numRovP, int& numRovE, int& speedRovP, int& speedRovE, int& numCheckup, int& checkupDurP, int& checkupDurE, int& eventsNum, LinkedQueue<Formulation*>& Events);
	void OutputFile(LinkedQueue<Mission*> CompletedMissions, int RovP, int RovE);
	void OutputScreen(LinkedQueue<Mission*> WaitMissionsP, LinkedPriQueue<Mission*> WaitMissionsE,LinkedPriQueue<Mission*> InExMissions,LinkedQueue<Rover*> AvailRovP,LinkedQueue<Rover*> AvailRovE,LinkedQueue<Rover*> InCheckRov,LinkedQueue<Mission*> CompletedMissions);

};


#endif