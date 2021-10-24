#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <string>
#include "wisdom.cpp"
using namespace std;

class container {
public:
    enum { max_len = 10000 }; // максимальная длина
    int len; // текущая длина

    wisdom* cont[max_len];


    void Init(container& c) {
        c.len = 0;
    }

    //------------------------------------------------------------------------------
    // Очистка контейнера от элементов (освобождение памяти)
    void Clear(container& c) {
        for (int i = 0; i < c.len; i++) {
            delete c.cont[i];
        }
        c.len = 0;
    }

    //------------------------------------------------------------------------------
    // Ввод содержимого контейнера из указанного потока
    void In(container& c, std::ifstream& ifst) {
        while (!ifst.eof()) {
            wisdom w;
            if ((c.cont[c.len] = w.In(ifst)) != 0) {
                c.len++;
            }
            else {
                char s[10000];
                ifst.getline(s, sizeof(s));
            }
        }
    }

    //------------------------------------------------------------------------------
    // Случайный ввод содержимого контейнера

    void InRnd(container& c, int size) {
        while (c.len < size) {
            wisdom w;
            if ((c.cont[c.len] = w.InRnd()) != nullptr) {
                c.len++;
            }
        }
    }

    //------------------------------------------------------------------------------
    // Вывод содержимого контейнера в указанный поток
    void Out(container& c, std::ofstream& ofst) {
        ofst << "Container contains " << c.len << " elements." << "\n";
        for (int i = 0; i < c.len; i++) {
            wisdom w;
            ofst << i << ": ";
            w.Out(*(c.cont[i]), ofst);
        }
    }

    //------------------------------------------------------------------------------
    // Функция сортировки прямым выбором
    void Selection(container& c, std::ofstream& ofst)
    {
        int max;
        container newcont;
        wisdom* w;
        for (int i = 0; i < c.len - 1; i++) {
            max = i; // запоминаем индекс текущего элемента
            // ищем максимальный элемент чтобы поместить на место i-ого
            wisdom ww;
            for (int j = i + 1; j < c.len; j++)  // для остальных элементов после i-ого
            {
                if (ww.Chastnoe(*(c.cont[j])) > ww.Chastnoe(*(c.cont[max]))) // если элемент больше максимального,
                    max = j;       // запоминаем его индекс в max
            }
            w = c.cont[i];      // меняем местами i-ый и максимальный элементы
            c.cont[i] = c.cont[max];
            c.cont[max] = w;
        }

        ofst << "Selected container contains " << c.len << " elements." << "\n";
        for (int i = 0; i < c.len; i++) {
            wisdom w;
            ofst << i << ": ";
            w.Out(*(c.cont[i]), ofst);
        }
    }
};