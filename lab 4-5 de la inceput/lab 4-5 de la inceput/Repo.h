//
//  Repo.h
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 31/03/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef Repo_h
#define Repo_h
#pragma once
#include "Bank.h"

#include <stdio.h>
class Repo
{
private:
    Bank Banks[101];
    int n;
    Bank undos[101];
    int k;
public:
    Repo();
    ~Repo();
    void addBank(Bank x);
    void deleteBank(int id);
    void updateBank(int id,Bank x);
    Bank* getAll();
    int getSize();
    int findID(int day,char* type,char* desc);
    int getMoney(int id);
    void getID_byDay(int day,int ids[101],int &l);
    void getID_byType(char* type,int ids[101],int &l);
    void getID_byMoney(int money,char semn,int ids[101],int &l);
    void undo();
};


#endif /* Repo_h */
