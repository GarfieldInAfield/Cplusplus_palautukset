#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;        //Maksimiarvo, jonka sis‰ll‰ arvaus tapahtuu
    int playerGuess;      //Pelaajan arvaus
    int randomNumber;     //Arvottu luku
    int numOfGuesses;     //Arvausten m‰‰r‰


public:
    
    Game(int maxNumber); //konstruktori
    ~Game(); //ja desktruktori

    
    void play(); //pelin core funktiot
    void printGameResult() const;
};

#endif //GAME_H
