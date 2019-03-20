﻿/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.2
*/
#include"Country.h"
#include"CountryArr.h"


int main() {

	CountryArr country;
	Country Max;

	int i = 1;
	country.getSize(i);

	char** name = new char*[i];
	for (int j = 0; j < i; j++) {
		name[j] = new char[24];
	}
	for (int j = 0; j < i; j++) {
		std::cout << "Enter name:  ";
		std::cin >> name[j];
	}
	country.newArray(name);
	country.addElem(232142, 53423, 654321, (char*)"Ukraine");
	country.addElem(32142, 5323, 23321, (char*)"Poland");
	country.addElem(2422, 523423, 5654321, (char*)"Japan");
	country.deleteElem(1);
	country.getByIndex(1);
	country.print();
	Max = country.maxPop();
	country.deleteArray();
	country.printMax(Max);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	return 0;
}