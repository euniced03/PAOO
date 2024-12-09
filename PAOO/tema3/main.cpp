#include <iostream>
#include <cstring>

class Serial {
    char* nume;
    int episoade;

public:
    // Constructor implicit
    Serial(const char* numeInitial = "", int episoadeInitial = 0)
        : episoade(episoadeInitial) {
        nume = new char[strlen(numeInitial) + 1];
        strcpy(nume, numeInitial);
    }

    // Constructor de copiere (pentru deep copy)
    Serial(const Serial& other)
        : episoade(other.episoade) {
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        std::cout << "Serialul '" << other.nume << "' a fost copiat prin constructorul de copiere.\n";
    }

    // Operator de atribuire
    Serial& operator=(const Serial& other) {
        // Item 11: Verificare auto-atribuire
        if (this == &other) {
            return *this;
        }

        // Eliberăm resursele existente
        delete[] nume;

        // Copiem toate componentele (Item 12)
        episoade = other.episoade;
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);

        std::cout << "Serialul '" << other.nume << "' a fost atribuit prin operator=.\n";

        // Item 10: Returnăm referința la obiectul curent
        return *this;
    }

    // Destructor
    ~Serial() {
        //delete[] nume;
        std::cout << "Serialul '" << nume << "' distrus prin destructor.\n";
    }

    // Funcție pentru afișare
    void afiseaza() const {
        std::cout << "Nume serial: " << nume << ", episoade: " << episoade << "\n";
    }
};

int main() {
    // Creăm un obiect Serial
    Serial s1("Prison Break", 150);
    s1.afiseaza();

    // Copiem un obiect Serial folosind constructorul de copiere
    Serial s2 = s1;
    s2.afiseaza();

    // Creăm un alt obiect Serial
    Serial s3("Arrow", 100);
    s3.afiseaza();

    // Folosim operatorul de atribuire
    s3 = s1;
    s3.afiseaza();

    // Testăm auto-atribuirea
    s1 = s1;

    return 0;
}
