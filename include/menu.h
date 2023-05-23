#pragma once

#include <iostream>
#include "Dictionary.h"
#include "MyFile.h"


std::string menu_text()
{
    std::string k1{"1 - Dodaj nowe słowo\n"};
    std::string k2{"2 - Pokaż wszystkie słówka\n"};
    std::string k3{"3 - Koniec\n"};
    std::string k4{"Wybierz odpowiednią opcję i nacisnij ENTER\n"};

    return k1 + k2 + k3 + k4;
}

int get_answer()
{
    //int my_choice{};
    char choice{};
    std::string _clear;
    std::cin >> choice;

    if (isdigit(choice))
    {
        std::cin.clear();
        std::getline(std::cin, _clear);
        return choice - '0';
    }
    else
    {   
        std::cin.clear();
        std::getline(std::cin, _clear);
        return 100;
    }
}

void add_word_to_dict(MyFile &m,Dictionary &d)
{
    std::string new_word{};
    std::string new_meaning{};
    std::string new_sentence{};

    std::cout << "Wpisz słówko\n";
    std::getline(std::cin,new_word);
    std::cout << "Wpisz znaczenie\n";
    std::getline(std::cin,new_meaning);
    std::cout << "Wpisz przykładowe zdanie\n";
    std::getline(std::cin,new_sentence);
    //std::cin >> new_sentence;
    Word w(new_word,new_meaning);
    w.setExampleSentences(new_sentence);
    d.addWord(w);
    m.saveFile(d);
    std::cin.clear();
}

void save_dictionary(MyFile &m,Dictionary &d)
{
    m.saveFile(d);
}

void menu()
{

    bool end{false};

    Dictionary dict;
    MyFile my_file{"dictionary.csv"};

    while (!end)
    {
        std::cout << menu_text();

        
        switch (get_answer())
        {
        case 1:
            add_word_to_dict(my_file,dict);
            break;
        case 2:
            //save_dictionary(my_file,dict);
            std::cout<<"This functionality is not implemented yet!\n";
            break;
        case 3:
            end = true;
            break;
        default:
            std::cout << "Wybierz poprawna opcje!\n";
            break;
        }
    }
}