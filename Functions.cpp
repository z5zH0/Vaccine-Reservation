#include "VaccineReservation.h"



//��� ����Ʈ ���Ͽ��� ��� ���� ������ �迭�� ���
void getFileAndSetInfo(Vaccine v[], int& num) 
{
	string i, s, d, t;

	ifstream inputFile;
	inputFile.open("list.txt"); //��� ����Ʈ ���� ����

	if (!inputFile.is_open()) { //���������� ���ȴ��� Ȯ��
		cout << "���� ���� ������ ��� ����Ʈ�� ������ �� �����ϴ�." << endl;
		assert(false);
	}

	while (!inputFile.eof()) { //���� �� �ٿ� ��� ��� ���� ������ Vaccine ��ü �迭�� ���
		inputFile >> i; //�����
		inputFile >> s; //��� ����
		inputFile >> d; //��¥
		inputFile >> t; //�ð�
		v[num] = Vaccine(i, s, d, t); //�ν��Ͻ�ȭ
		num++;
	}

	inputFile.close(); //�迭�� ���� ������ ���� �ݱ�
}



//��� �����ϱ�
void reserveVaccine(const User u, const Vaccine* v, const int& size, Reservation r, int& moderna, int& pfizer)
{
	for (int i = 0; i < size; i++) //��ü ��� ����ŭ �ݺ�
	{
		if ((v + i)->isModerna()) //����� ����̸� ����� ���� +1
		{
			moderna++;
		}
		if ((v + i)->isPfizer()) //ȭ���� ����̸� ȭ���� ���� +1
		{
			pfizer++;
		}
	}

	cout << endl << "[������ ���� ���� ������ ��� ��]" << endl << endl;
	cout << "�����: " << moderna << endl;
	cout << "ȭ����: " << pfizer << endl << endl;
	cout << "������ ����� �����ϼ���. (���ڷ� �Է�)" << endl;
	cout << "1. ����� 2. ȭ����" << endl;
	int input;
	cin >> input;

	if (input == 1) { //����ڰ� ������ ����� ����� ����� ��
		if (moderna == 0) //����� ����� ���� 0���̸� ���α׷� ����
		{
			cout << "�����Ͻ� ����� ����� ���� ���� ������ ����� �����ϴ�." << endl;
			assert(false);
		}
		cout << endl << "[���� ���� ������ ����� ��� ����Ʈ]" << endl << endl;
		showModerna(v, size); //����� ��� ���
		reserveModerna(u, v, r); //����� ��� ����
	}
	if (input == 2) { //����ڰ� ������ ����� ȭ���� ����� ��
		if (pfizer == 0) //ȭ���� ����� ���� 0���̸� ���α׷� ����
		{
			cout << "�����Ͻ� ȭ���� ����� ���� ���� ������ ����� �����ϴ�." << endl;
			assert(false);
		}
		cout << endl << "[���� ���� ������ ȭ���� ��� ����Ʈ]" << endl << endl;
		showPfizer(v, size); //ȭ���� ��� ���
		reservePfizer(u, v, r); //ȭ���� ��� ����
	}
}

void showModerna(const Vaccine* v, const int& size)
{
	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isModerna()) //��� ��ü �迭���� ����� ����� ã���� ���
		{
			cout << "[" << i + 1 << "] ";
			(v + i)->print();
		}
	}
}

void showPfizer(const Vaccine* v, const int& size)
{
	for (int i = 0; i < size; i++)
	{

		if ((v + i)->isPfizer()) //��� ��ü �迭���� ȭ���� ����� ã���� ���
		{
			cout << "[" << i + 1 << "] ";
			(v + i)->print();
		}
	}
}

void reserveModerna(const User u, const Vaccine* v, Reservation r)
{
	int reserveNum;

	while (true)
	{
		cout << endl << "������ ����� ��ȣ�� �Է��ϼ���. (���� ����� ��ȣ)" << endl;
		cin >> reserveNum;
		if (!(v + reserveNum - 1)->isModerna()) //�Է� ���� ��ȣ�� �߸��� ���
		{
			cout << endl << "�߸� �Է��Ͽ����ϴ�." << endl;
		}
		else break; //����� �ԷµǸ� break
	}

	r = Reservation(u, *(v + reserveNum - 1)); //Reservation ��ü�� �ν��Ͻ�ȭ
	r.print(); //ȭ�鿡 ���� ���� ���
}

void reservePfizer(const User u, const Vaccine* v, Reservation r)
{
	int reserveNum;

	while (true)
	{
		cout << endl << "������ ����� ��ȣ�� �Է��ϼ���. (���� ����� ��ȣ)" << endl;
		cin >> reserveNum;
		if (!(v + reserveNum - 1)->isPfizer()) //�Է� ���� ��ȣ�� �߸��� ���
		{
			cout << endl << "�߸� �Է��Ͽ����ϴ�." << endl;
		}
		else break; //����� �ԷµǸ� break
	}

	r = Reservation(u, *(v + reserveNum - 1)); //Reservation ��ü�� �ν��Ͻ�ȭ
	r.print(); //ȭ�鿡 ���� ���� ���
}