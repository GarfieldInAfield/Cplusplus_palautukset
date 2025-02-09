#include <iostream>
#include <string>


class Pankkitili {
protected:
    double saldo;
    std::string omistaja;

public:
    Pankkitili(const std::string& nimi) : saldo(0), omistaja(nimi) {}
    virtual ~Pankkitili() {}

    virtual bool deposit(double amount) {
        if (amount > 0) {
            saldo += amount;
            return true;
        }
        std::cout << "Et voi tallentaa negatiivista summaa\n";
        return false;
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= saldo) {
            saldo -= amount;
            return true;
        }
        std::cout << "Nostoa ei voida suorittaa.\n";
        return false;
    }

    double getBalance() const { return saldo; }
};

class Luottotili : public Pankkitili {
private:
    double luottoraja;

public:
    Luottotili(const std::string& nimi, double raja) : Pankkitili(nimi), luottoraja(raja) {}

    bool withdraw(double amount) override {
        if (amount > 0 && (saldo - amount) >= -luottoraja) {
            saldo -= amount;
            return true;
        }
        std::cout << "Virhe: ylität luottorajan.\n";
        return false;
    }

    bool deposit(double amount) override {
        if (amount > 0 && saldo + amount <= 0) {
            saldo += amount;
            return true;
        }
        std::cout << "Virhe: Maksu ei voi olla negatiivinen tai ylittää velkaa.\n";
        return false;
    }
};

class Asiakas {
private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& n, double luottoraja)
        : nimi(n), kayttotili(n), luottotili(n, luottoraja) {}

    std::string getNimi() const {
        return nimi;
    }

    void showSaldo() const {
        std::cout << nimi << " - Pankkitilin saldo: " << kayttotili.getBalance() << " EUR\n";
        std::cout << nimi << " - Luottotilin saldo: " << luottotili.getBalance() << " EUR\n";
    }

    bool talletus(double amount) {
        return kayttotili.deposit(amount);
    }

    bool nosto(double amount) {
        return kayttotili.withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili.deposit(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili.withdraw(amount);
    }

    bool tiliSiirto(double amount, Asiakas& vastaanottaja) {
        if (amount > 0 && kayttotili.withdraw(amount)) {
            return vastaanottaja.talletus(amount);
        }
        std::cout << "Tilisiirto epäonnistui.\n";
        return false;
    }
};

int main() {
    Asiakas asiakas1("Matti Meikäläinen", 1000.0);
    Asiakas asiakas2("Maija Meikäläinen", 1000.0);

    asiakas1.talletus(900);
    asiakas1.nosto(1100);
    //asiakas1.luotonNosto(700);
    //asiakas1.luotonMaksu(10000);

    //kommentoimalla saa testattua termejä, otan kuvia eri ehdoilla

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    double siirtosumma = 2200; //esimerkki luku rahalle jota siirretään
    //doublen olisi voinut sijoittaa paremmin 

    std::cout << "Tilisiirto " << siirtosumma << "EUR, käyttäjältä " << asiakas1.getNimi() << " käyttäjälle " << asiakas2.getNimi() << "\n";
    asiakas1.tiliSiirto(siirtosumma, asiakas2);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
