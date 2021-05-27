#ifndef C_UI
#define C_UI


template <typename T>
class UIclass
{
public:
	int numRovP;
	int numRovE;

	int speedRovP;
	int speedRovE;
	
	int numCheckup; 

	int checkupDurP;
	int checkupDurE;

	int AutoP;
	int eventsNum;

	int eventsMisType[eventsNum];
	int eventsED[eventsNum];
	int eventsID[eventsNum];
	int eventsTLOC[eventsNum];
	int eventsMDUR[eventsNum];
	int eventsSIG[eventsNum];


public:
	UIclass();
	
	void read(T& Element);
	void print(T Element);

	void InputFile();
	void OutputFile();
};


#endif