#include <iostream>
#include <string>

// Item 4: Make sure that objects are initialized before they’re used
//Item 5: Know what functions C++ silently writes and calls
// Item 6: Explicitly disallow the use of compiler generated functions you do not want
class Tren {
    std::string nume;
    int vagoane;

public:
    Tren(const std::string& nume, int vagoane)
        : nume(nume), vagoane(vagoane) {}

    //Copy constructor
    /*Tren(const Tren& other)
        : nume(other.nume), vagoane(other.vagoane) {
        std::cout << "Trenul '" << this->nume << "' a fost copiat prin copy constructor.\n";
    }*/

    Tren(const Tren&) = delete; // stergere functie copy constructor generata automat
    Tren& operator=(const Tren&) = delete; // stergere functie operator de atribuire generata automat

    void afiseaza() const {
        std::cout << "Nume tren: " << nume << ", Vagoane: " << vagoane << "\n";
    }
    //Destructor
    ~Tren() {
        std::cout << "Tren '" << nume << "' distrus prin destructor.\n";
    }
};



int main() {
    // Item 4: initislizarea obiectului t1
    Tren t1("IR 797", 4);
    t1.afiseaza();

    // Creem un alt obiect Tren prin copiere
    //Tren t2 = t1; // acum vom avea eroare aici, copy constructorul a fost sters cu delete
    //t2.afiseaza();

    Tren t3("R 13708", 6);
    t3.afiseaza();
    //t3 = t1; //aici vom avea eroare daca incercam sa atribuim obiectului t3 pe t1, pt ca operatorul de atribuire a fost sters cu delete
    return 0;
}