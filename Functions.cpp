#include"Prototype.h"

void DrawMainMenu()
{
	cout << "\t������� ����." << endl;
	cout << endl;
	cout << "\t1. ������� ����� �������." << endl;
	cout << "\t2. �������� �������." << endl;
	cout << "\t3. ������� �������." << endl;
	cout << "\t4. ��������� ������ ��������� � ����." << endl;
	cout << "\t5. ��������� ������ ��������� �� �����." << endl;
	cout << "\t6. ���������� ��� ��������." << endl;
	cout << "\t7. ���������� ��������� �� ��������." << endl;
	cout << "\t8. ����� ���������." << endl;
	cout << "\t9. �����." << endl;
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
	cout << "������� ��� ������ �������: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(newOne.name, 20);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ������� ������ �������: ";
	cin.getline(newOne.surname, 20);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ����� �������� ������ �������, � ������� 380���������: ";
	cin.getline(newOne.phone, 13);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ������� ������ �������: ";
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
		cout << "������� ���������� ����� ��������, ������� �� ������ �������: ";
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
			cout << "�������� � ����� ���������� ������� �� ����������!" << endl;
			cout << endl;
		}
		system("pause");
		return;
	}
	cout << endl;
	cout << "C����� ��������� ����!" << endl;
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
	cout << "C����� ��������� ����!" << endl;
	cout << endl;
	system("pause");
}

contact* DeleteContact(contact* list)
{
	if (list != nullptr)
	{
		cout << endl;
		cout << "������� ���������� ����� ��������, ������� �� ������ �������: ";
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
			cout << "�������� � ����� ���������� ������� �� ����������!" << endl;
			cout << endl;
			system("pause");
			return list;
		}
	}
	else
	{
		cout << endl;
		cout << "C����� ��������� ����!" << endl;
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
		cout << "\t���������� ����� ��������: " << index+1 << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\t���: " << list[index].name << endl;
		cout << "\t�������: " << list[index].surname << endl;
		cout << "\t�������: " << list[index].age << endl;
		cout << "\t�������: " << list[index].phone << endl;
		cout << endl;
	}
}

void SaveListToFile(contact*list)
{
	if (list != nullptr)
	{
		cout << endl;
		int size = _msize(list) / sizeof(list[0]);
		/*cout << "������� ��� ����� ��� ����������(����������� �������� ���������� .txt): ";*/
		cout << "������� ��� ����� ��� ����������: ";
		char filename[MAX_PATH];
		gets_s(filename, MAX_PATH);
		FILE * savedlist = fopen(filename, "ab");
		if (savedlist)
		{
			fseek(savedlist, 0, SEEK_END);
			fwrite(list, sizeof(contact), size, savedlist);
			cout << "���� ������� ������ ��� ��������." << endl;
			fclose(savedlist);
		}
		else
		{
			cout << "�� ������� ������� ��� ��������� ����!" << endl;
			cout << "������ #" << errno << endl;	// ������ errno (������������ ���� errno.h) �������� ������� _errno: http://www.cplusplus.com/reference/cerrno/errno/
			perror("������: "); // ������� �������� ����� ������, ������� ��������� ������������ ��������
		}
	}
	return;
}

contact* LoadListFromFile()
{
	cout << endl;
	cout << "������� ��� ����� ��� ��������: ";
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
