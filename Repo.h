#pragma once
#include "Conturi_bancare.h"

//clasa repo cu operatiile CRUD,constructori si destructor
class Repo {
private:
    Bank Banks[101];
    int n;
public:
    Repo();
    ~Repo();
    void addBank(Bank b);
    void deleteBank(int nr);
    void updateBank(int nr, Bank b);
    Bank* getAll();
    int getSize();
};
