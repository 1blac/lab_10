// Lab_10.3.cpp
// <������ ������>
// ����������� ������ � 10.2
// ����������� ���������� �����
// ������ 30
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


#pragma pack(push, 1)

struct Shop
{
	string name_first_route;
	string name_second_route;
	string number_of_route;
};

void Fill_File(const string File_Name, int option)
{
	Shop S;

	string action;

	ofstream f;

	switch (option)
	{
	case 1:
	{
		f.open(File_Name, ios::out);
		break;
	}
	case 2:
	{
		f.open(File_Name, ios::app); 
		break;
	}
	}

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	cin.get();
	do
	{
		cout << endl << endl;
		cout << "������ ����� ����������� ������ ��������: "; getline(cin, S.name_first_route);
		f << S.name_first_route << endl;
		
		cout << "������ ����� ��������: "; getline(cin, S.number_of_route);
		f << S.number_of_route << endl;

		cout << "������ ����� �������� ������ ��������: "; cin >> S.name_second_route;
		f << S.name_second_route << endl;

		cin.get();
		cout << "������ ���������?(���, ͳ): "; getline(cin, action); cout << endl;

	} while (action == "���" ||
		action == "���");
}
void Print(const string File_Name)
{
	int number = 1;

	char line[50];

	ifstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	string tmp;
	int counter = 0;

	cout << "===================================================================================================" << endl;
	cout << "| � | ����� ����������� ������ ��������  |  ����� ��������    |  ����� �������� ������ ��������  |" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		getline(f, tmp);
		counter++;
	}

	f.close();
	f.open(File_Name, ios::in);

	for (int i = 0; i < counter / 3; i++)
	{
		cout << "|" << setw(2) << number++ << setw(2);

		f.getline(line, sizeof(line));
		cout << "|" << setw(17) << line << setw(20);

		f.getline(line, sizeof(line));
		cout << "|" << setw(11) << line << setw(10);

		f.getline(line, sizeof(line));
		cout << "|" << setw(17) << line << setw(19) << "     |" << endl;		
	}

	cout << "===================================================================================================" << endl;
}

void Number_Search(const string File_Name, const string number_of_route)
{
	char line[50];

	char first_line[50];

	int number = 1;

	fstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "���� �� �������!" << endl;
		return;
	}

	cout << "===================================================================================================" << endl;
	cout << "| � | ����� ����������� ������ ��������  |  ����� ��������    |  ����� �������� ������ ��������  |" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;


	while (!f.eof())
	{
		f.getline(first_line, sizeof(first_line));

		f.getline(line, sizeof(line));

		if (line == number_of_route)
		{
			cout << "|" << setw(2) << number++ << setw(2);

			cout << "|" << setw(17) << first_line << setw(20);

			cout << "|" << setw(11) << line << setw(10);

			f.getline(line, sizeof(line));
			cout << "|" << setw(17) << line << setw(19) << "|" << endl;
		}
		else
			for (int i = 0; i < 2; i++)
				f.getline(line, sizeof(line));
	}
	cout << "===================================================================================================" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int action;

	string Shop_Name, amount_of_items;

	string File_Name = "test.txt";

	do
	{
		cout << endl << endl;
		cout << "������� ��: " << endl;
		cout << "1 - ��������� ����" << endl;
		cout << "2 - ������� ����, �� �������� � ����" << endl;
		cout << "3 - ��������� ������" << endl;
		cout << "4 - ����� �� ������� ��������" << endl;
		cout << "0 - ��������� ������ ��������" << endl;

		cout << "������: "; cin >> action;

		cout << endl << endl;

		switch (action)
		{
		case 1:
			Fill_File(File_Name, 1);
			break;
		case 2:
			Print(File_Name);
			break;
		case 3:
			Fill_File(File_Name, 2);
			break;
		case 4:
			cout << "������ ����� ��������: ";

			cin.get(); cin.sync();
			getline(cin, amount_of_items);

			Number_Search(File_Name, amount_of_items);
			break;
		case 0:
			exit(1);
		default:
			cout << "�������!" << endl;
		}
	} while (action != 0);

	return 0;
}