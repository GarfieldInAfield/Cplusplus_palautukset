#include <iostream>
#include "Game.h"  //liitetty header

int main() {
    int maxNumber;
    std::cout << "Syötä maksimiarvo: ";
    std::cin >> maxNumber;


    Game game(maxNumber);
    //peli käyntiin
    game.play();


    return 0;
}
