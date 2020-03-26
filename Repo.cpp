#include "Repo.h"
//clasa repository


//constructor
Repo::Repo()
{
    this->n = 0;
}

//destructor
Repo::~Repo()
{
    this->n = 0;
}

//functie adaugare obiect in lista de obiecte
void Repo::addBank(Bank b)
{
    this->Banks[this->n++] = b;
}

//pentru lab5
void Repo::deleteBank(int nr)
{
    for (int i = 0; i < n; i++)
        if (this->Banks[i].getDay() == nr)
            for (int k = i; k < n - 1; k++)
                this->Banks[k] = this->Banks[k + 1];
    this->n--;
}

//pentru lab5
void Repo::updateBank(int nr, Bank b)
{
    for (int i = 0; i < n; i++)
        if (this->Banks[i].getDay() == nr)
            this->Banks[i] = b;
}

//luare toate obiectele
Bank* Repo::getAll()
{
    return this->Banks;
}
//luare marime
int Repo::getSize()
{
    return this->n;
}
