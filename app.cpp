#include "VaccineReservation.h"

int main()
{
	User users[MAX];
	Vaccine vaccines[MAX];
	int numsOfVaccines = 0;
	int numsOfModerna = 0;
	int numsOfPfizer = 0;		
	int& numV = numsOfVaccines;
	int& numM = numsOfModerna;
	int& numP = numsOfPfizer;
	getFileAndSetInfo(vaccines, numV);

	while (true) {

		int answer;
		int i = 0;

		cout << "COVID-19 3�� ��� ���� ���� ���α׷�" << endl;
		cout << "1. ���� ���� 2. ���� ���� ��ȸ (���ڷ� ����)" << endl;
		cin >> answer;

		switch (answer) {
		case 1:
			do {
				users[i].setInfo();
				users[i].confirm();
				cin >> answer;
			} while (answer != 1);
			chooseVaccine(vaccines, numV, numM, numP);

			break;
		}


	}

	return 0;
}