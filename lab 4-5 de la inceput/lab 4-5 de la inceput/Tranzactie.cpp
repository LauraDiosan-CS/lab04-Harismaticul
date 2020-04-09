//
//  repo.cpp
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 28/03/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "Tranzactie.h"
#include <iostream>
#define strcpy_s

using namespace std;

Tranzaction::Tranzaction()
{
    this->id= 0;
    this->day= 0;
    this->sum= 0;
    this->type= NULL;
    this->desc= NULL;
}
Tranzaction::Tranzaction(int id,int day,int sum,char* type,char* desc)
{
    this->id=id;
    this->day=day;
    this->sum=sum;
        this->type = new char[strlen(type) + 1];
        strcpy_s(this->type, strlen(type) + 1, type);
        this->desc = new char[strlen(desc) + 1];
    strcpy_s(this->desc, strlen(desc) + 1, desc);
}

Tranzaction::Tranzaction(const Tranzaction& a)
{
    this->day = a.day;
    this->sum = a.sum;
    this->type = new char[strlen(a.type) + 1];
    strcpy_s(this->type, strlen(a.type) + 1, a.type);
    this->desc = new char[strlen(a.desc) + 1];
    strcpy_s(this->desc, strlen(a.desc) + 1, a.desc);
}

Tranzaction::~Tranzaction()
{
    this->day = 0;
    this->sum = 0;
    if (this->type != NULL)
    {
        delete[] this->type;
        this->type = NULL;
    }
    if (this->desc != NULL)
    {
        delete[] this->desc;
        this->desc = NULL;
    }
}

int Tranzaction::getID()
{
    return this->id;
}

int Tranzaction::getday()
{
    return this->day;
}

int Tranzaction::getsum()
{
    return this->sum;
}

char* Tranzaction::gettype()
{
    return this->type;
}

char* Tranzaction::getdesc()
{
    return this->desc;
}

void Tranzaction::set_id(int id)
{
    this->id=id;
}

void Tranzaction::set_day(int day)
{
    this->day = day;
}

void Tranzaction::set_sum(int sum)
{
    this->sum = sum;
}

void Tranzaction::set_type(char* type)
{
    if (this->type != NULL)
    {
        delete[] this->type;
        this->type = NULL;
    }
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

void Tranzaction::set_desc(char* desc)
{
    if (this->desc != NULL)
    {
        delete[] this->desc;
        this->desc = NULL;
    }
    this->desc = new char[strlen(desc) + 1];
    strcpy_s(this->desc, strlen(desc) + 1, desc);
}

Tranzaction& Tranzaction::operator=(const Tranzaction& a)
{
    this->set_day(a.day);
    this->set_sum(a.sum);
    this->set_type(a.type);
    this->set_desc(a.desc);
    return *this;
}

bool Tranzaction::operator==(const Tranzaction& a)
{
    return (this->day == a.day) && (this->sum == a.sum) && (strcmp(this->type, a.type) == 0) && (strcmp(this->desc, a.desc) == 0);
}

ostream& operator<<(ostream& os, const Tranzaction& a)
{
    os << "Day: " << a.day << "\nSum: " << a.sum << "\nType: " << a.type << "\nDescription: " << a.desc;
    return os;
}



