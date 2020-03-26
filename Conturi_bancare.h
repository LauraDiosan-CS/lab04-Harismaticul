#pragma once
#include <iostream>
using namespace std;

//clasa banca cu toate atributele,operatorii,getteri si setteri specificati in enunt,constrctori si destructori specifici
class Bank {
private:
    int day;
    int money;
    char* type;
    char* desc;
public:
    Bank();
    Bank(int day, int money, char* type, char* desc);
    Bank(const Bank& b);
    ~Bank();
    int getDay();
    int getMoney();
    char* getType();
    char* getDesc();
    void setDay(int day);
    void setMoney(int money);
    void setType(char* type);
    void setDesc(char* desc);
    Bank& operator=(const Bank& b);
    bool operator==(const Bank& b);
    friend ostream& operator<<(ostream& os, const Bank& b);
};
