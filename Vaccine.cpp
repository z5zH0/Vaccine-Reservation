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

void Vaccine::print() const
{
	cout << setw(18) << right << setfill(' ') << institution << " ";
	cout << Vsort << " ";
	cout << date << " ";
	cout << time << " ";
	cout << endl;

}

void Vaccine::getInstitution() const
{
	cout << institution << endl;
}
void Vaccine::getVSort() const
{
	cout << Vsort << endl;
}
void Vaccine::getDate() const
{
	cout << date << endl;
}
void Vaccine::getTime() const
{
	cout << time << endl;
}

bool Vaccine::isModerna() const
{
	if (Vsort == "모더나") return true;
	else return false;
}

bool Vaccine::isPfizer() const
{
	if (Vsort == "화이자") return true;
	else return false;
}