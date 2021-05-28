#pragma once

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
	LinkedQueue<Mission*> WaitMissionsP;
	LinkedPriQueue<Mission*> WaitMissionsE;

	LinkedPriQueue<Mission*> InExMissions;

	LinkedQueue<Rover*> AvailRovP;
	LinkedQueue<Rover*> AvailRovE;

	LinkedQueue<Rover*> InCheckRov;
	LinkedQueue<Mission*> CompletedMissions;

	LinkedPriQueue<Rover*> InExRov;

	UIclass UI;

public:
	station() {};

	/*void read() {

		int MOU, EME, POL;

		ifstream inputFile;
		inputFile.open("x.txt");
		inputFile >> MOU >> EME >> POL;
	}
	
	void write() {
		ofstream outputFile;
		outputFile.open("z.txt");
		outputFile << 12 << " " << 13 << " " << 14 << " ";
	}*/
	
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

		UI.InputFile(numRovP,numRovE, speedRovP, speedRovE, numCheckup, checkupDurP, checkupDurE, eventsNum, Events);

		for (int i = 0; i < numRovE; i++)
		{
			Rover* R = new Rover(Emergency, checkupDurE, speedRovE, numCheckup);
			AvailRovE.enqueue(R);
		}

		for (int i = 0; i < numRovP; i++)
		{
			Rover* R = new Rover(Polar,checkupDurP,speedRovP, numCheckup);
			AvailRovP.enqueue(R);
		}
		int Day = 1;
		do
		{
			Formulation* F;
			Mission* M;
			Rover* R;

			Events.peek(F);
			if (F->getED() == Day)
			{
				if (F->getMissionType()==Polar) WaitMissionsP.enqueue(F->Execute());
				else if (F->getMissionType() == Emergency) WaitMissionsE.enqueue(F->Execute());
				Events.dequeue(F);
			}

			if (WaitMissionsE.dequeue(M))
			{
				if (!AvailRovE.isEmpty())
				{
					AvailRovE.dequeue(R);
					M->setRover(R);

					InExMissions.enqueue(M);
					InExRov.enqueue(R);
				}
				else
				{
					AvailRovP.dequeue(R);
					M->setRover(R);

					InExMissions.enqueue(M);
					InExRov.enqueue(R);
				}
			}
			else
			{
				if (!AvailRovP.isEmpty())
				{
					if (WaitMissionsP.dequeue(M)) {
						AvailRovP.dequeue(R);
						M->setRover(R);

						InExMissions.enqueue(M);
						InExRov.enqueue(R);
					}
				}
			}

			Day++;
		} while (!WaitMissionsP.isEmpty() && !WaitMissionsE.isEmpty() && !InExMissions.isEmpty() && !Events.isEmpty());
	}
};


