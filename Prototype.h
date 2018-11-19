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
// глобальное объявление структуры "Contact"

struct contact
{
	/*int listNumber;*/ // порядковый/серийный номер
	char phone[12]; // телефонный номер в формате строки
	char name[20]; // имя
	char surname[20]; // фамилия
	int age; // возраст
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

