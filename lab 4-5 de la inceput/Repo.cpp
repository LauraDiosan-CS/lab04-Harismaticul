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

