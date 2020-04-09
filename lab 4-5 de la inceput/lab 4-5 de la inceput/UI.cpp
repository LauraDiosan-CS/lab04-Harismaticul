//
//  UI.cpp
//  lab 4-5 de la inceput
//
//  Created by Haris Muller Cristea on 06/04/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "UI.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include "Service.h"
#define strcyp_s


using namespace std;

int doarCifre(char x[101])
{
    int i;
    i=0;
    for(i=0;i<strlen(x);i++)
        if(x[i]!='1' and x[i]!='2' and x[i]!='3' and x[i]!='4' and x[i]!='5' and x[i]!='6' and x[i]!='7' and x[i]!='8' and x[i]!='9' and x[i]!='0')
            return 0;
    return 1;
}

int doarSemne(char x[101])
{
    int i,n;
    i=0;
    n=strlen(x);
    for(i=0;i<n;i++)
        if(x[i]!='=' and x[i]!='>' and x[i]!='<')
            return 0;
    return 1;
}


UI::UI()
{
    this->curentDay=0;
    this->comanda=NULL;
}

UI::UI(int curentDay,char* comanda)
{
    this->curentDay=curentDay;
    this->comanda = new char[strlen(comanda) + 1];
    strcpy_s(this->comanda, 1 + strlen(comanda), comanda);
}

UI::UI(const UI& ui)
{
    this->curentDay=ui.curentDay;
    this->comanda = new char[strlen(ui.comanda) + 1];
    strcpy_s(this->comanda, 1 + strlen(ui.comanda), ui.comanda);
}

UI::~UI()
{
    this->curentDay=0;
    if(this->comanda)
    {
        delete[] this->comanda;
        this->comanda=NULL;
    }
}

