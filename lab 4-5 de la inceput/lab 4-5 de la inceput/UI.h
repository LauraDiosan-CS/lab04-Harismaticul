//
//  UI.h
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 06/04/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef UI_h
#define UI_h
#pragma once
#include "Service.h"


class UI
{
    Service s;
    int curentDay;
    char* comanda[101];
    int undos[101];
    int k;
public:
    UI();
    UI(int curentDay,char comanda[101]);
    UI(const UI& ui);
    ~UI();
    void adaugare();
    void inserare();
    void eliminare_nr();
    void eliminare_nr_la_nr();
    void eliminare_tip();
    void inlocuire();
    void listare_all();
    void listare_tip();
    void listare_suma();
    void listare_sold();
    void suma_tip(); //suma totala a tranzactiilor de un tip
    void max_tip(); //cea mai valoroasa tranzactie de tipul respectiv
    void filtru_tip();
    void filtru_tip_valoare(); //se pastreaza doar tranzactiile de acel tip cu o valoare mai mica decat cea data
    void undo();
    void numarCuvinte();
};


#endif /* UI_h */
