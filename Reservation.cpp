#include "VaccineReservation.h"

Reservation::Reservation(){}

Reservation::Reservation(User u, Vaccine v)
	:user(u), vaccine(v){}

Reservation::~Reservation(){}

void Reservation::print() const //���� ���� ���
{
	cout << endl << "[" << user.getName() << "���� 3�� ��� ���� ����]" << endl << endl;
	cout << "�����: " << vaccine.getInstitution() << endl;
	cout << "��� ����: " << vaccine.getVSort() << endl;
	cout << "��¥: " << vaccine.getDate() << endl;
	cout << "�ð�: " << vaccine.getTime() << endl;
	cout << endl << "������ �Ϸ�Ǿ����ϴ�." << endl;
}