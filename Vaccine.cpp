#include "VaccineReservation.h"

Vaccine::Vaccine()
	:institution(""), Vsort(""), date(""), time("")
{
}

Vaccine::Vaccine(string i, string v, string d, string t)
	:institution(i), Vsort(v), date(d), time(t)
{
}

Vaccine::~Vaccine()
{
}

void Vaccine::print() const //���
{
	cout << setw(18) << right << setfill(' ') << institution << " ";
	cout << Vsort << " ";
	cout << date << " ";
	cout << time << " ";
	cout << endl;

}

string Vaccine::getInstitution() const //����� ������
{
	return institution;
}
string Vaccine::getVSort() const //��� ���� ������
{
	return Vsort;
}
string Vaccine::getDate() const //��¥ ������
{
	return date;
}
string Vaccine::getTime() const //�ð� ������
{
	return time;
}

bool Vaccine::isModerna() const //����� ��� üũ
{
	if (Vsort == "�����") return true;
	else return false;
}

bool Vaccine::isPfizer() const //ȭ���� ��� üũ
{
	if (Vsort == "ȭ����") return true;
	else return false;
}