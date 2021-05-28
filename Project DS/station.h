#pragma once

#include "LinkedQueue.h"
#include "LinkedPriQueue.h"
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

		// Load Input File
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
			
			while (Events.peek(F) && F->getED() == Day)
			{
				if (F->getMissionType()==Polar) 
					WaitMissionsP.enqueue(F->Execute());
				else if (F->getMissionType() == Emergency)
					WaitMissionsE.enqueueDesc(F->Execute(), F->Execute()->getSign());
				Events.dequeue(F);
			}

			if (WaitMissionsE.dequeue(M))
			{
				if (!AvailRovE.isEmpty())
				{
					AvailRovE.dequeue(R);
					M->setRover(R);
					R->SetMission(M);
					M->setWD(Day - M->getFD());

					InExMissions.enqueueAsc(M,M->getCD());
					InExRov.enqueueAsc(R, M->getCD());
				}
				else
				{
					AvailRovP.dequeue(R);
					
					M->setRover(R);
					R->SetMission(M);

					M->setWD(Day - M->getFD());

					InExMissions.enqueueAsc(M,M->getCD());
					InExRov.enqueueAsc(R, M->getCD());
				}
			}
			else
			{
				if (!AvailRovP.isEmpty())
				{
					if (WaitMissionsP.dequeue(M)) {
						AvailRovP.dequeue(R);

						M->setRover(R);
						R->SetMission(M);

						M->setWD(Day - M->getFD());

						InExMissions.enqueueAsc(M, M->getCD());
						InExRov.enqueueAsc(R, M->getCD());
					}
				}
			}

			Day++;
		
		} while (!WaitMissionsP.isEmpty() && !WaitMissionsE.isEmpty() && !InExMissions.isEmpty() && !Events.isEmpty());
		
		// Save Output File
		UI.OutputFile(CompletedMissions, AvailRovP.size(),AvailRovE.size());
	}
};


