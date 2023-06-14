// algocpp_homework_06_1.cpp 

#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string str) 
{
    int sum = 0;
    for (int i = 0; i < str.size();i++) 
    {
        sum = sum + (int)(str[i]);
    }
    return sum;
}

int main()
{
    system("chcp 1251");
    system("cls");
    std::string str="";
    while (str != "exit") 
    {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
    }
    return 0;
}
