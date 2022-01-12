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

void Vaccine::print() const //출력
{
	cout << setw(18) << right << setfill(' ') << institution << " ";
	cout << Vsort << " ";
	cout << date << " ";
	cout << time << " ";
	cout << endl;

}

string Vaccine::getInstitution() const //기관명 접근자
{
	return institution;
}
string Vaccine::getVSort() const //백신 종류 접근자
{
	return Vsort;
}
string Vaccine::getDate() const //날짜 접근자
{
	return date;
}
string Vaccine::getTime() const //시간 접근자
{
	return time;
}

bool Vaccine::isModerna() const //모더나 백신 체크
{
	if (Vsort == "모더나") return true;
	else return false;
}

bool Vaccine::isPfizer() const //화이자 백신 체크
{
	if (Vsort == "화이자") return true;
	else return false;
}