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
	long id; //�ֹι�ȣ
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
	void setId(long id);
	void setSV(bool SV);
};




// ----------���� ������ ��� ����Ʈ Ŭ����----------
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




// ----------���� ���� Ŭ����----------
class Reservation {
private:
	User user;
	VaccineList vac;
};



#endif