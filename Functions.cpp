#include "VaccineReservation.h"

void getFileAndSetInfo(Vaccine v[], int& num)
{
	string i, s, d, t;

	ifstream inputFile;
	inputFile.open("list.txt");

	while (!inputFile.eof()) {
		inputFile >> i;
		inputFile >> s;
		inputFile >> d;
		inputFile >> t;
		v[num] = Vaccine(i, s, d, t);
		num++;
	}
}

void chooseVaccine(const Vaccine* v, int& size, int& moderna, int& pfizer)
{
	for (int i = 0; i < size; i++)
	{
		if ((v + i)->isModerna())
		{
			moderna++;
		}
		if ((v + i)->isPfizer())
		{
			pfizer++;
		}
	}

	cout << endl << "[종류별 현재 예약 가능한 백신 수]" << endl << endl;
	cout << "모더나: " << moderna << endl;
	cout << "화이자: " << pfizer << endl << endl;
	cout << "예약할 백신을 선택하세요. (숫자로 입력)" << endl;
	cout << "1. 모더나 2. 화이자" << endl;
	int input;
	cin >> input;

	if (input == 1) {
		if (moderna == 0)
		{
			cout << "선택하신 모더나 백신은 현재 예약 가능한 백신이 없습니다." << endl;
			assert(false);
		}
		cout << endl << "[현재 예약 가능한 모더나 백신 리스트]" << endl << endl;
		showModerna(v, size);
	}
	if (input == 2) {
		if (pfizer == 0)
		{
			cout << "선택하신 화이자 백신은 현재 예약 가능한 백신이 없습니다." << endl;
			assert(false);
		}
		cout << endl << "[현재 예약 가능한 화이자 백신 리스트]" << endl << endl;
		showPfizer(v, size);
	}
}

void showModerna(const Vaccine* v, int& size)
{
	int count = 1;

	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isModerna())
		{
			cout << "[" << count << "] ";
			(v + i)->print();
			count++;
		}
	}
}

void showPfizer(const Vaccine* v, int& size)
{
	int count = 1;

	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isPfizer())
		{
			cout << "[" << count << "] ";
			(v + i)->print();
			count++;
		}
	}
}