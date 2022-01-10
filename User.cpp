#include "VaccineReservation.h"

User::User() {}

User::~User() {}

void User::confirm() const
{
	cout << endl << "[������ ����]" << endl;
	cout << "�̸�: " << name << endl;
	cout << "�ֹι�ȣ: " << setw(13) << right << setfill('0') << id << endl;
	cout << endl << "�Է��Ͻ� ������ �½��ϱ�?" << endl;
	cout << "1. �� 2. �ƴϿ� (���ڷ� �Է�)" << endl;
}

void User::getName() const {
	cout << "�̸�: " << name << endl;
}

void User::getId() const {
	cout << "�ֹι�ȣ: " << id << endl;
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
	cout << endl << "�������� �ֹι�ȣ�� �Է��ϼ���." << endl;
	cin >> id;
	setId(id);
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

void User::setId(long i) {
	id = i;
}

void User::setSV(bool SV) {
	if (SV == false) {
		cout << "2�� ��� ������ �Ϸ��ؾ� 3�� ��� ���� ������ �����մϴ�." << endl;
		assert(false);
	}
	else SecondVaccinated = SV;
}