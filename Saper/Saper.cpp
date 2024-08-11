// Saper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Field.h"

void End(Field& field, bool& close) {
    char answ;

    Color::RPrint(field.IsWin() ? "Вы победили!" : "Вы проиграли :(",
        field.IsWin() ? Color::Green : Color::Red);
    Color::RPrint("\nНачать заново?", Color::Yellow);
    Color::RPrint("y", Color::LightGreen);
    std::cout << "/";
    Color::RPrint("n", Color::LightRed);
    std::cout << " ";
    std::cin >> answ;

    if (answ == 'y') {
        clear();
        field.Restart(Setting());
        close = false;
        return;
    }

    close = true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    Field field(Setting());
    bool close = false;

    while (!close) {
        field.Show();
        if (field.IsOver()) {
            End(field, close);
            clear();
            continue;
        }

        field.Action(Key::GetKey());
        clear();
    }

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