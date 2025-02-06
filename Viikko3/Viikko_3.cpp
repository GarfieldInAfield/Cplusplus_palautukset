#include <iostream>
using namespace std;

// Chef-luokka
class Chef {
protected:
    string chefName;  //periytyy

public:
    // Konstruktori
    Chef(string name) : chefName(name) {
        cout << "Chef (konstruktori) " << chefName << " created." << endl;
    }

    // Destruktori
    ~Chef() {
        cout << "Chef (konstruktori) " << chefName << " deleted." << endl;
    }

    //palautetaan kokin nimi
    string getName() {
        return chefName;
    }
};

//italianChef perii Chef-luokan
class ItalianChef : public Chef {
private:
    string password = "pizza";  // Salasana asetettu oletusarvoksi
    int flour;  // Jauhojen määrä
    int water;  // Veden määrä

    // makePizza on yksityinen funktio
    int makePizza(int flourAmount, int waterAmount) {
        int pizzas = min(flourAmount / 5, waterAmount / 5); // Yksi pizza tarvitsee 5 jauhoa ja 5 vettä
        cout << "ItalianChef " << chefName << " made " << pizzas << " pizzas!" << endl;
        return pizzas;
    }

public:
    // Konstruktori
    ItalianChef(string name) : Chef(name), flour(0), water(0) {
        cout << "ItalianChef " << chefName << " starts working!" << endl;
    }

    // Destruktori
    ~ItalianChef() {
        cout << "ItalianChef " << chefName << " went home." << endl;
    }

    //salasana
    bool askSecret(string inputPassword, int flourAmount, int waterAmount) {

        if (inputPassword == password) {
            makePizza(flourAmount, waterAmount);
            return true;
        }

        else {
            cout << "Wrong password! Access denied." << endl;
            return false;
        }
    }
};


//testaan useilla ehdoilla
int main() {

    ItalianChef mario("Luigi");  //aluksi nimetään luigi

    //mario.askSecret("pizza", 20, 20);  //oikea salasana + extra aineksia testiksi
    mario.askSecret("pizza", 50, 60);  //oikea salasana + extra aineksia testiksi

    //mario.askSecret("pasta", 20, 20);  //väärä salasana
    //mario.askSecret("pasta", 500, 600);  //väärä salasana + extra aineksia

    return 0;
}
