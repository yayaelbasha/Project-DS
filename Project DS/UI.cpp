#include "UI.h"
#include <windows.h>
#include <iostream>
#include <fstream>

#include "Formulation.h"
#include "LinkedQueue.h"
#include "LinkedPriQueue.h"

using namespace std;

//void UIclass::read(string Element)
//{
//	cin >> Element;
//}
//
//void UIclass::print(string Element)
//{
//	cout << Element;
//}


UIclass::UIclass() {}

int UIclass::start() {
	cout << "Mars Exploration" << endl << endl;
	Sleep(300);
	cout << "1 - Interactive Mode" << endl;
	cout << "2 - Step-By-Step Mode" << endl;
	cout << "3 - Silent Mode" << endl;
	cout << "Please, select the Program mode (Enter the number of mode) : ";

	int mode;
	cin >> mode;

	cout << endl;

	switch (mode){
	case 1: 
		cout << "Interactive Mode" << endl; 
		break;
	case 2: 
		cout << "Step-By-Step Mode" << endl;
		Sleep(10);
		break;
	case 3: 
		cout << "Silent Mode" << endl; 
		Sleep(500);
		cout << "Simulation Starts";
		for (int i = 0; i < 3; i++)
		{
			Sleep(300);
			cout << ".";
		}
		cout << endl; 
		cout << "Simulation ends, Output file created" << endl;
		break;
	default: 
		break;
	}

	return mode;
}

void UIclass::InputFile(int& numRovP, int& numRovE, int& speedRovP, int& speedRovE, int& numCheckup, int& checkupDurP, int& checkupDurE, LinkedQueue<Formulation*>& Events)
{
	char missionType;
	int ED = 0;
	int Id = 0;
	int TLOC = 0;
	int MDUR = 0;
	int SIG = 0;
	int eventsNum;


	ifstream inputFile("input.txt", ios::in);

	if (inputFile.is_open())
	{
		inputFile >> numRovE >> numRovP;
		inputFile >> speedRovE >> speedRovP;
		inputFile >> numCheckup >> checkupDurE >> checkupDurP;
		inputFile >> eventsNum;

		for (int i = 0; i < eventsNum; i++)
		{
			char eventType;
			if (inputFile >> eventType, eventType == 'F')
			{
				Formulation* F = new Formulation;
				inputFile >> missionType;

				inputFile >> ED >> Id >> TLOC >> MDUR >> SIG;
				F->setMissionType(missionType);
				F->setED(ED);
				F->setID(Id);
				F->setTLOC(TLOC);
				F->setMDUR(MDUR);
				F->setSIG(SIG);
				Events.enqueue(F);
			}
		}
	}
	else {
		cout << "File is not found ...";
	}

	inputFile.close();
}

void UIclass::OutputFile(LinkedQueue<Mission*> CompletedMissions, int RovP, int RovE)
{
	float AvgExec = 0;
	float AvgWait = 0;

	int MissionP = 0;
	int MissionE = 0;

	int Compsize = 0;

	ofstream outputFile("output.txt", ios::out);

	outputFile << "CD" << "\t" << "ID" << "\t" << "FD" << "\t" << "WD" << "\t" << "ED" << endl;

	Mission* M;
	while (CompletedMissions.dequeue(M))
	{
		if (M->getType() == Emergency) MissionE++;
		else MissionP++;

		outputFile << M->getCD() << "\t" << M->getID() << "\t" << M->getFD() << "\t" << M->getWD() << "\t" << M->getED() << endl;
		
		AvgExec += M->getED();
		AvgWait += M->getWD();
		Compsize++;
	}

	AvgExec = AvgExec / Compsize;
	AvgWait = AvgWait / Compsize;

	outputFile << "..................................." << endl << "..................................." << endl;

	outputFile << "Missions: " << MissionP + MissionE << " [P: " << MissionP << ", E: " << MissionE << "]" << endl;
	outputFile << "Rovers: " << RovP+RovE << " [P: " << RovP << ", E: " << RovE << "]" << endl;
	outputFile << "Avg Wait = " << AvgWait << ", Avg Exec = " << AvgExec << endl;
}

