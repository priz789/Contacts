#include"Prototype.h"

void DrawMainMenu()
{
	cout << "\tГлавное меню." << endl;
	cout << endl;
	cout << "\t1. Создать новый контакт." << endl;
	cout << "\t2. Показать контакт." << endl;
	cout << "\t3. Удалить контакт." << endl;
	cout << "\t4. Сохранить список контактов в файл." << endl;
	cout << "\t5. Загрузить список контактов из файла." << endl;
	cout << "\t6. Отобразить все контакты." << endl;
	cout << "\t7. Сортировка контактов по алфавиту." << endl;
	cout << "\t8. Поиск контактов." << endl;
	cout << "\t9. Выход." << endl;
	cout << endl;
}

contact * ListMemoryAdjust(int number)
{
	contact* list = new contact[number];
	return list;
}

void DeleteList(contact* list)
{
	if (list != nullptr)
	{
		delete[]list;
		list = nullptr;
	}
}

contact * ContactAddNew(contact* list)
{
	contact newOne;
	cout << "Введите имя нового котакта: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(newOne.name, 20);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите фамилию нового котакта: ";
	cin.getline(newOne.surname, 20);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите номер телефона нового котакта, в формате 380ХХХХХХХХХ: ";
	cin.getline(newOne.phone, 13);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите возраст нового котакта: ";
	cin >> newOne.age;
	cout << endl;
	if (list == nullptr)
	{
		list = ListMemoryAdjust(1);
		/*newOne.listNumber = 1;*/
		list[0] = newOne;
		return list;
	}
	int size = _msize(list) / sizeof(list[0]);
	/*newOne.listNumber = size + 1;*/
	contact * newList = ListMemoryAdjust(size + 1);
	for (int i = 0; i < size; i++)
	{
		newList[i] = list[i];
	}
	DeleteList(list);
	newList[size] = newOne;
	cout << endl;
	cin.clear();
	system("pause");
	return newList;
}

void ShowOneContact(contact* list)
{
	if (list != nullptr)
	{
		cout << endl;
		cout << "Введите порядковый номер контакта, который вы хотите увидеть: ";
		int iNum;
		cin >> iNum;
		int size = _msize(list) / sizeof(list[0]);
		if (iNum <= size && iNum > 0)
		{
			PrintContact(list, iNum - 1);
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Контакта с таким порядковым номером не сущесвтует!" << endl;
			cout << endl;
		}
		system("pause");
		return;
	}
	cout << endl;
	cout << "Cписок контактов пуст!" << endl;
	cout << endl;
	system("pause");
}

void ShowAllContacts(contact* list)
{
	if (list != nullptr)
	{
		int size = _msize(list) / sizeof(list[0]);
		for (int i = 0; i < size; i++)
		{
			PrintContact(list, i);
			cout << endl;
		}
		ShowOneContact(list);
		return;
	}
	cout << endl;
	cout << "Cписок контактов пуст!" << endl;
	cout << endl;
	system("pause");
}

contact* DeleteContact(contact* list)
{
	if (list != nullptr)
	{
		cout << endl;
		cout << "Введите порядковый номер контакта, который вы хотите удалить: ";
		int iNum;
		cin >> iNum;
		int size = _msize(list) / sizeof(list[0]);
		if (iNum <= size && iNum > 0)
		{
			list = DeleteContactByIndex(list, iNum - 1);
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Контакта с таким порядковым номером не сущесвтует!" << endl;
			cout << endl;
			system("pause");
			return list;
		}
	}
	else
	{
		cout << endl;
		cout << "Cписок контактов пуст!" << endl;
		cout << endl;
	}
	system("pause");
	return list;
}

contact* DeleteContactByIndex(contact*list, int index)
{
	if (list != nullptr)
	{
		int size = _msize(list) / sizeof(list[0]);
		int a = 0;
		contact * newList = ListMemoryAdjust(size - 1);
		for (int i = 0; i < size - 1; i++)
		{
			if (i == index)
			{
				a++;
			}
			newList[i] = list[i + a];
		}
		DeleteList(list);
		return newList;
	}
	return nullptr;
}

void PrintContact(contact* list, int index)
{
	if (list != nullptr)
	{
		cout << endl;
		cout << "\tПорядковый номер контакта: " << index+1 << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\tИмя: " << list[index].name << endl;
		cout << "\tФамилия: " << list[index].surname << endl;
		cout << "\tВозраст: " << list[index].age << endl;
		cout << "\tТелефон: " << list[index].phone << endl;
		cout << endl;
	}
}

void SaveListToFile(contact*list)
{
	if (list != nullptr)
	{
		cout << endl;
		int size = _msize(list) / sizeof(list[0]);
		/*cout << "Введите имя файла для сохранения(обязательно добавьте расширение .txt): ";*/
		cout << "Введите имя файла для сохранения: ";
		char filename[MAX_PATH];
		gets_s(filename, MAX_PATH);
		FILE * savedlist = fopen(filename, "ab");
		if (savedlist)
		{
			fseek(savedlist, 0, SEEK_END);
			fwrite(list, sizeof(contact), size, savedlist);
			cout << "Файл успешно создан или дополнен." << endl;
			fclose(savedlist);
		}
		else
		{
			cout << "Не удалось создать или дополнить файл!" << endl;
			cout << "Ошибка #" << errno << endl;	// Макрос errno (заголовочный файл errno.h) вызывает функцию _errno: http://www.cplusplus.com/reference/cerrno/errno/
			perror("Ошибка: "); // Функция печатает текст ошибки, который определен операционной системой
		}
	}
	return;
}

contact* LoadListFromFile()
{
	cout << endl;
	cout << "Введите имя файла для загрузки: ";
	char filename[MAX_PATH];
	gets_s(filename, MAX_PATH);
	FILE * loadlist = fopen(filename, "rb");
	/*if (!loadlist);
	{
		perror("Open: ");
		return nullptr;
	}*/
	fseek(loadlist, 0, SEEK_SET);
	int length = _filelength(_fileno(loadlist));
	int size = length / sizeof(contact);
	contact * newList = new contact[size];
	fread(newList, sizeof(contact), size, loadlist);
	fclose(loadlist);
	return newList;
}
