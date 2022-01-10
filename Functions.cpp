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

	cout << endl << "[������ ���� ���� ������ ��� ��]" << endl << endl;
	cout << "�����: " << moderna << endl;
	cout << "ȭ����: " << pfizer << endl << endl;
	cout << "������ ����� �����ϼ���. (���ڷ� �Է�)" << endl;
	cout << "1. ����� 2. ȭ����" << endl;
	int input;
	cin >> input;

	if (input == 1) {
		if (moderna == 0)
		{
			cout << "�����Ͻ� ����� ����� ���� ���� ������ ����� �����ϴ�." << endl;
			assert(false);
		}
		cout << endl << "[���� ���� ������ ����� ��� ����Ʈ]" << endl << endl;
		showModerna(v, size);
	}
	if (input == 2) {
		if (pfizer == 0)
		{
			cout << "�����Ͻ� ȭ���� ����� ���� ���� ������ ����� �����ϴ�." << endl;
			assert(false);
		}
		cout << endl << "[���� ���� ������ ȭ���� ��� ����Ʈ]" << endl << endl;
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