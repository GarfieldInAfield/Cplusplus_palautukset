#include <iostream>
#include <cstdlib>
#include <ctime>
int main() {

    srand(time(0));
    int randomNumber = rand() % 20 + 1;
    int guess = 0;

    while (true) {
        std::cout << "Arvaa arvo väliltä 1-20: ";
        std::cin >> guess;


        if (guess < randomNumber) {
            std::cout << "Luku on suurempi!\n";
        }

        else if (guess > randomNumber) {
            std::cout << "Luku on pienempi!\n";
        }

        else {
            std::cout << "oikein, Luku oli:" << randomNumber;

            break;
        }


    }
    return 0;
}
