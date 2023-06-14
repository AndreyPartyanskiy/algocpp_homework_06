// algocpp_homework_06_3.cpp 

#include <iostream>
#include <Windows.h>
#include <math.h>
#include <string>

int simple_string_hash(std::string str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum = sum + (int)(str[i]);
    }
    return sum;
}

int find_substring_light_rabin_karp (std::string str, std::string sub_str)
{
    int hash_string=0;
    int hash_sub_string = simple_string_hash(sub_str);
    std::string temp_str;
    int comp;
    
    for (int i = 0; i < (str.size() - sub_str.size()+1); i++)
    {
        if (i == 0) 
        { 
            hash_string = simple_string_hash(str.substr(0,sub_str.size())); 
        }
        else 
        {
            hash_string = hash_string - (int)(str[i - 1]) + (int)(str[i + (sub_str.size()-1)]);
        }
        if (hash_string == hash_sub_string) 
        {
            comp = sub_str.compare(str.substr(i, sub_str.size()));
            if (comp==0) return i;   
        }
    }
    return (-1);
}

int main()
{
    system("chcp 1251");
    system("cls");
    std::string str="";
    std::string sub_str = "";
    int mark_str=0;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;
    
    while (sub_str != "exit") 
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> sub_str;
        mark_str = find_substring_light_rabin_karp(str, sub_str);
        if (mark_str != -1)  std::cout << "Подстрока " << sub_str << " найдена по индексу " << mark_str << std::endl;
        else std::cout << "Подстрока " << sub_str << " не найдена " << std::endl;
    }
    return 0;
}