void UIclass::OutputScreen(int Day,LinkedQueue<Mission*> WaitMissionsP, LinkedPriQueue<Mission*> WaitMissionsE, LinkedPriQueue<Mission*> InExMissions, LinkedQueue<Rover*> AvailRovP, LinkedQueue<Rover*> AvailRovE, LinkedQueue<Rover*> InCheckRov, LinkedQueue<Mission*> CompletedMissions) {

	Mission* M;
	Rover* R;

	cout << endl;
	cout << "Current Day:" << Day << endl;
	
	int sizeWaitE = WaitMissionsE.size();
	int sizeWaitP = WaitMissionsP.size();
	cout << sizeWaitE + sizeWaitP << " Waiting Missions: ";

	cout << "[";
	for (int i = 0; i < sizeWaitE; i++)
	{
		WaitMissionsE.dequeue(M);
		if (i > 0 && i !=sizeWaitE)
		{
			cout << ", ";
		}
		if (M->getType() == Emergency)
		{
			cout << M->getID();
		}
	}
	cout << "] ";

	cout << "{";
	for (int i = 0; i < sizeWaitP; i++)
	{
		WaitMissionsP.dequeue(M);
		if (i > 0 && i !=sizeWaitP)
		{
			cout << ", ";
		}
		if (M->getType() == Polar)
		{
			cout << M->getID();
		}
	}
	cout << "}";

	cout << endl;

	cout << "------------------------------------------------------" << endl;
	int InExSize = InExMissions.size();
	cout << InExSize <<" In-Execution Missions/Rovers: ";

	cout << "[";
	for (int i = 0; i < InExSize; i++)
	{
		InExMissions.dequeue(M);
		if (M->getType() == Emergency)
		{
			if (i > 0 && i !=InExSize)
			{
				cout << ", ";
			}
			cout << M->getID() << "/" << M->getRover()->getId();
		}
		else
		{
			InExMissions.enqueueAsc(M,M->getCD());
		}
	}
	cout << "] ";

	cout << "{";
	int i = 0;
	while (InExMissions.dequeue(M))
	{
		if (i > 0)
		{
			cout << ", ";
		}
		cout << M->getID() << "/" << M->getRover()->getId();
		i++;
	}
	cout << "}";

	cout << endl;
	
	cout << "------------------------------------------------------" << endl;
	
	int sizeAvailE = AvailRovE.size();
	int sizeAvailP = AvailRovP.size();
	cout << sizeAvailE + sizeAvailP << " Available Rovers: ";

	cout << "[";
	for (int i = 0; i < sizeAvailE; i++)
	{
		if (AvailRovE.dequeue(R)) {
			if (i > 0 && i != sizeAvailE)
			{
				cout << ", ";
			}
			if (R->getRovertype() == Emergency)
			{
				cout << R->getId();
			}
		}
	}
	cout << "] ";

	cout << "{";
	for (int i = 0; i < sizeAvailP; i++)
	{
		if (AvailRovP.dequeue(R)) {
			if (i > 0 && i != sizeAvailP)
			{
				cout << ", ";
			}
			if (R->getRovertype() == Polar)
			{
				cout << R->getId();
			}
		}
	}
	cout << "}";
	cout << endl;
	
	cout << "------------------------------------------------------" << endl;
	
	int sizeCheckRov = InCheckRov.size();
	cout << sizeCheckRov << " In-Checkup Rovers: ";

	cout << "[";
	for (int i = 0; i < sizeCheckRov; i++)
	{
		InCheckRov.dequeue(R);
		if (R->getRovertype() == Emergency)
		{
			if (i > 0 && i !=sizeCheckRov)
			{
				cout << ", ";
			}
			cout << R->getId();
		}
		else
		{
			InCheckRov.enqueue(R);
		}
	}
	cout << "] ";

	cout << "{";
	i = 0;
	while (InCheckRov.dequeue(R))
	{
		if (i > 0)
		{
			cout << ", ";
		}
		cout << R->getId();
		i++;
	}
	cout << "}";

	cout << endl;
	
	cout << "------------------------------------------------------" << endl;

	int sizeComp = CompletedMissions.size();
	cout << sizeComp <<" Completed Missions: ";
	
	cout << "[";
	for (int i = 0; i < sizeComp; i++)
	{
		CompletedMissions.dequeue(M);
		if (M->getType() == Emergency)
		{
			if (i > 0 && i !=sizeComp)
			{
				cout << ", ";
			}
			cout << M->getID();
		}
		else
		{
			CompletedMissions.enqueue(M);
		}
	}
	cout << "] ";

	cout << "{";
	i = 0;
	while (CompletedMissions.dequeue(M))
	{
		if (i > 0)
		{
			cout << ", ";
		}
		cout << M->getID();
		i++;
	}
	cout << "}";

	cout << endl;
	
}


