#include "cont_economii.h"

ContEconomii::ContEconomii(std::string n, double s, double d) 
    : ContBancar(n, s), dobanda(d) {
    std::cout << "Contul de economii al titularului " << titular << " a fost creat cu soldul de " 
              << sold << " lei si dobanda de " << dobanda << "%.\n";
}

ContEconomii::~ContEconomii() {
    std::cout << "Contul de economii al titularului " << titular << " a fost inchis.\n";
}

void ContEconomii::afiseazaDetalii() const {
    std::cout << "Cont Economii - Titular: " << titular << ", Sold: " << sold << " lei, Dobanda: " << dobanda << "%\n";
}
