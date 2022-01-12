#include "VaccineReservation.h"

Reservation::Reservation(){}

Reservation::Reservation(User u, Vaccine v)
	:user(u), vaccine(v){}

Reservation::~Reservation(){}

void Reservation::print() const //예약 정보 출력
{
	cout << endl << "[" << user.getName() << "님의 3차 백신 예약 정보]" << endl << endl;
	cout << "기관명: " << vaccine.getInstitution() << endl;
	cout << "백신 종류: " << vaccine.getVSort() << endl;
	cout << "날짜: " << vaccine.getDate() << endl;
	cout << "시간: " << vaccine.getTime() << endl;
	cout << endl << "예약이 완료되었습니다." << endl;
}