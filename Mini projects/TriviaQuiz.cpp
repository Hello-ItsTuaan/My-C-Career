#include <iostream>

int main() {
  int score = 0;
  int Q1choice;
  // Write code here 💖
  std::cout << "Q1) What is the name of the world's longest river? \n";
  std::cout << "1) Missouri River\n2) Nile\n3) Amazon River\n4) Yangtze River\n";

  std::cin >> Q1choice;

  if (Q1choice == 2) {
    std::cout << "Correct!\n";
    score += 1;
  } else {
    std::cout << "Wrong!\n";
  }

  int Q2choice;
  // Write code here 💖
  std::cout << "Q2) How many bones are in the human body? \n";
  std::cout << "1) 92\n2) 150\n3) 206\n4) 10\n";

  std::cin >> Q2choice;

  if (Q2choice == 3) {
    std::cout << "Correct!\n";
    score += 1;
  } else {
    std::cout << "Wrong!\n";
  }

  int Q3choice;

  std::cout << "What is the name of the tallest grass on earth?\n";
  std::cout << "1) Giant Bamboo\n2) Elephant Grass\n3) Sugarcane\n4) Pampas Grass\n";

  std::cin >> Q3choice;

  if (Q3choice == 1) {
    std::cout << "Correct!\n";
    score += 1;
  } else {
    std::cout << "Wrong!\n";
  }


  std::cout << "You have finished our trivia quiz!, Your score is " << score << "/3";
}


