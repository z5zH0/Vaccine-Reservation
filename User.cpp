#include "VaccineReservation.h"

User::User() {}

User::~User() {}

void User::confirm() const
{
	cout << endl << "[예약자 정보]" << endl;
	cout << "이름: " << name << endl;
	cout << "주민번호: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
	cout << endl << "입력하신 정보가 맞습니까?" << endl;
	cout << "1. 예 2. 아니오 (숫자로 입력)" << endl;
}

void User::getName() const {
	cout << "이름: " << name << endl;
}

void User::getId() const {
	cout << "주민번호: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
}

void User::setInfo() {

	string name;
	long id;
	bool SV = false;
	int input;

	cout << endl << "COVID-19 3차 백신 접종일자 예약" << endl;
	cout << endl << "예약자의 이름을 입력하세요." << endl;
	cin >> name;
	setName(name);
	cout << endl << "예약자의 주민번호 앞자리를 입력하세요." << endl;
	cin >> birth;
	cout << endl << "예약자의 주민번호 뒷자리를 입력하세요." << endl;
	cin >> code;
	setId(birth, code);
	cout << endl << "예약자의 2차 백신 접종 여부를 입력하세요." << endl;
	cout << "1. 접종 완료 2. 미접종 (숫자로 입력)" << endl;
	cin >> input;
	if (input == 1) {
		SV = true;
	}
	setSV(SV);
}

void User::setName(string n) {
	name = n;
}

void User::setId(int b, int c) {
	birth = b;
	code = c;
}

void User::setSV(bool SV) {
	if (SV == false) {
		cout << "2차 백신 접종을 완료해야 3차 백신 접종 예약이 가능합니다." << endl;
		assert(false);
	}
	else SecondVaccinated = SV;
}