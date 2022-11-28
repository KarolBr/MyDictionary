#include <iostream>
#include "person.h"
#include "address.h"

int main() {


    std::vector<Person> people{{"Emilia","Plater",41}, {"Adam","Mickiewicz",53}, {"Juliusz","Slowacki",57}, {"Fryderyk","Chopin",34}};

    Person person{"Albert","Einstein",42};

    Person person1{"Albert","Einstein",121};

    Address addr{"Wojska Polskiego","12","Warszawa","00-950","Warszawa"};

    Person pati;
    pati.setAddress(addr);
    pati.setFirstName("Alfred");
    pati.setLastName("Nobel");
    pati.setAge(56);
    pati.setPhone("+48785412369","private");
    pati.setPhone("+48785416369","company");
    pati.setPhone("+48785412389","private");

    Person inny{pati};

    std::cout << person1;

    std::cout << pati;

    std::cout << inny;


    for(auto item: people)
    {
          std::cout << item;
    }



    return 0;
}
