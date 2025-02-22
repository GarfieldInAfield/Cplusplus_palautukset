#include <iostream>
#include <string>

using namespace std;

// Seuraaja-luokka edustaa yksitt‰ist‰ seuraajaa
class Seuraaja {
    string nimi; // Seuraajan nimi

public:
    Seuraaja* next; // Osoitin seuraavaan seuraajaan

    // Konstruktori, joka alustaa seuraajan nimen ja next-osoittimen
    Seuraaja(const string& nimi) {
        this->nimi = nimi;
        next = nullptr;
    }

    // Palauttaa seuraajan nimen
    string getNimi() const {
        return nimi;
    }

    // Tulostaa viestin, jonka seuraaja saa
    void paivitys(const string& viesti) const {
        cout << "seuraaja " << nimi << " sai viestin: " << viesti << endl;
    }
};

//seuraajien ja viestien l‰hetys notifikaattorin avulla
class Notifikaattori {
    Seuraaja* alku; //osoitin ensimm‰iseen seuraajaan


public:
    // Konstruktori, joka alustaa tyhj‰n listan
    Notifikaattori() {
        alku = nullptr; //tyhj‰ lista
    }

    // Lis‰‰ uuden seuraajan listan alkuun
    void lisaa(Seuraaja* seuraaja) {
        seuraaja->next = alku;
        alku = seuraaja;
        cout << "notifikaattori lis‰‰ seuraajan: " << seuraaja->getNimi() << endl;
    }

    //poistetaan valittu seuraaja
    void poista(Seuraaja* poistettava) {
        Seuraaja* nykyinen = alku; //listan aloitus tai uudelleen aloitus
        Seuraaja* edellinen = nullptr; //edellinen osoitin

        while (nykyinen != nullptr) { //listan l‰pi lukeminen

            if (nykyinen == poistettava) { //etsit‰‰n poistettavaksi merkityt listassa

                if (edellinen == nullptr) { //jos poistettava on ensimm‰inen listassa niin
                    alku = nykyinen->next; //niin siirret‰‰n ns ensimm‰inen toiseksi.
                }
                else { //tai poistettava ei ole ensimm‰inen listassa
                    edellinen->next = nykyinen->next; //"ohitetaan" poistettava ensimm‰inen
                }
                cout << "Notifikaattori poistaa seuraajan: " << poistettava->getNimi() << endl;
                return; // Lopetetaan funktio, koska poistaminen on tehty
            }
            edellinen = nykyinen; // P‰ivitet‰‰n edellinen ennen siirtymist‰ seuraavaan
            nykyinen = nykyinen->next; // Siirryt‰‰n seuraavaan alkioon listassa
        }
    }


    // Tulostaa kaikki seuraajat listassa
    void tulosta() const {
        cout << "notifikaattorin seuraajat ovat:" << endl;
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            cout << "seuraaja " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }

    // L‰hett‰‰ viestin kaikille seuraajille
    void postita(const string& viesti) const {
        cout << "notifikaattori postaa viestin: " << viesti << endl;
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
};

int main() {
    Notifikaattori n;

    //seuraajien luominen ja nimet niille
    Seuraaja a("A1_XYZ");
    Seuraaja b("2B_XYZ");
    Seuraaja c("C3_XYZ");

    //Lis‰t‰‰n uudet seuraajat notifikaattoriin
    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    std::cout << "-----------------------------------------------------------------" << std::endl;
    
    n.tulosta(); //tulostetaan seuraajat

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // viesti 1
    n.postita("t‰m‰ on viesti bla bla bla");

    //n.poista(&b);
    n.poista(&c);

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // L‰hetet‰‰n viesti 2 testiss‰
    n.postita("Toinen testi viesti, t‰m‰ n‰kyy niin seuraaja on viel‰ olemassa ");
    n.poista(&b);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    // L‰hetet‰‰n viesti 3 testiss‰
    n.postita("Kolmas testi viesti! ");

    std::cout << "-----------------------------------------------------------------" << std::endl;

    //en tosin viel‰k‰‰n ymm‰rr‰ miksi debugissa poistetaan viesti ennenkuin se printataan..
    return 0;
}
