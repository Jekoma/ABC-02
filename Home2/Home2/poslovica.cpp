#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <string>
using namespace std;
#define N 21
#define SET "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789,<>""'';:!(){}"

class poslovica {
public:
    char  input[10000]; // Входная строка
    char  answer[10000]; // Страна

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

    void In(poslovica& p, ifstream& ifst) {
        ifst.getline(p.input, sizeof(p.input));
    }

    // Получение данных через рандомайзер
    void InRnd(poslovica& p) {
        for (size_t i = 0; i < 21; i++) {
            p.input[i] = myRandom()[i];
        }
        p.input[9] = ' ';
        p.input[10] = '-';
        p.input[11] = ' ';
    }
    // Вывод данных
    void Out(poslovica& p, ofstream& ofst) {
        ofst << "It is Poslovica, input = ";
        for (int i = 0; i < strlen(p.input); i++) {
            ofst << p.input[i];
        }
        ofst << " CHASTNOE = " << Chastnoe(p) << "   STRANA = " << p.answer << " \n";
    }

    // Вычисление частного
    double Chastnoe(poslovica& p) {
        double X;
        double count = 0.0, x = 0.0;
        int xx = 0;
        int i = 0;

        do {
            if (p.input[i] == '-') {
                xx++;
            }
            i++;
        } while (xx == 0 && sizeof(p.input));
        x = i;
        copy(p.input + i, p.input + strlen(p.input), p.answer);
        for (int i = 0; i < sizeof(p.input); i++) {
            if (p.answer[i] == '.') {
                p.answer[i + 1] = '\0';
                break;
            }
        }
        for (int j = 0; j < strlen(p.answer); j++) {
            if (p.answer[j] == '.' || p.answer[j] == ',' || p.answer[j] == ';' || p.answer[j] == ':' || p.answer[j] == '-' ||
                p.answer[j] == '?' || p.answer[j] == '!' || p.answer[j] == '(' || p.answer[j] == ')' || p.answer[j] == '"' ||
                p.answer[j] == '<' || p.answer[j] == '>' || p.answer[j] == '{' || p.answer[j] == '}') {
                count++;
            }
        }
        X = strlen(p.answer) / count;
        return X;
    }
};