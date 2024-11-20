#include <iostream>
#include "cont_bancar.h"
#include "cont_economii.h"

int main() {
    // Crearea unui obiect de tip ContBancar
    ContBancar cont1("Ion Popescu", 1500.0);
    cont1.afiseazaDetalii(); // Afișează detaliile contului bancar

    // Crearea unui obiect de tip ContEconomii
    ContEconomii cont2("Maria Ionescu", 5000.0, 2.5);
    cont2.afiseazaDetalii(); // Afișează detaliile contului de economii

     std::cout << "\nDistrugere obiecte:\n";
    // Aici, obiectele cont1 și cont2 vor ieși din scope și vor fi distruse automat.
    // Mesajele corespunzătoare din destructorii claselor vor fi afișate la finalul execuției.
    
    return 0;
}
