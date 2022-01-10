#include "VaccineReservation.h"

int main()
{

	User user[MAX];

	while (true) {

		int answer;
		int num = 0;

		cout << "COVID-19 3차 백신 접종 예약 프로그램" << endl;
		cout << "1. 접종 예약 2. 예약 내역 조회 (숫자로 선택)" << endl;
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