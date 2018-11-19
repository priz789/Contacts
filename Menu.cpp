#include "Prototype.h"

void MainMenu()
{
	contact *listOfContacts = nullptr;
	int choice;
	while (true)
	{
		system("cls");
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		DrawMainMenu();
		choice = _getch();
		switch (choice)
		{
		case '1':
			cout << "�������� ������ ��������." << endl;
			listOfContacts = ContactAddNew(listOfContacts);
			break;
		case '2':
			cout << "�������� �������." << endl;
			ShowOneContact(listOfContacts);
			break;
		case '3':
			cout << "������� �������." << endl;
			listOfContacts = DeleteContact(listOfContacts);
			break;
		case '4':
			cout << "��������� ������ ��������� � ����." << endl;
			SaveListToFile(listOfContacts);
			break;
		case '5':
			cout << "��������� ������ ��������� �� �����." << endl;
			listOfContacts = LoadListFromFile();
			break;
		case '6':
			cout << "���������� ��� ��������." << endl;
			ShowAllContacts(listOfContacts);
			break;
		case '7':
			cout << "���������� ��������� �� ��������." << endl;
			break;
		case '8':
			cout << "����� ��������." << endl;
			break;
		case '9':
			cout << "�����." << endl;
			return;
			break;
		/*case 27:
			return;
			break;*/
		/*default:
			break;*/
		}
	}
}
