#ifndef VACCINERESERVATION_H
#define VACCINERESERVATION_H
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <fstream>
#define MAX 200
using namespace std;


// ----------����� Ŭ����----------
class User {

private: //��������� ������� ��������
	string name; //�̸�
	int birth; //�ֹι�ȣ ���ڸ�
	int code; //�ֹι�ȣ ���ڸ�
	bool SecondVaccinated; //2�� ��� ���� ����

public:
	User(); //������
	~User(); //�Ҹ���

	void confirm() const; //�Էµ� ���� Ȯ�� (������)
	void getName() const;
	void getId() const;

	void setInfo(); //������

private:
	void setName(string n); //���� ������
	void setId(int b, int c);
	void setSV(bool SV);
};




// ----------��� Ŭ����----------
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




// ---------���� ������ ��� ����Ʈ Ŭ����----------
class VaccineList {
private:
	Vaccine vaccine;
public:
	void setInfo(Vaccine* v);
	void choice(Vaccine* v) const;
};




// ----------���� ���� Ŭ����----------
class Reservation {
private:
	User user;
	Vaccine vac;
};




//-----------�Ϲ� �Լ�-------------



void getFileAndSetInfo(Vaccine v[], int& num);
void chooseVaccine(const Vaccine* v, int& size, int& moderna, int& pfizer);
void showModerna(const Vaccine* v, int& size);
void showPfizer(const Vaccine* v, int& size);




#endif