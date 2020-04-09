#include <iostream>
#include "Bank.h"
#include "Repo.h"
#include "Teste.h"
#include "Service.h"
#include "UI.h"
using namespace std;



int main()
{
    int curentDay;
    char* comanda;
    cout<<"Introduceti ziua curenta: ";
    cin>>curentDay;
    cout<<"Introduceti comanda: ";
    comanda=new char;
    cin.getline(comanda,101);
    UI ui;
    ui.numarCuvinte();
    
}
////meniul aplicatiei cu operatiile specifice
//void menu()
//{
//    cout << "Select option: " << endl;
//    cout << "1. Adauga cheltuiala " << endl;
//    cout << "2. Afisare cheltuieli" << endl;
//    cout << "3. Afisati numar de cheltuieli" << endl;
//    cout << "4. Delete dupa id" << endl;
//    cout << "5. Update dupa id" << endl;
//    cout << "6. Exit" << endl;
//    cout << endl;
//}
//
//
////functia principala
//int main()
//{
//    testAdd();
//    testRepo();
//    testeConstructor();
//    testGetter();
//    testSetter();
//    int nr, newDay, newMoney;
//    char type[10];
//    char desc[10];
//    int day = {}, money = {}, id = {} , id2={};
//    int ok = 1;
//    Repo r;
//    Service ser;
//    while (ok == 1)
//    {
//
//        menu();
//
//        int option;
//
//        cin >> option;
//        if (option == 1)
//        {
//            cout << "Introduceti id: ";
//            cin >> id;
//            cout << "Introduceti ziua: ";
//            cin >> day;
//            cout << "Introduceti suma de bani: ";
//            cin >> money;
//            cout << "Introduceti tipul de cheltuiala:  ";
//            cin >> type;
//            cout << "Introduceti descrierea: ";
//            cin >> desc;
//            cout << endl;
//
//            ser.addBank(id, day, money, type, desc);
//
//            cout << endl;
//
//        }
//        if (option == 2)
//        {
//            for (int i = 0; i < ser.getSize(); i++)
//            {
//                cout << ser.getAll()[i].getID() << " "<< ser.getAll()[i].getDay() << " " << ser.getAll()[i].getMoney() << " " << ser.getAll()[i].getType() << " " << ser.getAll()[i].getDesc()<<endl;
//            }
//            cout << endl;
//
//        }
//
//        if (option == 3)
//        {
//            cout << "Numarul de cheltuieli este " << ser.getSize() << endl;
//            cout << endl;
//
//            cout << endl;
//        }
//
//        /*
//        if (option == 6)
//        {
//            int resultLen;
//            resultLen = 0;
//            Bank result[5];
//            Bank* initialBank = r.getAll();
//            int len = r.getSize();
//            filterBank(initialBank, len, result, resultLen);
//            for (int i = 0; i < resultLen; i++)
//                cout << result[i];
//        }
//        */
//
//
//        if (option == 4)
//        {
//            int idNew;
//            cout << "Introduceti id-ul obiectului pe care doriti sa il stergeti: ";
//            cin >> idNew;
//            ser.deleteBank(idNew);
//        }
//        if (option == 5)
//        {
//            cout << "Introduceti id unde aveti modificari de facut: ";
//            cin >> id;
//            cout << "Introduceti noul id: ";
//            cin>> id2;
//            cout << "Introduceti ziua noua: ";
//            cin >> day;
//            cout << "Introduceti suma de bani noua: ";
//            cin >> money;
//            cout << "Introduceti tipul de cheltuiala noua:  ";
//            cin >> type;
//            cout << "Introduceti descrierea noua: ";
//            cin >> desc;
//            cout << endl;
//            ser.updateBank(id, id2, day, money, type, desc);
//        }
//        if (option == 6)
//            ok = 0;
//    }
//
//}
