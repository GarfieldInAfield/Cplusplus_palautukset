#include "Game.h"  //Sis‰llytet‰‰n Game.h-tiedosto
#include <iostream> //Konsolin tulostamiseen
#include <cstdlib>  //Satunnaislukujen generointi
#include <ctime>    //Aikapohjainen satunnaisuus 

using namespace std;
//k
Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
    this->numOfGuesses = 0;

    //random generator
    srand(static_cast<unsigned int>(time(0)));
    this->randomNumber = rand() % maxNumber + 1;
}

//d
Game::~Game() {
}

// Peli alkaa ja pelaaja arvaa lukuja
void Game::play() {
    cout << "arvaa 1 ja " << maxNumber << " v‰lilt‰:" << endl;

    do { //voisikohan tehd‰ while:ll‰ helpommin. 
        cout << "anna arvauksesi arvolle:";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "arvauksesi on liian pieni" << endl;
        }


        else if (playerGuess > randomNumber) {
            cout << "arvauksesi on liian suuri" << endl;
        }


    } while (playerGuess != randomNumber);

    printGameResult(); //lopputulosten ilmoitus funktion kutsu
}



//tulostetaan pelin tulos
void Game::printGameResult() const {
    cout << "oikea luku oli:" << randomNumber << endl;
    cout << "arvauksia tehtiin:" << numOfGuesses << endl;
}
