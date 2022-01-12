#include "VaccineReservation.h"

User::User()
	:name(""), birth(0), code(0), SecondVaccinated(false) {}

User::~User() {}

void User::confirm() const //����ڷκ��� �Է¹��� ���� Ȯ��
{
	cout << endl << "[������ ����]" << endl;
	cout << "�̸�: " << name << endl;
	cout << "�ֹι�ȣ: " << setw(6) << right << setfill('0') << birth << "-" << setw(7) << code << endl;
	cout << endl << "�Է��Ͻ� ������ �½��ϱ�?" << endl;
	cout << "1. �� 2. �ƴϿ� (���ڷ� �Է�)" << endl;
}

string User::getName() const { //�̸� ������
	return name;
}

int User::getId() const { //�ֹι�ȣ ������ (������ϸ� ���)
	return birth;
}

void User::setInfo() { //�̸� + �ֹι�ȣ ����ڷκ��� �Է¹޾� ����

	int input;
	bool SV = false;

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

void User::setName(string n) { //�̸� ������
	name = n;
}

void User::setId(int b, int c) { //�ֹι�ȣ ������
	birth = b;
	code = c;
}

void User::setSV(bool SV) { //2�� ��� ������ �Ϸ���� ������ �޽����� ��� �� ���α׷� ����
	if (SV == false) {
		cout << "2�� ��� ������ �Ϸ��ؾ� 3�� ��� ���� ������ �����մϴ�." << endl;
		assert(false);
	}
	else SecondVaccinated = SV;
}