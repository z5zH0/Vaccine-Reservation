#include "VaccineReservation.h"

User::User() {}

User::~User() {}

void User::confirm() const
{
	cout << endl << "[������ ����]" << endl;
	cout << "�̸�: " << name << endl;
	cout << "�ֹι�ȣ: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
	cout << endl << "�Է��Ͻ� ������ �½��ϱ�?" << endl;
	cout << "1. �� 2. �ƴϿ� (���ڷ� �Է�)" << endl;
}

void User::getName() const {
	cout << "�̸�: " << name << endl;
}

void User::getId() const {
	cout << "�ֹι�ȣ: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
}

void User::setInfo() {

	string name;
	long id;
	bool SV = false;
	int input;

	cout << endl << "COVID-19 3�� ��� �������� ����" << endl;
	cout << endl << "�������� �̸��� �Է��ϼ���." << endl;
	cin >> name;
	setName(name);
	cout << endl << "�������� �ֹι�ȣ ���ڸ��� �Է��ϼ���." << endl;
	cin >> birth;
	cout << endl << "�������� �ֹι�ȣ ���ڸ��� �Է��ϼ���." << endl;
	cin >> code;
	setId(birth, code);
	cout << endl << "�������� 2�� ��� ���� ���θ� �Է��ϼ���." << endl;
	cout << "1. ���� �Ϸ� 2. ������ (���ڷ� �Է�)" << endl;
	cin >> input;
	if (input == 1) {
		SV = true;
	}
	setSV(SV);
}

void User::setName(string n) {
	name = n;
}

void User::setId(int b, int c) {
	birth = b;
	code = c;
}

void User::setSV(bool SV) {
	if (SV == false) {
		cout << "2�� ��� ������ �Ϸ��ؾ� 3�� ��� ���� ������ �����մϴ�." << endl;
		assert(false);
	}
	else SecondVaccinated = SV;
}