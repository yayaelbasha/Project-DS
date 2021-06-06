#include "station.h"


// Project [Mars Exploration] //

/*
 Cairo University
 Faculty of Engineering
 Computer Engineering Department
 Spring 2021
 CMPN 102

Names :
 Yahia Ahmed Hatem Mostafa Mahmoud	1190445
 Ismael Tawfik Ismael Ahmed			1190264
 Mohamed Ahmed Abdullah Mahmoud		1190388
 Mohamed Wael Abdelfatah Mohamed	1190279
*/


// Main File which the program run in it
int main(){

	//Create an object of station
	station marsStation;


	//Read Input File
	marsStation.Load();


	//Control station
	marsStation.Control();	


	return 0;

}