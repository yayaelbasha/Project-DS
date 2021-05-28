#ifndef C_UI
#define C_UI

#include "Formulation.h"
#include "LinkedQueue.h"


// template <typename T>
class UIclass
{
public:
	/*int numRovP;
	int numRovE;

	int speedRovP;
	int speedRovE;
	
	int numCheckup; 

	int checkupDurP;
	int checkupDurE;

	int AutoP;
	int eventsNum;*/

	/*int * eventsMisType = new int [eventsNum];
	int * eventsED = new int [eventsNum];
	int * eventsID = new int [eventsNum];
	int * eventsTLOC = new int [eventsNum];
	int * eventsMDUR = new int [eventsNum];
	int * eventsSIG = new int [eventsNum];*/


public:
	UIclass();
	
	void InputFile(int& numRovP, int& numRovE, int& speedRovP, int& speedRovE, int& numCheckup, int& checkupDurP, int& checkupDurE, int& eventsNum, LinkedQueue<Formulation*>& Events);
	void OutputFile(int CD, int ID, int FD, int WD, int ED);
};


#endif