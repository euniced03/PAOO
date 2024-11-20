#include <iostream>
#include <string>

// Item 4: Make sure that objects are initialized before they’re used
//Item 5: Know what functions C++ silently writes and calls
// Item 6: Explicitly disallow the use of compiler generated functions you do not want
class Serial {
    std::string nume;
    int episoade;

public:
    Serial(const std::string& nume, int episoade)
        : nume(nume), episoade(episoade) {}

    //Copy constructor
    /*Serial(const Serial& other)
        : nume(other.nume), episoade(other.episoade) {
        std::cout << "Serialul '" << this->nume << "' a fost copiat prin copy constructor.\n";
    }*/

    Serial(const Serial&) = delete; // stergere functie copy constructor generata automat
    Serial& operator=(const Serial&) = delete; // stergere functie operator de atribuire generata automat

    void afiseaza() const {
        std::cout << "Nume serial: " << nume << ", episoade: " << episoade << "\n";
    }
    //Destructor
    ~Serial() {
        std::cout << "Serial '" << nume << "' distrus prin destructor.\n";
    }
};



int main() {
    // Item 4: initislizarea obiectului t1
    Serial s1("Prison Break", 150);
    s1.afiseaza();

    // Creem un alt obiect serial prin copiere
    //Serial s2 = s1; // acum vom avea eroare aici, copy constructorul a fost sters cu delete
    //s2.afiseaza();

    Serial s3("Arrow", 100);
    s3.afiseaza();
    //s3 = s1; //aici vom avea eroare daca incercam sa atribuim obiectului t3 pe t1, pt ca operatorul de atribuire a fost sters cu delete
    return 0;
}