#ifndef VACCINERESERVATION_H
#define VACCINERESERVATION_H
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <fstream>
#define MAX 200
using namespace std;





// ----------사용자 클래스----------
class User {

private: //멤버변수는 사용자의 개인정보
	string name; //이름
	int birth; //주민번호 앞자리
	int code; //주민번호 뒷자리
	bool SecondVaccinated; //2차 백신 접종 여부

public:
	User(); //생성자
	~User(); //소멸자

	//접근자
	string getName() const;
	int getId() const;

	void setInfo(); //설정자

	void confirm() const; //입력받은 정보 확인

private:
	void setName(string n); //세부 설정자
	void setId(int b, int c);
	void setSV(bool SV);
};




// ----------백신 클래스----------
class Vaccine {
private:
	string institution; //접종 기관명
	string Vsort; //백신 종류 (모더나/화이자)
	string date; //날짜
	string time; //시간

public:
	//생성자
	Vaccine(); 
	Vaccine(string i, string v, string d, string t);

	~Vaccine(); //소멸자

	void print() const; //출력

	//접근자
	string getInstitution() const;
	string getVSort() const;
	string getDate() const;
	string getTime() const;

	bool isModerna() const; //모더나 백신 체크
	bool isPfizer() const; //화이자 백신 체크
};







// ----------예약 정보 클래스----------
//예약 정보 = 사용자 + 백신
class Reservation {
private:
	User user; //사용자 객체
	Vaccine vaccine; //백신 객체

public:

	//생성자
	Reservation();
	Reservation(User u, Vaccine v);

	~Reservation(); //소멸자

	void print() const; //출력
};








//-----------일반 함수-------------

//백신 리스트 파일에서 백신 정보 가져와 배열에 담기
void getFileAndSetInfo(Vaccine v[], int& num);

//백신 예약하기
void reserveVaccine(const User u, const Vaccine* v, const int& size, Reservation r, int& moderna, int& pfizer);

//모더나 백신만 출력
void showModerna(const Vaccine* v, const int& size);

//화이자 백신만 출력
void showPfizer(const Vaccine* v, const int& size);

//모더나 백신 예약
void reserveModerna(const User u, const Vaccine* v, Reservation r);

//화이자 백신 예약
void reservePfizer(const User u, const Vaccine* v, Reservation r);




#endif