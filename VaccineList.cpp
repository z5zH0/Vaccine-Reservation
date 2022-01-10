#include "VaccineReservation.h"

VaccineList::VaccineList(const char* ifn)
	:inputFileName(ifn)
{
	inputFile.open(inputFileName);
	vaccines = new Vaccine[MAX];
	getInput();
	cout << endl;
	print();
	cout << endl;
	cout << "예약할 백신을 선택하세요." << endl << endl;
	cout << "현재 잔여 수량" << endl;
	cout << "모더나: " << countModerna() << endl;
	cout << "화이자: " << countPfizer() << endl;
}

VaccineList::~VaccineList()
{
	delete[] vaccines;
	inputFile.close();
}

void VaccineList::getInput()
{
	for (int i = 0; i < MAX; i++) {
		inputFile >> vaccines[i].institution;
		inputFile >> vaccines[i].Vsort; 
		inputFile >> vaccines[i].date;
		inputFile >> vaccines[i].time;
	}
}

void VaccineList::print() const
{
	for (int i = 0; i < 5; i++) {
		cout << vaccines[i].institution << " ";
		cout << vaccines[i].Vsort << " ";
		cout << vaccines[i].date << " ";
		cout << vaccines[i].time << " ";
		cout << endl;
	}
}

int VaccineList::countModerna() const
{
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		if (vaccines[i].Vsort == "모더나") count++;
	}
	return count;
}

int VaccineList::countPfizer() const
{
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		if (vaccines[i].Vsort == "화이자") count++;
	}
	return count;
}