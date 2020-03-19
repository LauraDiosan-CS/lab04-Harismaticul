#include "Teste.h"
#include "Conturi_bancare.h"
#include "Repo.h"
#include <string.h>
#include <cassert>
#include <iostream>
#define strcpy_s

void testConturi()
{
	char* tipul1 = new char[10];
	char* tipul2 = new char[10];
	char* descriere1 = new char[20];
	char* descriere2 = new char[20];
	strcpy_s(tipul1, strlen("In") + 1, "In");
	strcpy_s(tipul2, strlen("Out") + 1, "Out");
	strcpy_s(descriere1, strlen("Salar") + 1, "Salar");
	strcpy_s(descriere2, strlen("Indemnizatie") + 1, "Indemnizatie");
	Accounts a1(5, 12, tipul1, descriere1);
	Accounts a2(1, 41, tipul2, descriere2);
	assert(a1.getDay() == 5);
	assert(a2.getSum() == 41);
	a1.set_day(10);
	a2.set_type(tipul1);
	a2.set_description(descriere1);
	a2.set_sum(33);
	assert(a1.getDay() == 10);
	assert(strcmp(a2.get_type(), tipul1) == 0);
	assert(strcmp(a2.get_description(), descriere1) == 0);
	assert(a2.getSum() == 33);
	cout << "Tests Accounts are OK!\n";
}

void testRepoConturi()
{
	char* type_1 = new char[10];
	char* type_2 = new char[10];
	char* description_1 = new char[20];
	char* description_2 = new char[20];
	strcpy_s(type_1, strlen("In") + 1, "In");
	strcpy_s(type_2, strlen("Out") + 1, "Out");
	strcpy_s(description_1, strlen("Cumparaturi") + 1, "Cumparaturi");
	strcpy_s(description_2, strlen("Taxe") + 1, "Taxe");
	Accounts a1(5, 65, type_1, description_1);
	Accounts a2(12, 13, type_2, description_2);
	Repo repo_accounts;
	repo_accounts.add(a1);
	repo_accounts.add(a2);
	assert(repo_accounts.get_size() == 2);
	assert(repo_accounts.show()[0] == a1);
	assert(repo_accounts.show()[1] == a2);
	cout << "Tests Repo Accounts are OK!\n";
}
