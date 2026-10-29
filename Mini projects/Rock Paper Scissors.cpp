#include <bits/stdc++.h>

int getUserChoice();
int getComputerChoice();
void chooseWinner(int player, int computer);
std::string choiceToString(int value);

int main () {
    srand(time(NULL));
    char choice;
    do {
        choice = 'n';
        std::cout << "Please choose 1, 2 or 3 (Rock, Paper and Scissors)" << "\n";
        int player = getUserChoice();
        int computer = getComputerChoice();

        std::cout << "You chose " << choiceToString(player) << " || ";
        std::cout << "Computer chose " << choiceToString(computer) << "\n";

        chooseWinner(player, computer);

        std::cout << "Do you want to play again? (y/n)" << "\n";
        std::cin >> choice;
        std::cin.ignore(10000, '\n');  // ? Why: xóa phần thừa như "es" của "yes"

    } while (tolower(choice) == 'y');
    return 0;
}

int getUserChoice() {
    int choice;

    // ! IMPORTANT: lặp tới khi nhập đúng 1, 2 hoặc 3
    while (true) {
        if (std::cin >> choice && choice >= 1 && choice <= 3) {
            // ? Why ignore here: bỏ phần thừa trên dòng (vd "2abc") để lần đọc sau sạch
            std::cin.ignore(10000, '\n');
            return choice;
        }

        // WARNING: nhập chữ -> cin fail -> PHẢI clear() rồi mới ignore()
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid! Please choose 1, 2 or 3: ";
    }
}

int getComputerChoice() {
    int computerChoice = rand() % 3 + 1;
    switch(computerChoice) {
        case 1:
            return 1; //ROCK
        case 2:
            return 2; //Paper
        case 3:
            return 3; //Scissors
    }
    return 99;
}


void chooseWinner(int player, int computer) {
    if (player == computer) {
        std::cout << "DRAW!\n";
        return;
    }

    if ((player % 3 + 1) == computer) {
        std::cout << "You have lost!\n";
        return;
    }

    std::cout << "You have won!\n";
    return;
}

std::string choiceToString(int value) {
    switch (value) {
        case 1: return "ROCK";
        case 2: return "PAPER";
        case 3: return"SCISSORS";
        default: return "UNKNOWN";
    }
}

