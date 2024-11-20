#include <iostream>
using namespace std;

class Tren {
private:
    int* elements;
    int size;

public:
    // Constructor pentru a inițializa un tren de dimensiune fixă
    Tren(int dim) : size(dim) {
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = 0;  // Inițializăm fiecare element cu 0
        }
    }

    
    Tren(int dim, int vals[]) : size(dim) {
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = vals[i];
        }
    }

    //Copy constructor
    Tren(const Tren& other) : size(other.size) {
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
        cout << "Copy constructor: " << endl;  
    } 

    /* suprascrie copy constructor
    Tren(const Tren& other) : size(other.size), elements(other.elements){
        
        
        cout << "Suprascrie Copy constructor: " << endl;  
    } */

     // Move constructor
    Tren(Tren&& other) noexcept : size(other.size), elements(other.elements) {
        cout << "Move constructor: " << endl;
        other.elements = nullptr; // Eliberăm referința din obiectul sursă
        
    }
   


    //destructor pentru a elibera memoria
    ~Tren() {
        delete[] elements;
        cout<<"Destructor pentru tren"<<endl;
    }

    // metoda pentru adunare
    Tren add(const Tren& other) const {
        Tren result(size);
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // metoda pt afisarea trenului
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << elements[i]<<" ";
        }
        cout<<endl;
        
    }

      
    void copyAndModify() {
        for (int i = 0; i < size; i++) {
            elements[i] = 1; 
        }
        cout << "Toate vagoanele au fost setate pe 1: " << endl;  
    }
};

int main() {
    // initializarea trenului
    int elems1[] = {1, 2, 3};
    int elems2[] = {4, 5, 6};
    int dim = 3;

    Tren t1(dim, elems1);
    Tren t2(dim, elems2);

    t1.print();
    t2.print();
    Tren sum = t1.add(t2);
    sum.print();


    // folosim constructorul de copiere
    Tren t3(t1);  
    cout << "Trenul copiat (t3): ";
    t3.print();

    
    cout << "Tren original (t1): ";
    t1.print();
   

    t3.copyAndModify(); 
    cout << "Trenul t3 după setAllToOne: "<<endl;
    t3.print();
    cout<<"Asa arata vagoanele lui t1 acum: ";
    t1.print(); 
    //destructorul va incerca sa elibereze memoria partajata, deci o eliberare dubla


    Tren t4(std::move(t1));
    cout<<"Tren mutat(t4): ";
    t4.print();

    // Verificam v1 pentru a vedea daca a fost afectat
    //cout << "Tren original (t1) dupa mutare: ";
    //t1.print(); // Ar trebui sa fie un pointer null
    
    
    return 0;
}
