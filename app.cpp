#include "VaccineReservation.h"

int main()
{
	User user;
	Vaccine vaccines[MAX];
	Reservation reservation;
	int numsOfVaccines = 0; //전체 백신수
	int numsOfModerna = 0; //모더나 백신수
	int numsOfPfizer = 0; //화이자 백신수
	int& numV = numsOfVaccines;
	int& numM = numsOfModerna;
	int& numP = numsOfPfizer;
	
	getFileAndSetInfo(vaccines, numV); //파일 속 백신 정보 Vaccine 객체 배열에 세팅

	int answer;

	cout << "COVID-19 3차 백신 접종 예약 프로그램" << endl;

	do {
		user.setInfo(); //사용자 정보 설정
		user.confirm(); //입력 받은 사용자 정보 확인
		cin >> answer;
	} while (answer != 1); //정보가 잘못 입력되면 수정할 수 있도록 반복

	//인자로 사용자 객체, 백신 객체 배열, 전체 백신 개수, 예약 정보 객체, 모더나 개수, 화이자 개수를 넘겨주어 백신 예약
	reserveVaccine(user, vaccines, numV, reservation, numM, numP); 

	return 0;
}