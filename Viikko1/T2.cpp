#include <iostream>
#include <cstdlib>  //Satunnaisluvut
#include <ctime> 
using namespace std;

int game(int maxnum);

int main() {
    int maxnum;
    cout << "Anna suurin mahdollinen arvottava luku:";
    cin >> maxnum;

    int yritykset = game(maxnum);

    cout << "Arvasit oikein:" << yritykset << " yrityksen jälkeen!" << endl;

    return 0;
}

//erillinen funktio maxnumille

int game(int maxnum) {
    srand(time(0));
    int secret = rand() % maxnum + 1; //1 - maksimi numero
    int guess, yritykset = 0;

    cout << "arvaa luku väliltä 1-" << maxnum << endl;

    while (true) {
        cout << "Syötä arvauksesi arvolle:";
        cin >> guess;
        yritykset++;


        if (guess < secret) {
            cout << "Luku on suurempi!" << endl;
        }


        else if (guess > secret) {
            cout << "Luku on pienempi!" << endl;
        }


        else {
            cout << "oikein, luku oli:" << secret << "." << endl;

            break;
        }
    }

    return yritykset; //arvausten määrä lopuksi
}
