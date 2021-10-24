#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <string>
#include "aforizm.cpp"
#include "poslovica.cpp"
#include "zagadka.cpp"
using namespace std;

class wisdom {
public:
    // значения ключей для каждой из строк
    enum key { AFORIZM, POSLOVICA, ZAGADKA };
    key k;
    // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию]
        aforizm a;
        poslovica p;
        zagadka z;
    };

    wisdom* In(ifstream& ifst) {
        wisdom* wm;
        int k;
        ifst >> k;
        switch (k) {
        case 1:
            wm = new wisdom;
            wm->k = wisdom::AFORIZM;  // Афоризм
            aforizm a;
            a.In(wm->a, ifst);
            return wm;
        case 2:
            wm = new wisdom;
            wm->k = wisdom::POSLOVICA;  // Пословицa
            poslovica p;
            p.In(wm->p, ifst);
            return wm;
        case 3:
            wm = new wisdom;
            wm->k = wisdom::ZAGADKA; // Загадка
            zagadka z;
            z.In(wm->z, ifst);
            return wm;
        default:
            return 0;
        }
    }

    //Случайный ввод мудрости
    wisdom* InRnd() {
        wisdom* wm;
        auto k = rand() % 3 + 1;
        switch (k) {
        case 1:
            wm = new wisdom;
            wm->k = wisdom::AFORIZM;
            aforizm a;
            a.InRnd(wm->a);
            return wm;

        case 2:
            wm = new wisdom;
            wm->k = wisdom::POSLOVICA;
            poslovica p;
            p.InRnd(wm->p);
            return wm;

        case 3:
            wm = new wisdom;
            wm->k = wisdom::ZAGADKA;
            zagadka z;
            z.InRnd(wm->z);
            return wm;

        default:
            return 0;
        }
    }

    //------------------------------------------------------------------------------
    // Вывод параметров текущей мудрости
    void Out(wisdom& w, ofstream& ofst) {
        switch (w.k) {
        case wisdom::AFORIZM:
            aforizm a;
            a.Out(w.a, ofst);
            break;
        case wisdom::POSLOVICA:
            poslovica p;
            p.Out(w.p, ofst);
            break;
        case wisdom::ZAGADKA:
            zagadka z;
            z.Out(w.z, ofst);
            break;
        default:
            ofst << "Incorrect String!" << endl;
        }
    }

    //-------
    //Вычисление частного

    double Chastnoe(wisdom& w) {
        switch (w.k) {
        case wisdom::AFORIZM:
            aforizm a;
            return a.Chastnoe(w.a);
            break;
        case wisdom::POSLOVICA:
            poslovica p;
            return p.Chastnoe(w.p);
            break;
        case wisdom::ZAGADKA:
            zagadka z;
            return z.Chastnoe(w.z);
            break;
        default:
            return 0.0;
        }
    }



};