//
//  Repo.cpp
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 31/03/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include "Repo.h"
#include <stdio.h>

Repo::Repo()
{
    this->n=0;
}

Repo::~Repo()
{
    this->n=0;
}

//Desc: adauga un obiect
//In: un obiect de tip banca
//Out: -
void Repo::addBank(Bank x)
{
    this->Banks[this->n++]=x;
}

//Desc: sterge un obiect dupa id
//In: id
//Out: -
void Repo::deleteBank(int id)
{
    int ok=1;
    for(int i=0;i<n;i++)
        if(this->Banks[i].getID()==id)
        {
            for ( int j = i;j<n-1;j++)
                this->Banks[j]=this->Banks[j+1];
            ok=0;
        }
    if(ok==0)
        this->n--;
    
    
}

//Desc: inlocuiesti obiectul de la id-ul dat cu obiectul data
//In: id,un obiect de tip banca
//Out: -
void Repo::updateBank(int id,Bank x)
{
    for(int i=0;i<n;i++)
        if(this->Banks[i].getID()==id)
            this->Banks[i]=x;
            
}

//Desc: returneaza lista de obiecte
//In: -
//Out: returneaza lista de obiecte
Bank* Repo::getAll()
{
    return this->Banks;
}

//Desc: returneaza marimea listei de obiecte
//In: -
//Out: returneaza marimea listei de obiecte
int Repo::getSize()
{
    return this->n;
}

int Repo::findID(int day,char* type,char* desc)
{
    int i;
    for(i=0;i<this->n;i++)
        if(this->Banks[i].getDay()==day and this->Banks[i].getType()==type and this->Banks[i].getDesc()==desc)
            return this->Banks[i].getID();
    return 0;
}

int Repo::getMoney(int id)
{
    int i;
    for(i=0;i<this->n;i++)
        if(this->Banks[i].getID()==id)
            return this->Banks[i].getMoney();
    return 0;
}

void Repo::getID_byDay(int day,int ids[101],int &l)
{
    int i;
    for(i=0;i<this->n;i++)
        if(this->Banks[i].getDay()==day)
            ids[l++]=this->Banks[i].getID();
}

void Repo::getID_byType(char* type, int ids[101], int &l)
{
 int i;
    for(i=0;i<this->n;i++)
        if(this->Banks[i].getType()==type)
            ids[l++]=this->Banks[i].getID();
}

void Repo::getID_byMoney(int money, char semn, int ids[101], int &l)
{
    int i;
       for(i=0;i<this->n;i++)
       {
           if(this->Banks[i].getMoney()==money and semn=='=')
               ids[l++]=this->Banks[i].getID();
           if(this->Banks[i].getMoney()<money and semn=='<')
               ids[l++]=this->Banks[i].getID();
           if(this->Banks[i].getMoney()>money and semn=='>')
               ids[l++]=this->Banks[i].getID();
       }
}



void Repo::undo()
{
    
}

