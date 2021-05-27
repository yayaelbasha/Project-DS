#include "UI.h"

#include <iostream>
#include <fstream>

#include "Formulation.h"
#include "LinkedQueue.h"

using namespace std;

//template < typename T>
//void UIclass<T>::read(T& Element)
//{
//	cin >> Element;
//}
//
//template < typename T>
//void UIclass<T>::print(T Element)
//{
//	cout << Element;
//}
//
//template < typename T>

UIclass::UIclass() {}

void UIclass::InputFile(int& numRovP, int& numRovE, int& speedRovP, int& speedRovE, int& numCheckup, int& checkupDurP, int& checkupDurE, int& AutoP, int& eventsNum, LinkedQueue<Formulation*>& Events)
{
	char missionType;
	int ED;
	int Id;
	int TLOC;
	int MDUR;
	int SIG;


	ifstream inputFile("input.txt", ios::in);

	if (inputFile.is_open())
	{
		inputFile >> numRovE >> numRovP;
		inputFile >> speedRovE >> speedRovP;
		inputFile >> numCheckup >> checkupDurE >> checkupDurP;
		inputFile >> AutoP >> eventsNum;

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
				F->setMDUR(SIG);
				Events.enqueue(F);
			}
		}
	}
	else {
		cout << "File is not found ...";
	}

	inputFile.close();
}

void UIclass::OutputFile()
{
	ofstream outputFile("output.txt", ios::out);

}