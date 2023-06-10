#pragma once

#include <iostream>
#include "Dictionary.h"
#include "MyFile.h"

std::string menu_text()
{
    std::string k1{"1 - Dodaj nowe słowo\n"};
    std::string k2{"2 - Pokaż wszystkie słówka\n"};
    std::string k3{"3 - Pokaż rozmiar słownika\n"};
    std::string k4{"4 - Koniec\n"};
    std::string k5{"Wybierz odpowiednią opcję i nacisnij ENTER\n"};

    return k1 + k2 + k3 + k4;
}

void read_file_print_dict(MyFile &m, Dictionary &d)
{
    d.cleanDictionary();
    m.loadFile(d);
    for (auto w : d.getWords())
        std::cout << w << "\n";
}

int get_answer()
{
    // int my_choice{};
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

void add_word_to_dict(MyFile &m, Dictionary &d)
{
    std::string new_word{};
    std::string new_meaning{};
    std::string new_sentence{};

    std::cout << "Wpisz słówko\n";
    std::getline(std::cin, new_word);
    std::cout << "Wpisz znaczenie\n";
    std::getline(std::cin, new_meaning);
    std::cout << "Wpisz przykładowe zdanie\n";
    std::getline(std::cin, new_sentence);
    // std::cin >> new_sentence;
    Word w(new_word, new_meaning);
    w.setExampleSentences(new_sentence);
    d.addWord(w);
    m.saveFile(d);
    std::cin.clear();
    d.cleanDictionary();
}

void save_dictionary(MyFile &m, Dictionary &d)
{
    m.saveFile(d);
}

void show_dict(MyFile &m, Dictionary &d)
{
    m.loadFile(d);

    for (Word w : d.getWords())
    {
        std::cout << w << "\n";
    }
    d.cleanDictionary();
}
void menu()
{

    bool end{false};
    MyFile my_file{"dictionary.csv"};
    Dictionary dict;

    while (!end)
    {
        std::cout << menu_text();

        switch (get_answer())
        {
        case 1:
            add_word_to_dict(my_file, dict);
            break;
        case 2:
            read_file_print_dict(my_file, dict);
            break;
        case 3:
            std::cout << "Rozmiar słownika: " << dict.sizeOfDictionary() << "\n";
            break;
        case 4:
            end = true;
            break;
        default:
            std::cout << "Wybierz poprawną opcję!\n";
            break;
        }
    }
}