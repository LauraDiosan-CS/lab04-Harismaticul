//
//  Service.h
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 31/03/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef Service_h
#define Service_h
#pragma once
#include "Bank.h"
#include "Repo.h"

class Service
{
    Repo r;
public:
    Service();
    ~Service();
    void addBank(int id, int day, int money, char* type, char* desc);
    void updateBank(int id,int id2,int day, int money, char* type, char* desc);
    void deleteBank(int id);
    Bank* getAll();
    int getSize();
    int findID(int day,char* type,char* desc);
    int getMoney(int i);
    void getID_byDay(int day,int ids[101],int &l);
    void getID_byType(char* type,int ids[101],int &l);
    void getID_byMoney(int money,char semn,int ids[101],int &l);
};


#endif /* Service_h */
