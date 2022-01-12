#include "VaccineReservation.h"

User::User()
	:name(""), birth(0), code(0), SecondVaccinated(false) {}

User::~User() {}

void User::confirm() const //사용자로부터 입력받은 내용 확인
{
	cout << endl << "[예약자 정보]" << endl;
	cout << "이름: " << name << endl;
	cout << "주민번호: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
	cout << endl << "입력하신 정보가 맞습니까?" << endl;
	cout << "1. 예 2. 아니오 (숫자로 입력)" << endl;
}

string User::getName() const { //이름 접근자
	return name;
}

int User::getId() const { //주민번호 접근자 (생년월일만 출력)
	return birth;
}

void User::setInfo() { //이름 + 주민번호 사용자로부터 입력받아 설정

	int input;
	bool SV = false;

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

void User::setName(string n) { //이름 설정자
	name = n;
}

void User::setId(int b, int c) { //주민번호 설정자
	birth = b;
	code = c;
}

void User::setSV(bool SV) { //2차 백신 접종이 완료되지 않으면 메시지를 띄운 후 프로그램 종료
	if (SV == false) {
		cout << "2차 백신 접종을 완료해야 3차 백신 접종 예약이 가능합니다." << endl;
		assert(false);
	}
	else SecondVaccinated = SV;
}