#include "VaccineReservation.h"

int main()
{

	User user[MAX];

	while (true) {

		int answer;
		int num = 0;

		cout << "COVID-19 3�� ��� ���� ���� ���α׷�" << endl;
		cout << "1. ���� ���� 2. ���� ���� ��ȸ (���ڷ� ����)" << endl;
		cin >> answer;

		switch (answer) {
		case 1:
			do {
				user[num].setInfo();
				user[num].confirm();
				cin >> answer;
			} while (answer != 1);

			VaccineList VL("list.txt");
			break;
		}


	}

	return 0;
}