// algocpp_homework_06_2.cpp 

#include <iostream>
#include <Windows.h>
#include <math.h>


int real_string_hash(std::string str,int p,int n)
{
    int sum = 0;
    for (int i = 0; i < str.size();i++) 
    {
        sum = sum + (int)(str[i])* static_cast <int> (pow(p,i));
    }
    return (sum % n);
}

int main()
{
    system("chcp 1251");
    system("cls");
    std::string str="";
    int p = 0;
    int n = 0;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    while (str != "exit") 
    {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Хэш строки " << str << " = " << real_string_hash(str,p,n) << std::endl;
    }
    return 0;
}