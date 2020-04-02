//clasa banca cu toate tipurile de constructori si operatori
#include "Bank.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#define strcpy_s
using namespace std;


//Desc: creeaza un obiect de tip Produs
//In: -
//Out: 
Bank::Bank()
{
    this->id = 0;
    this->day = 0;
    this->money = 0;
    this->type = NULL;
    this->desc = NULL;
}


//Desc: creeaza un obiect de tip Produs
//In: id,day,money,type,desc
//Out: o instanta a clasei Produs
Bank::Bank(int id, int day, int money, char* type, char* desc)
{
    this->id = id;

    this->day = day;

    this->money = money;
    
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, 1 + strlen(type), type);
    
    this->desc = new char[strlen(desc) + 1];
    strcpy_s(this->desc, 1 + strlen(desc), desc);
}

//Desc:constructor copiere a unui obiect de tip banca
//In: un obiect de tip banca
//Out: o instanta a clasei Produs
Bank::Bank(const Bank& b)
{
    this->id = b.id;

    this->day = b.day;
    
    this->money = b.money;

    this->type = new char[strlen(b.type) + 1];
    strcpy_s(this->type, 1 + strlen(b.type), b.type);

    this->desc = new char[strlen(b.desc) + 1];
    strcpy_s(this->desc, 1 + strlen(b.desc), b.desc);
    

}

//Desc:destructor pentru un obiect bank
//In: -
//Out: -


Bank::~Bank()
{
    if (this->type)
    {
        delete[] this->type;
        this->type = NULL;
    }

    if (this->desc)
    {
        delete[] this->desc;
        this->desc = NULL;
    }
}

//Desc:acceseaza acel atribut al bancii
//In: -
//Out: id-ul bancii

int Bank::getID() {
    return this->id;
}

//Desc:acceseaza acel atribut al bancii
//In: -
//Out: ziua
int Bank::getDay() {
    return this->day;
}

//Desc:acceseaza acel atribut al bancii
//In: -
//Out: suma de bani
int Bank::getMoney() {
    return this->money;
}

//Desc:acceseaza acel atribut al bancii
//In: -
//Out: tipul cheltuielii
char* Bank::getType() {
    return this->type;
}

//Desc:acceseaza atribut al bancii
//In: -
//Out: descrierea cheltuielii
char* Bank::getDesc() {
    return this->desc;
}

//Desc:schimba acel atribut al bancii
//In: -
//Out: -
void Bank::setID(int id)
{
    this->id = id;
}

//Desc:schimba acel atribut al bancii
//In: -
//Out: -
void Bank::setDay(int day)
{
    this->day = day;
}

//Desc:schimba acel atribut al bancii
//In: -
//Out: -
void Bank::setMoney(int money)
{
    this->money = money;
}

//Desc:schimba acel atribut al bancii
//In: -
//Out: -
void Bank::setType(char* type)
{
    if (this->type)
    {
        delete[] this->type;
    }
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

//Desc:schimba acel atribut al bancii
//In: -
//Out: -
void Bank::setDesc(char* desc)
{
    if (this->desc)
    {
        delete[] this->desc;
    }
    this->desc = new char[strlen(desc) + 1];
    strcpy_s(this->desc, strlen(desc) + 1, desc);
}

//Desc:operator de copiere valoare
//In: un obiect de tip banca
//Out: obiectul schimbat
Bank& Bank::operator=(const Bank& b) {
    this->setID(b.id);
    this->setDay(b.day);
    this->setMoney(b.money);
    this->setDesc(b.desc);
    this->setType(b.type);
    return *this;
}

// operator de comparare
//Desc:operator de comparare
//In: un obiect de tip banca
//Out: obiectul mai mare

bool Bank:: operator==(const Bank& b) {
    return strcmp(this->type, b.type) == 0 && strcmp(this->desc, b.desc) == 0 &&  this->day == b.day && this->money == b.money && this->id == b.id ;
}

//declararea operatie de afisare clasa
ostream& operator<<(ostream& os, const Bank& b)
{
    os << b.id << " "<< b.day << " " << b.money << " " << b.type << " " << b.desc;
    return os;
}
