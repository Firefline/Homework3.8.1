// Homework3.8.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class bad_length : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};
int function(std::string str, int forbidden_length)
{
    if (str.size() != forbidden_length)
    {
        return str.size();
    }
    else {
        throw bad_length();
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    int forbidden, num = 0;
    std::string word, temp;

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden;

    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> word;
        try
        {
            temp = function(word, forbidden);
        }
        catch (const bad_length& ex) { std::cout << ex.what() << std::endl; break; }
        std::cout << "Длина слова '" << word << "' равна " << word.size() << std::endl;
    }
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
