#include "VaccineReservation.h"



//백신 리스트 파일에서 백신 정보 가져와 배열에 담기
void getFileAndSetInfo(Vaccine v[], int& num) 
{
	string i, s, d, t;

	ifstream inputFile;
	inputFile.open("list.txt"); //백신 리스트 파일 열기

	if (!inputFile.is_open()) { //정상적으로 열렸는지 확인
		cout << "현재 예약 가능한 백신 리스트를 가져올 수 없습니다." << endl;
		assert(false);
	}

	while (!inputFile.eof()) { //파일 한 줄에 담긴 백신 정보 가져와 Vaccine 객체 배열에 담기
		inputFile >> i; //기관명
		inputFile >> s; //백신 종류
		inputFile >> d; //날짜
		inputFile >> t; //시간
		v[num] = Vaccine(i, s, d, t); //인스턴스화
		num++;
	}

	inputFile.close(); //배열에 전부 담으면 파일 닫기
}



//백신 예약하기
void reserveVaccine(const User u, const Vaccine* v, const int& size, Reservation r, int& moderna, int& pfizer)
{
	for (int i = 0; i < size; i++) //전체 백신 수만큼 반복
	{
		if ((v + i)->isModerna()) //모더나 백신이면 모더나 개수 +1
		{
			moderna++;
		}
		if ((v + i)->isPfizer()) //화이자 백신이면 화이자 개수 +1
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

	if (input == 1) { //사용자가 선택한 백신이 모더나 백신일 때
		if (moderna == 0) //모더나 백신의 수가 0개이면 프로그램 종료
		{
			cout << "선택하신 모더나 백신은 현재 예약 가능한 백신이 없습니다." << endl;
			assert(false);
		}
		cout << endl << "[현재 예약 가능한 모더나 백신 리스트]" << endl << endl;
		showModerna(v, size); //모더나 백신 출력
		reserveModerna(u, v, r); //모더나 백신 예약
	}
	if (input == 2) { //사용자가 선택한 백신이 화이자 백신일 때
		if (pfizer == 0) //화이자 백신의 수가 0개이면 프로그램 종료
		{
			cout << "선택하신 화이자 백신은 현재 예약 가능한 백신이 없습니다." << endl;
			assert(false);
		}
		cout << endl << "[현재 예약 가능한 화이자 백신 리스트]" << endl << endl;
		showPfizer(v, size); //화이자 백신 출력
		reservePfizer(u, v, r); //화이자 백신 예약
	}
}

void showModerna(const Vaccine* v, const int& size)
{
	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isModerna()) //백신 객체 배열에서 모더나 백신을 찾으면 출력
		{
			cout << "[" << i + 1 << "] ";
			(v + i)->print();
		}
	}
}

void showPfizer(const Vaccine* v, const int& size)
{
	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isPfizer()) //백신 객체 배열에서 화이자 백신을 찾으면 출력
		{
			cout << "[" << i + 1 << "] ";
			(v + i)->print();
		}
	}
}

void reserveModerna(const User u, const Vaccine* v, Reservation r)
{
	int reserveNum;

	while (true)
	{
		cout << endl << "예약할 백신의 번호를 입력하세요. (좌측 기재된 번호)" << endl;
		cin >> reserveNum;
		if (!(v + reserveNum - 1)->isModerna()) //입력 받은 번호가 잘못된 경우
		{
			cout << endl << "잘못 입력하였습니다." << endl;
		}
		else break; //제대로 입력되면 break
	}

	r = Reservation(u, *(v + reserveNum - 1)); //Reservation 객체로 인스턴스화
	r.print(); //화면에 예약 정보 출력
}

void reservePfizer(const User u, const Vaccine* v, Reservation r)
{
	int reserveNum;

	while (true)
	{
		cout << endl << "예약할 백신의 번호를 입력하세요. (좌측 기재된 번호)" << endl;
		cin >> reserveNum;
		if (!(v + reserveNum - 1)->isPfizer()) //입력 받은 번호가 잘못된 경우
		{
			cout << endl << "잘못 입력하였습니다." << endl;
		}
		else break; //제대로 입력되면 break
	}

	r = Reservation(u, *(v + reserveNum - 1)); //Reservation 객체로 인스턴스화
	r.print(); //화면에 예약 정보 출력
}