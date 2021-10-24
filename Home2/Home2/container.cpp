#include <iostream>
#include <fstream>
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime>   // ��� ������� time()
#include <string>
#include "wisdom.cpp"
using namespace std;

class container {
public:
    enum { max_len = 10000 }; // ������������ �����
    int len; // ������� �����

    wisdom* cont[max_len];


    void Init(container& c) {
        c.len = 0;
    }

    //------------------------------------------------------------------------------
    // ������� ���������� �� ��������� (������������ ������)
    void Clear(container& c) {
        for (int i = 0; i < c.len; i++) {
            delete c.cont[i];
        }
        c.len = 0;
    }

    //------------------------------------------------------------------------------
    // ���� ����������� ���������� �� ���������� ������
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
    // ��������� ���� ����������� ����������

    void InRnd(container& c, int size) {
        while (c.len < size) {
            wisdom w;
            if ((c.cont[c.len] = w.InRnd()) != nullptr) {
                c.len++;
            }
        }
    }

    //------------------------------------------------------------------------------
    // ����� ����������� ���������� � ��������� �����
    void Out(container& c, std::ofstream& ofst) {
        ofst << "Container contains " << c.len << " elements." << "\n";
        for (int i = 0; i < c.len; i++) {
            wisdom w;
            ofst << i << ": ";
            w.Out(*(c.cont[i]), ofst);
        }
    }

    //------------------------------------------------------------------------------
    // ������� ���������� ������ �������
    void Selection(container& c, std::ofstream& ofst)
    {
        int max;
        container newcont;
        wisdom* w;
        for (int i = 0; i < c.len - 1; i++) {
            max = i; // ���������� ������ �������� ��������
            // ���� ������������ ������� ����� ��������� �� ����� i-���
            wisdom ww;
            for (int j = i + 1; j < c.len; j++)  // ��� ��������� ��������� ����� i-���
            {
                if (ww.Chastnoe(*(c.cont[j])) > ww.Chastnoe(*(c.cont[max]))) // ���� ������� ������ �������������,
                    max = j;       // ���������� ��� ������ � max
            }
            w = c.cont[i];      // ������ ������� i-�� � ������������ ��������
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