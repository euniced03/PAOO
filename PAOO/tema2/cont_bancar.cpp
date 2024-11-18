#include "cont_bancar.h"

ContBancar::ContBancar(std::string n, double s) : titular(n), sold(s) {
    std::cout << "Contul bancar al titularului " << titular << " a fost creat cu soldul de " << sold << " lei.\n";
}

ContBancar::~ContBancar() {
    std::cout << "Contul bancar al titularului " << titular << " a fost inchis.\n";
}

void ContBancar::afiseazaDetalii() const {
    std::cout << "Cont Bancar - Titular: " << titular << ", Sold: " << sold << " lei\n";
}
