#ifndef CONT_ECONOMII_H
#define CONT_ECONOMII_H

#include "cont_bancar.h"

class ContEconomii : public ContBancar {
private:
    double dobanda;

public:
    ContEconomii(std::string n, double s, double d);
    ~ContEconomii();

    void afiseazaDetalii() const override;
};

#endif // CONT_ECONOMII_H
