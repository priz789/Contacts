#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<errno.h>
#include<iostream>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<io.h>	

using namespace std;
// ���������� ���������� ��������� "Contact"

struct contact
{
	/*int listNumber;*/ // ����������/�������� �����
	char phone[12]; // ���������� ����� � ������� ������
	char name[20]; // ���
	char surname[20]; // �������
	int age; // �������
};

void MainMenu();
void DrawMainMenu();
contact * ListMemoryAdjust(int);
void DeleteList(contact*);
contact * ContactAddNew(contact*);
void PrintContact(contact*, int);
void ShowOneContact(contact*);
void ShowAllContacts(contact*);
contact* DeleteContact(contact*);
contact* DeleteContactByIndex(contact*, int);
void SaveListToFile(contact*);
contact* LoadListFromFile();
void ClearBuffer();
contact* SortContacts(contact*);
void FindContact(contact*);
void FindBy(contact*, int);
//void FindByName(contact*);
//void FindByNumber(contact*);

