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

void ClearBuffer()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
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
	ClearBuffer();
	cin.getline(newOne.name, 20);
	ClearBuffer();
	cout << "������� ������� ������ �������: ";
	cin.getline(newOne.surname, 20);
	ClearBuffer();
	cout << "������� ����� �������� ������ �������, � ������� 380���������: ";
	cin.getline(newOne.phone, 13);
	ClearBuffer();
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
		/*ShowOneContact(list);*/
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
		ClearBuffer();
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
		FILE * savedlist = fopen(filename, "wb");
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
	if (loadlist)
	{
		fseek(loadlist, 0, SEEK_SET);
		int length = _filelength(_fileno(loadlist));
		int size = length / sizeof(contact);
		contact * newList = new contact[size];
		fread(newList, sizeof(contact), size, loadlist);
		fclose(loadlist);
		cout << "���� ��������." << endl;
		system("pause");
		return newList;
	}
	else
	{
		perror("������: ");
		system("pause");
		return nullptr;
	}
}

contact* SortContacts(contact*list)
{
	if (list != nullptr)
	{
		cout << "������ ��������� �� ����������." << endl;
		ShowAllContacts(list);
		int size = _msize(list) / sizeof(list[0]);
		contact temp;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(list[i].name,list[j].name)>0)
				{
					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
		}
		cout << "������ �������� ����� ����������: " << endl;
		ShowAllContacts(list);
		system("pause");
		return list;
	}
	return nullptr;
}

void FindContact(contact*list)
{
	if (list != nullptr)
	{
		cout << endl;
		int choice;
		cout << "�������� ��� ������:" << endl;
		cout << endl;
		cout << "\t1.�� �����." << endl;
		cout << "\t2.�� ������." << endl;
		cout << endl;
		cout << "��� �����: ";
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			FindBy(list, choice);
		}
		else
		{
			cout << "�������� �����!" << endl;
		}
		/*	switch (choice)
		{
			case 1:
				FindByName(list);
				break;
			case 2:
				FindByNumber(list);
				break;
			default:
				cout << "�������� �����!" << endl;
				break;
		}*/
	}
	else
	{
		cout << endl;
		cout << "C����� ��������� ����!" << endl;
		cout << endl;
	}
	cout << endl;
	system("pause");
}

//void FindByName(contact*list)
//{
//	if (list != nullptr)
//	{
//		cout << "������� ���(��� ��� �����) �������� ��� ������: ";
//		char *findname = new char[20];
//		char *p;
//		int a = 0;
//		ClearBuffer();
//		cin.getline(findname, 20);
//		int size = _msize(list) / sizeof(list[0]);
//		for (int i = 0; i < size; i++)
//		{
//			p = strstr(list[i].name,findname);
//			if (p)
//			{
//				PrintContact(list, i);
//			}
//			else
//			{
//				a++;
//			}
//		}
//		if (a == size)
//		{
//			cout << "�������� � ����� ������ �� ����������." << endl;
//		}
//	}
//	return;
//}
//
//void FindByNumber(contact*list)
//{
//	if (list != nullptr)
//	{
//		cout << "������� �����(��� ��� �����) ��� ������: ";
//		char *findname = new char[20];
//		char *p;
//		int a = 0;
//		ClearBuffer();
//		cin.getline(findname, 20);
//		int size = _msize(list) / sizeof(list[0]);
//		for (int i = 0; i < size; i++)
//		{
//			p = strstr(list[i].phone, findname);
//			if (p)
//			{
//				PrintContact(list, i);
//			}
//			else
//			{
//				a++;
//			}
//		}
//		if (a == size)
//		{
//			cout << "�������� � ����� ������� �� ����������." << endl;
//		}
//	}
//	return;
//}

void FindBy(contact*list,int type)
{
	if (list != nullptr)
	{
		if (type == 1)
		{
			cout << "������� ���(��� ��� �����) �������� ��� ������: ";
		}
		else
		{
			cout << "������� �����(��� ��� �����) ��� ������: ";
		}
		char *findname = new char[20];
		char *p;
		int a = 0;
		ClearBuffer();
		cin.getline(findname, 20);
		int size = _msize(list) / sizeof(list[0]);
		for (int i = 0; i < size; i++)
		{
			p = strstr(type == 1? list[i].name : list[i].phone, findname);
			if (p)
			{
				PrintContact(list, i);
			}
			else
			{
				a++;
			}
		}
		if (a == size)
		{
			cout << "�������� � ����� ������ �� ����������." << endl;
		}
	}
	return;
}