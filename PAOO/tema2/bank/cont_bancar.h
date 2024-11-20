#ifndef CONT_BANCAR_H
#define CONT_BANCAR_H

#include <string>
#include <iostream>

class ContBancar {
protected:
    std::string titular;
    double sold;

public:
    ContBancar(std::string n, double s);
    virtual ~ContBancar();

    ContBancar(const ContBancar&) = delete;  // Interzicere constructor de copiere
    ContBancar& operator=(const ContBancar&) = delete;  // Interzicere operator de copiere

    ContBancar(ContBancar&&) = delete;  // Interzicere constructor de mutare
    ContBancar& operator=(ContBancar&&) = delete;  // Interzicere operator de mutare

    void afiseazaDetalii() const;
};

#endif // CONT_BANCAR_H
