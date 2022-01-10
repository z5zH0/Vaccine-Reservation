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
	long id; //주민번호
	bool SecondVaccinated; //2차 백신 접종 여부

public:
	User(); //생성자
	~User(); //소멸자

	void confirm() const; //입력된 정보 확인 (접근자)
	void getName() const;
	void getId() const;

	void setInfo(); //설정자

private:
	void setName(string n); //세부 설정자
	void setId(long id);
	void setSV(bool SV);
};




// ----------예약 가능한 백신 리스트 클래스----------
class VaccineList {
private:
	const char* inputFileName;
	ifstream inputFile;
	struct Vaccine {
		string institution; string Vsort; int date; int time;
	};
	Vaccine* vaccines;
	
	void getInput();
	void print() const;
	void printModerna() const;
	void printPfizer() const;
	int countModerna() const;
	int countPfizer() const;

public:
	VaccineList(const char* inputFileName);
	~VaccineList();
};




// ----------예약 정보 클래스----------
class Reservation {
private:
	User user;
	VaccineList vac;
};



#endif