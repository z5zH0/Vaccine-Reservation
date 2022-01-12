#include "VaccineReservation.h"

int main()
{
	User user;
	Vaccine vaccines[MAX];
	Reservation reservation;
	int numsOfVaccines = 0; //��ü ��ż�
	int numsOfModerna = 0; //����� ��ż�
	int numsOfPfizer = 0; //ȭ���� ��ż�
	int& numV = numsOfVaccines;
	int& numM = numsOfModerna;
	int& numP = numsOfPfizer;
	
	getFileAndSetInfo(vaccines, numV); //���� �� ��� ���� Vaccine ��ü �迭�� ����

	int answer;

	cout << "COVID-19 3�� ��� ���� ���� ���α׷�" << endl;

	do {
		user.setInfo(); //����� ���� ����
		user.confirm(); //�Է� ���� ����� ���� Ȯ��
		cin >> answer;
	} while (answer != 1); //������ �߸� �ԷµǸ� ������ �� �ֵ��� �ݺ�

	//���ڷ� ����� ��ü, ��� ��ü �迭, ��ü ��� ����, ���� ���� ��ü, ����� ����, ȭ���� ������ �Ѱ��־� ��� ����
	reserveVaccine(user, vaccines, numV, reservation, numM, numP); 

	return 0;
}