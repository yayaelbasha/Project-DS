#include "station.h"

// Constructor
station::station() {
	// Day start from 0
	Day = 0; 
}


// Load input file and extract information from it
void station::Load() {
	int numRovP;
	int numRovE;

	int speedRovP;
	int speedRovE;

	int numCheckup;

	int checkupDurP;
	int checkupDurE;

	int AutoP;
	int eventsNum;

	// Load Input File
	UI.InputFile(numRovP, numRovE, speedRovP, speedRovE, numCheckup, checkupDurP, checkupDurE, Events);

	for (int i = 0; i < numRovE; i++)
	{
		Rover* R = new Rover(Emergency, checkupDurE, speedRovE, numCheckup);
		AvailRovE.enqueue(R);
	}

	for (int i = 0; i < numRovP; i++)
	{
		Rover* R = new Rover(Polar, checkupDurP, speedRovP, numCheckup);
		AvailRovP.enqueue(R);
	}
}


// Execute the mission and rovers 
void station::Execute() {

	Formulation* F;
	Mission* M;
	Rover* R;

	while (Events.peek(F) && F->getED() == Day)
	{
		if (F->getMissionType() == Polar)
			WaitMissionsP.enqueue(F->Execute());
		else if (F->getMissionType() == Emergency)
			WaitMissionsE.enqueueDesc(F->Execute(), F->Execute()->getSign());

		Events.dequeue(F);
	}

	if (!AvailRovE.isEmpty() || !AvailRovP.isEmpty())
	{
		while (WaitMissionsE.dequeue(M))
		{
			if (!AvailRovE.isEmpty())
			{
				AvailRovE.dequeue(R);
				M->setRover(R);
				R->SetMission(M);
				M->setWD(Day - M->getFD());

				InExMissions.enqueueAsc(M, M->getCD());
				InExRov.enqueueAsc(R, M->getCD());
			}
			else if (!AvailRovP.isEmpty())
			{
				AvailRovP.dequeue(R);

				M->setRover(R);
				R->SetMission(M);

				M->setWD(Day - M->getFD());

				InExMissions.enqueueAsc(M, M->getCD());
				InExRov.enqueueAsc(R, M->getCD());
			}
		}

		while (WaitMissionsP.peek(M) && !AvailRovP.isEmpty())
		{
			AvailRovP.dequeue(R);
			WaitMissionsP.dequeue(M);

			M->setRover(R);
			R->SetMission(M);

			M->setWD(Day - M->getFD());

			InExMissions.enqueueAsc(M, M->getCD());
			InExRov.enqueueAsc(R, M->getCD());

		}
	}

	while (InExMissions.peek(M) && M->getCD() == Day)
	{
		CompletedMissions.enqueue(M);
		InExMissions.dequeue(M);
		InExRov.dequeue(R);

		if (R->getMissionsDone() == R->getMissionLimit())
		{
			R->setMissionsDone(0);
			R->setReleaseDay(Day);
			InCheckRov.enqueue(R);
		}
		else {
			if (R->getRovertype() == Emergency)
			{
				AvailRovE.enqueue(R);
			}
			else {
				AvailRovP.enqueue(R);
			}
		}
	}

	while (InCheckRov.peek(R) && R->getReleaseDay() == Day)
	{
		InCheckRov.dequeue(R);
		if (R->getRovertype() == Emergency)
		{
			AvailRovE.enqueue(R);
		}
		else {
			AvailRovP.enqueue(R);
		}
	}
	Day++;
}


// Control the station 
void station::Control() {

	int mode = UI.start();

	switch (mode) {
	case 1:


		do
		{
			Execute();
			if (Day - 1 != 0)
			{
				UI.OutputScreen(Day - 1, WaitMissionsP, WaitMissionsE, InExMissions, AvailRovP, AvailRovE, InCheckRov, CompletedMissions);
				system("pause");
			}

		} while (!WaitMissionsP.isEmpty() || !WaitMissionsE.isEmpty() || !InExMissions.isEmpty() || !InCheckRov.isEmpty() || !Events.isEmpty());
		break;

	case 2:
		do
		{
			Execute();
			if (Day - 1 != 0)
			{
				UI.OutputScreen(Day - 1, WaitMissionsP, WaitMissionsE, InExMissions, AvailRovP, AvailRovE, InCheckRov, CompletedMissions);
				Sleep(1000);
			}
		} while (!WaitMissionsP.isEmpty() || !WaitMissionsE.isEmpty() || !InExMissions.isEmpty() || !InCheckRov.isEmpty() || !Events.isEmpty());

		break;
	case 3:
		do
		{
			Execute();
		} while (!WaitMissionsP.isEmpty() || !WaitMissionsE.isEmpty() || !InExMissions.isEmpty() || !Events.isEmpty());

	default:
		break;
	}

	UI.OutputFile(CompletedMissions, AvailRovP.size(), AvailRovE.size());

}


