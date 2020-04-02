//
//  repo.h
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 28/03/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <iostream>
#pragma once
#ifndef repo_h
#define repo_h
using namespace std;



class Tranzaction
{
private:
    int id;
    int day;
    int sum;
    char* type;
    char* desc;
public:
    Tranzaction();
    Tranzaction(int id,int day,int sum,char type,char desc);
    Tranzaction(const Tranzaction& a);
    ~Tranzaction();
    int getday();
    int getsuma();
    char* gettip();
    char* getdesc();
    void set_id(int id);
    void set_day(int day);
    void set_sum(int sum);
    void set_type(char* type);
    void set_desc(char* desc);
    Tranzaction& operator=(const Tranzaction& c);
    bool operator==(const Tranzaction& c);
    friend ostream& operator<<(ostream& os, const Tranzaction& a);
};



#endif /* repo_h */
