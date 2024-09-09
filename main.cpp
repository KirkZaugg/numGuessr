#include<iostream>
#include<time.h>

int numGen(int min, int max) {
    return (rand() % (max - min)) + min;
}

bool response() {
    char response;
    std::cin >> response;
    return (std::toupper(response) == 'Y');
}

void game() {
    int num = numGen(1, 100);
    std::cout << "Welcome to NumGuessr!\n";
    int i = 0;
    do {
        std::cout << "Please guess a number between 1 and 100: ";
        int input = 0;
        std::cin >> input;
        if (input == num) {
            std::cout << "That is correct! Great Job!\n";
            return;
        } else if(i < 9) {
            std::string comp = (input < num) ? "low" : "high";
            std::cout << "Unfortunately, your guess was too " << comp << ".\n" << "You have " << 9 - i << " attempts left, would you like to try again? (y/n): ";
            if(response()) {
                i++;
            } else {
                return;
            }
        } else {
            std::cout << "Unfortuantley, you have run out of attempts. The answer was " << num << "\n";
            return;
        }
        
    } while(i < 10);
}

int main() {
    std::srand(time(0));
    bool go = false;
    do {
        game();
        std::cout << "Thank you for playing NumGuessr! Would you like to play again? (y/n): ";
        go = response();
    } while(go);

}