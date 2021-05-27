#ifndef STATION_H
#define STATION_H

#include "LinkedQueue.h"
#include "Mission.h"
#include "Rover.h"
#include "event.h"
#include "UI.h"
#include "Formulation.h"

#include <fstream>


class station
{
private:
	LinkedQueue<Mission<int>> WaitMissionsP;
	LinkedQueue<Mission<int>> WaitMissionsE;

	LinkedQueue<Mission<int>> InExMissionsE;
	LinkedQueue<Mission<int>> InExMissionsP;

	LinkedQueue<Mission<int>> AvailRov;

	LinkedQueue<Mission<int>> InCheckRov;
	LinkedQueue<Mission<int>> CompletedMissions;

	LinkedQueue<Mission<int>> InExRovE;
	LinkedQueue<Mission<int>> InExRovP;

	UIclass UI;

public:
	station();

	void read() {

		int MOU, EME, POL;

		ifstream inputFile;
		inputFile.open("x.txt");
		inputFile >> MOU >> EME >> POL;
	}
	
	void write() {
		ofstream outputFile;
		outputFile.open("z.txt");
		outputFile << 12 << " " << 13 << " " << 14 << " ";
	}
	
	void excute() {
		int numRovP;
		int numRovE;

		int speedRovP;
		int speedRovE;

		int numCheckup;

		int checkupDurP;
		int checkupDurE;

		int AutoP;
		int eventsNum;
		LinkedQueue<Formulation*> Events;

		UI.InputFile(numRovP,numRovE, speedRovP, speedRovE, numCheckup, checkupDurP, checkupDurE, AutoP, eventsNum,Events);

	}
};

#endif
