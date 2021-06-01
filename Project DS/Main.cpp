#include "station.h"


// Project [Mars Exploration] //

/*
 Cairo University
 Faculty of Engineering
 Computer Engineering Department
 Spring 2021
 CMPN 102
*/

// Main File which the program run in it
int main()
{

	//Create an object of station
	station marsStation;

	//Read Input File
	marsStation.Load();

	//Control station
	marsStation.Control();
	
	return 0;
}