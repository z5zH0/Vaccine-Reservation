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

	void confirm() const; //입력된 정보 확인 (접근자)
	void getName() const;
	void getId() const;

	void setInfo(); //설정자

private:
	void setName(string n); //세부 설정자
	void setId(int b, int c);
	void setSV(bool SV);
};




// ----------백신 클래스----------
class Vaccine {
private:
	string institution;
	string Vsort;
	string date;
	string time;

public:
	Vaccine();
	Vaccine(string i, string v, string d, string t);
	~Vaccine();
	void print() const;
	void getInstitution() const;
	void getVSort() const;
	void getDate() const;
	void getTime() const;
	bool isModerna() const;
	bool isPfizer() const;
};




// ---------예약 가능한 백신 리스트 클래스----------
class VaccineList {
private:
	Vaccine vaccine;
public:
	void setInfo(Vaccine* v);
	void choice(Vaccine* v) const;
};




// ----------예약 정보 클래스----------
class Reservation {
private:
	User user;
	Vaccine vac;
};




//-----------일반 함수-------------



void getFileAndSetInfo(Vaccine v[], int& num);
void chooseVaccine(const Vaccine* v, int& size, int& moderna, int& pfizer);
void showModerna(const Vaccine* v, int& size);
void showPfizer(const Vaccine* v, int& size);




#endif