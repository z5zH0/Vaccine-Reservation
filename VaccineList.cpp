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
	cout << "������ ����� �����ϼ���." << endl << endl;
	cout << "���� �ܿ� ����" << endl;
	cout << "�����: " << countModerna() << endl;
	cout << "ȭ����: " << countPfizer() << endl;
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
		if (vaccines[i].Vsort == "�����") count++;
	}
	return count;
}

int VaccineList::countPfizer() const
{
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		if (vaccines[i].Vsort == "ȭ����") count++;
	}
	return count;
}