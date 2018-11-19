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
			cout << "Создание нового контакта." << endl;
			listOfContacts = ContactAddNew(listOfContacts);
			break;
		case '2':
			cout << "Показать контакт." << endl;
			ShowOneContact(listOfContacts);
			break;
		case '3':
			cout << "Удалить контакт." << endl;
			listOfContacts = DeleteContact(listOfContacts);
			break;
		case '4':
			cout << "Сохранить список контактов в файл." << endl;
			SaveListToFile(listOfContacts);
			break;
		case '5':
			cout << "Загрузить список контактов из файла." << endl;
			listOfContacts = LoadListFromFile();
			break;
		case '6':
			cout << "Отобразить все контакты." << endl;
			ShowAllContacts(listOfContacts);
			break;
		case '7':
			cout << "Сортировка контактов по алфавиту." << endl;
			break;
		case '8':
			cout << "Поиск контакта." << endl;
			break;
		case '9':
			cout << "Выход." << endl;
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
