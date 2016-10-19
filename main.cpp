#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>

#include "hash.h"

enum {AddElement = 1,FindElement,RemoveElement,ShowKeys,ShowValue,ShowTable,Exit};

int main()
{
    hash Hashy;
    std::string name = "",drink = "";
    int choose;

    Hashy("Paul","Locha");
    Hashy("Kim","Iced Mocha");
    Hashy("Emma","Strawberry Smoothy");
    Hashy("Annie","Hot Chocolate");
    Hashy("Sarah","Passion Tea");
    Hashy("Pepper","Caramel Mocha");
    Hashy("Mike","Chai Tea");
    Hashy("Steve","Apple Cider");
    Hashy("Bill","Root Beer");
    Hashy("Marie","Skinny Latte");
    Hashy("Susan","Water");
    Hashy("Joe","Green Tea");


    do
    {
        system("cls");
        std::cout <<"Choose the action:\n"
               "1.Add new element in the hash table\n"
               "2.Find the element \n"
               "3.Remove the element\n"
               "4.Display the keys\n"
               "5.Display the values\n"
               "6.Display the table\n"
               "7.Exit\n";

        std::cin >> choose;
        switch(choose)
        {
            case AddElement:
                std::cout << "Enter the name to add :";
                std::cin >> name;
                std::cout << "Enter the value:";
                std::cin >> drink;
                Hashy(name,drink);
                getch();
                break;

            case FindElement:
                std::cout << "Enter the name to find :";
                std::cin >> name;
                std::cout << name << "'s value is " << Hashy[name] << std::endl;
                getch();
                break;

            case RemoveElement:
                std::cout << "Enter the name to remove:";
                std::cin >> name;
                Hashy.RemoveItem(name);
                getch();
                break;

            case ShowKeys:
                std::cout << " Keys of the table:\n";
                Hashy.PrintKeys();
                getch();
                break;

            case ShowValue:
                std::cout << " The table of values:\n";
                Hashy.PrintValues();
                getch();
                break;

            case ShowTable:
                std::cout << " The Hash Table" << std::endl;
                Hashy.DisplayTable();
                getch();
                break;

            case Exit:
                exit(0);

            default :
                getch();
                std::cout << "Incorrect choice!\n";
        }
    }while(true);

    return 0;
}