void UI::adaugare()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],money[101],type[101],desc[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            else if(ok==1)
            {
                strcpy(money, cuvant);
                ok++;
                k=0;
            }
            else if(ok==2)
            {
                strcpy(type,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(desc,cuvant);
    k=0;
    int bani=0;
    for(i=0;i<strlen(money);i++)
    {
        int x=money[i]-'0';
        bani=bani*10+x;
    }
    srand(time(NULL));   // Initialization, should only be called once.
    int id = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
    this->s.addBank(id, this->curentDay, bani, type, desc);
}

void UI::inserare()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],money[101],type[101],desc[101],day[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            else if(ok==1)
            {
                strcpy(day, cuvant);
                ok++;
                k=0;
            }
            else if(ok==2)
            {
                strcpy(money,cuvant);
                ok++;
                k=0;
            }
            else if(ok==3)
            {
                strcpy(type,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(desc,cuvant);
    k=0;
    int bani=0;
    int ziua=0;
    for(i=0;i<strlen(money);i++)
    {
        int x=money[i]-'0';
        bani=bani*10+x;
    }
    for(i=0;i<strlen(day);i++)
    {
        int x=day[i]-'0';
        ziua=ziua*10+x;
    }
    srand(time(NULL));   // Initialization, should only be called once.
    int id = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
    this->s.addBank(id, ziua, bani, type, desc);
}

void UI::inlocuire()
{
    int k=0,ok,i,n,id;
    char cuvant[101],operatie[101],money[101],type[101],desc[101],day[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            else if(ok==1)
            {
                strcpy(day, cuvant);
                ok++;
                k=0;
            }
            else if(ok==2)
            {
                strcpy(type,cuvant);
                ok++;
                k=0;
            }
            else if(ok==3)
            {
                strcpy(desc,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(money,cuvant);
    k=0;
    int bani=0;
    int ziua=0;
    for(i=0;i<strlen(money);i++)
    {
        int x=money[i]-'0';
        bani=bani*10+x;
    }
    for(i=0;i<strlen(day);i++)
    {
        int x=day[i]-'0';
        ziua=ziua*10+x;
    }
    int newMoney=0;
    id=this->s.findID(ziua, type, desc);
    if(id!=0)
    {
        newMoney=this->s.getMoney(id)+bani;
        this->s.updateBank(id, id, ziua, newMoney, type, desc);
    }
    else
        cout<<"Nu exista tranzactie cu datele astea";
}

void UI::eliminare_nr_la_nr()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],day1[101],day2[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            else if(ok==1)
            {
                strcpy(day1, cuvant);
                ok++;
                k=0;
            }
            else if(ok==2)
            {
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(day2,cuvant);
    k=0;
    int ziua1=0;
    for(i=0;i<strlen(day1);i++)
    {
        int x=day1[i]-'0';
        ziua1=ziua1*10+x;
    }
    int ziua2=0;
    for(i=0;i<strlen(day2);i++)
    {
        int x=day2[i]-'0';
        ziua2=ziua2*10+x;
    }
    int ids[101],l=0;
    for(i=ziua;i<=ziua2;i++)
        this->s.getID_byDay(i, ids, l);
    for(i=0;i<l;i++)
        this->s.deleteBank(ids[i]);
}

void UI::eliminare_nr()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],day1[101];
    n=strlen(this->comaids;
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(day1,cuvant);
    k=0;
    int ziua1=0;
    for(i=0;i<strlen(day1);i++)
    {
        int x=day1[i]-'0';
        ziua1=ziua1*10+x;
    }
    int ids[101],l=0;
        this->s.getID_byDay(ziua1, ids2, l);
    for(i=0;i<l;i++)
        this->s.deleteBank(ids[i]);
}

void UI::eliminare_tip()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],type[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(type,cuvant);
    k=0;
    int ids[101],l=0;
    this->s.getID_byType(type, ids, l);
    for(i=0;i<l;i++)
        this->s.deleteBank(ids[i]);
}

void UI::listare_all()
{
    for (int i = 0; i < this->s.getSize(); i++)
    {
        cout << this->s.getAll()[i].getID() << " "<< this->s.getAll()[i].getDay() << " " << this->s.getAll()[i].getMoney() << " " << this->s.getAll()[i].getType() << " " << this->s.getAll()[i].getDesc()<<endl;
    }
    cout << endl;
}

void UI::listare_tip()
{
 int k=0,ok,i,n;
    char cuvant[101],operatie[101],type[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(type,cuvant);
    k=0;
    int ids[101],l=0;
    this->s.getID_byType(type, ids, l);
    for(i=0;i<l;i++)
        cout << this->s.getAll()[i].getID() << " "<< this->s.getAll()[i].getDay() << " " << this->s.getAll()[i].getMoney() << " " << this->s.getAll()[i].getType() << " " << this->s.getAll()[i].getDesc()<<endl;
}

void UI::listare_suma()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],money[101],semn[2],type[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            else if(ok==1)
            {
                strcpy(semn,cuvant);
                ok++;
                k=0;
            }
            
        }
    cuvant[k]='\0';
    strcpy(money,cuvant);
    int bani;
    for(i=0;i<strlen(money);i++)
    {
        int x=money[i]-'0';
        bani=bani*10+x;
    }
    k=0;
    int ids[101],l=0;
    this->s.getID_byMoney(type,semn,ids,l);
    for(i=0;i<l;i++)
        cout << this->s.getAll()[i].getID() << " "<< this->s.getAll()[i].getDay() << " " << this->s.getAll()[i].getMoney() << " " << this->s.getAll()[i].getType() << " " << this->s.getAll()[i].getDesc()<<endl;
}

void UI::listare_sold()
{
    
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],day[101],sold[5],type[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            if(ok==1)
            {
                strcpy(sold,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(day,cuvant);
    k=0;
    int zi;
    for(i=0;i<strlen(day);i++)
    {
        int x=day[i]-'0';
        zi=zi*10+x;
    }
    int ids1[101],l1=0;
    int ids2[101],l2=0;
    char in[4]="in";
    char out[4]="out";
    this->s.getID_byType(in, ids1, l1);
    this->s.getID_byType(out, ids2, l2);
    int sum_in=0;
    int sum_out=0;
    for(i=0;i<l1;i++)
        sum_in=sum_in+this->s.getAll()[i].getMoney();
    for(i=0;i<l2;i++)
        sum_out=sum_out+this->s.getAll()[i].getMoney();
    cout<<sum_in-sum_out;
}

void UI::suma_tip()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],day[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(type,cuvant);
    k=0;
    int ids[101],l=0;
    this->s.getID_byType(type, ids, l);
    int sum=0;
    for(i=0;i<l1;i++)
        sum=sum+this->s.getAll()[i].getMoney();
    cout<<sum;
}

void UI::max_tip()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],type[101],day[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            if(ok==1)
            {
                strcpy(type,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(day,cuvant);
    k=0;
    int zi;
    for(i=0;i<strlen(day);i++)
    {
        int x=day[i]-'0';
        zi=zi*10+x;
    }
    int ids[101],l=0;
    this->s.getID_byType(type, ids, l);
    int max=0;
    for(i=0;i<l1;i++)
        if(s.getAll()[i].getMoney()>max and s.getAll()[i].getDay()==zi)
            max=s.getAll()[i].getMoney();
    if(max!=0)
        cout<<max;
    else
        cout<<"Nu sunt tranzactii in aceasta zi."

}

void UI::filtru_tip()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],type[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(type,cuvant);
    k=0;
    char type2[101];
    if(type=="in")
        type2="out";
    if(type=="out")
        type2=="in";
    int ids[101],l=0;
    this->s.getID_byType(type2, ids, l);
    for(i=0;i<l;i++)
        this->s.deleteBank(ids[i]);
}

void UI::filtru_tip_valoare()
{
    int k=0,ok,i,n;
    char cuvant[101],operatie[101],type[101],money[101];
    n=strlen(this->comanda);
    ok=0;
    for(i=0;i<n;i++)
        if(this->comanda[i]!=' ')
            cuvant[k++]=this->comanda[i];
        else
        {
            cuvant[k]='\0';
            if(ok==0)
            {
                strcpy(operatie,cuvant);
                ok++;
                k=0;
            }
            if(ok==1)
            {
                strcpy(type,cuvant);
                ok++;
                k=0;
            }
        }
    cuvant[k]='\0';
    strcpy(money,cuvant);
    k=0;
    int bani;
    for(i=0;i<strlen(money);i++)
    {
        int x=money[i]-'0';
        bani=bani*10+x;
    }
    int ids[101],l=0;
    this->s.getID_byType(type2, ids, l);
    for(i=0;i<l;i++)
        if(this->s.getAll()[i].getMoney()>bani)
            this->s.deleteBank(ids[i]);
}

void UI::undo()
{
    
}





void UI::numarCuvinte()
{
    int i,n,k=0,ok=1;
    char cuvant1[101],cuvant2[101];
    cin.getline(this->comanda, 101);
    n=strlen(this->comanda);
    int nrCuv=0;
    for(i=0;i<n;i++)
    {
        if(this->comanda[i]==' ')
        {
            nrCuv++;
            if(ok==1)
            {
                cuvant1[k]='\n';
                ok++;
            }
            else if(ok==2)
            {
                cuvant2[k]='\n';
                ok++;
            }
        }
        else
        {   if(ok==1)
                cuvant1[k++]=this->comanda[i];
            if(ok==2)
                cuvant2[k++]=this->comanda[i];
        }
    }
    nrCuv++;
    if(nrCuv==1)
    {
         if(cuvant1=="undo")
             this->undo();
        else if(cuvant1=="listeaza")
            this->listare_all();
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else if(nrCuv==2)
    {
        if(cuvant1=="eliminare")
        {
            if(cuvant2=="in" or cuvant2=="out")
                this->eliminare_tip();
            else if(doarCrife(cuvant2)==1)
                this->eliminare_nr();
            else
            {
                cout<<"Comanda nu exista";
                this->numarCuvinte();
            }
        }
        
        else if(cuvant1=="listeaza")
            this->listeaza_tip();
        else if(cuvant1=="filtru")
            this->filtru_tip();
        else if(cuvant1=="sum")
            this->suma_tip;
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else if(nrCuv==3)
    {
        if(cuvant1=="listeaza")
        {
            if(doarSemne(cuvant2)==1)
                this->listare_suma();
            else if(cuvant2=="sol" or cuvant2=="sold")
                this->listare_sold();
            else
            {
                cout<<"Comanda nu exista";
                this->numarCuvinte();
            }
        }
        else if(cuvant1=="max")
            this->max_tip();
        else if(cuvant1=="filtru")
            this->filtru_tip_valoare();
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else if(nrCuv==4)
    {
        if(cuvant1=="adauga")
            this->adaugare();
        else if(cuvant1="eliminare")
            this->eliminare_nr_la_nr();
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else if(nrCuv==5)
    {
        if(cuvant1=="insereaza")
            this->inserare();
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else if(nrCuv==6)
    {
        if(cuvant1=="inlocuire")
            this->inlocuire();
        else
        {
            cout<<"Comanda nu exista";
            this->numarCuvinte();
        }
    }
    else
    {
        cout<<"Comanda nu exista";
        this->numarCuvinte();
    }
}


    
