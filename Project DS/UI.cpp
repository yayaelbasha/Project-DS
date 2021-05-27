#include "UI.h"

#include <iostream>
#include <fstream>

using namespace std;


template < typename T>
void UIclass<T>::read(T& Element)
{
	Cin >> Element;
}

template < typename T>
void UIclass<T>::print(T Element)
{
	cout << Element;
}

template < typename T>
void UIclass<T>::InputFile()
{
	ifstream inputFile("input.txt", ios::in);

	InputFile >> numRovE >> numRovP;
	InputFile >> speedRovE >> speedRovP;
	InputFile >> numCheckup >> checkupDurE >> checkupDurP;
	InputFile >> AutoP >> eventsNum;

	for (int i = 0; i < eventsNum; i++)
	{
		char eventType;
		if (InputFile >> eventType, eventType == 'F')
		{
			InputFile >> eventsMisType[i] >> eventsED[i] >> eventsID[i] >> eventsTLOC[i] >> eventsMDUR[i] >> eventsSIG[i] ;
		}
	}


}

template < typename T>
void UIclass<T>::OutputFile()
{
	ofstream outputFile("output.txt", ios::out);

}