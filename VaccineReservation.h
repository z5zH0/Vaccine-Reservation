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

	//������
	string getName() const;
	int getId() const;

	void setInfo(); //������

	void confirm() const; //�Է¹��� ���� Ȯ��

private:
	void setName(string n); //���� ������
	void setId(int b, int c);
	void setSV(bool SV);
};




// ----------��� Ŭ����----------
class Vaccine {
private:
	string institution; //���� �����
	string Vsort; //��� ���� (�����/ȭ����)
	string date; //��¥
	string time; //�ð�

public:
	//������
	Vaccine(); 
	Vaccine(string i, string v, string d, string t);

	~Vaccine(); //�Ҹ���

	void print() const; //���

	//������
	string getInstitution() const;
	string getVSort() const;
	string getDate() const;
	string getTime() const;

	bool isModerna() const; //����� ��� üũ
	bool isPfizer() const; //ȭ���� ��� üũ
};







// ----------���� ���� Ŭ����----------
//���� ���� = ����� + ���
class Reservation {
private:
	User user; //����� ��ü
	Vaccine vaccine; //��� ��ü

public:

	//������
	Reservation();
	Reservation(User u, Vaccine v);

	~Reservation(); //�Ҹ���

	void print() const; //���
};








//-----------�Ϲ� �Լ�-------------

//��� ����Ʈ ���Ͽ��� ��� ���� ������ �迭�� ���
void getFileAndSetInfo(Vaccine v[], int& num);

//��� �����ϱ�
void reserveVaccine(const User u, const Vaccine* v, const int& size, Reservation r, int& moderna, int& pfizer);

//����� ��Ÿ� ���
void showModerna(const Vaccine* v, const int& size);

//ȭ���� ��Ÿ� ���
void showPfizer(const Vaccine* v, const int& size);

//����� ��� ����
void reserveModerna(const User u, const Vaccine* v, Reservation r);

//ȭ���� ��� ����
void reservePfizer(const User u, const Vaccine* v, Reservation r);




#endif