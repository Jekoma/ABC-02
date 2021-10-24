#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <string>
#include "container.cpp"


int main(int argc, char* argv[])
{
    // Проверка на входные данные
    if (argc != 5) {
        std::cout << "Wrong input! argc != 5";
        return 1;
    }
    // Старт программы
    std::cout << "Start \n" << "\n";
    container c;
    c.Init(c);

    // Входные данные = текстовый файл
    if (!strcmp(argv[1], "-tests")) {
        std::ifstream ifst(argv[2]);
        c.In(c, ifst);
    }
    // Входные данные = через рандомайзер
    else if (!strcmp(argv[1], "-random")) {

        auto size = stoi(argv[2]);        
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of strings = "
                << size
                << ". Set 1 <= number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел        
        c.InRnd(c, size);
    }
    else {
        std::cout << " you need to put: task01.exe -random number outfile1 outfile2  or task01.exe -tests inputfile outfile1 outfile2";
        return 2;
    }

    // Вывод содержимого контейнера в файл
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(c, ofst1);

    // 2я часть задания
    std::ofstream ofst2(argv[4]);
    c.Selection(c, ofst2);

    //очистка контейнера
    c.Clear(c);
    std::cout << "Stop" << std::endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
