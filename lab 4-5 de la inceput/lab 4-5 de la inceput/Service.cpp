#include "Service.h"
#include <cstddef>
#include <string.h>
#include <iostream>
#include <cstring>

using namespace std;

//Desc:operator de copiere valoare
//In: un obiect de tip banca
//Out: obiectul schimbat
Service::Service()
{

}

Service::~Service()
{

}

void Service::addBank(int id,int day, int money, char* type, char* desc)
{
    Bank b(id, day, money, type, desc);
    this->r.addBank(b);
}

Bank* Service::getAll()
{
    return this->r.getAll();
}

void Service::updateBank(int id, int id2, int day, int money, char* type, char* desc)
{
    Bank b(id2, day, money, type, desc);
    this->r.updateBank(id, b);
}

void Service::deleteBank(int id)

{
    this->r.deleteBank(id);
}

int Service::getSize()
{
    return this->r.getSize();
}

int Service::findID(int day,char* type,char* desc)
{
    return this->r.findID(day, type, desc);
}

int Service::getMoney(int id)
{
    return this->r.getMoney(id);
}
    
void Service::getID_byDay(int day,int ids[101],int &l)
{
    this->r.getID_byDay(day, ids, l);
}

void Service::getID_byType(char* type, int* ids, int &l)
{
    this->r.getID_byType(type, ids, l);
}

void Service::getID_byMoney(int money,char semn,int* ids,int &l)
{
    this->r.getID_byMoney(money,semn,ids,l);
}
        
    
    

//int id,day,money;
//char type[1001],desc[1001];
//cout<<"id: ";
//cin>>id;
//cout<<"day: ";
//cin>>day;
//cout<<"money: ";
//cin>>money;
//cout<<"type: ";
//cin>>type;
//cout<<"desc: ";
//cin>>desc;
//this->addBank(id, day, money, type, desc);
