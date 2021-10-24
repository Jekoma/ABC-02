#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <string>
using namespace std;
#define N 21
#define SET "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789,<>""'';:!(){}"

class aforizm {
public:
    char input[10000];
    char answer[10000];

    char* myRandom() {
        char s[N];
        int i, set_len;
        set_len = strlen(SET);
        for (i = 0; i < N - 1; i++) {
            s[i] = SET[rand() % set_len];
        }
        s[19] = '.';
        s[20] = '\0';
        return s;
    }
    // Чтение данных из файла
    static void In(aforizm& a, ifstream& ifst) {
        ifst.getline(a.input, sizeof(a.input));
    } 

    // Получение рандомных данных
    void InRnd(aforizm& a) {        
        for (int i = 0; i < 21; i++) {
            a.input[i] = myRandom()[i];
        }
        a.input[9] = ' ';
        a.input[10] = '|';
        a.input[11] = ' ';
    }

    // Вывод в файл
    void Out(aforizm& a, ofstream& ofst) {
        ofst << "It is Aforizm, input = ";
        for (int i = 0; i < strlen(a.input); i++) {
            ofst << a.input[i];
        }
        ofst << " CHASTNOE = " << Chastnoe(a) << "   AVTOR = " << a.answer << " \n";
    }



    // Вычисление частного
    double Chastnoe(aforizm& a) {
        double X;
        double count = 0.0, x = 0.0;
        int xx = 0;
        int i = 0;

        do {
            if (a.input[i] == '|') {
                xx++;
            }
            i++;
        } while (xx == 0 && i < sizeof(a.input));
        x = i;

        copy(a.input + i, a.input + strlen(a.input), a.answer);
        for (int i = 0; i < sizeof(a.answer); i++) {
            if (a.answer[i] == '.') {
                a.answer[i + 1] = '\0';
                break;
            }
        }
        for (int j = 0; j < strlen(a.answer); j++) {
            if (a.answer[j] == '.' || a.answer[j] == ',' || a.answer[j] == ';' || a.answer[j] == ':' || a.answer[j] == '-' ||
                a.answer[j] == '?' || a.answer[j] == '!' || a.answer[j] == '(' || a.answer[j] == ')' || a.answer[j] == '"' ||
                a.answer[j] == '<' || a.answer[j] == '>' || a.answer[j] == '{' || a.answer[j] == '}') {
                count++;
            }
        }
        X = strlen(a.answer) / count;
        return X;
    }

};