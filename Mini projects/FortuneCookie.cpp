#include <iostream>
#include <cstdlib>

int main() {
  srand(time(NULL));

  int randomNumber = std::rand() %6 + 1;

  if (randomNumber == 1) {
    std::cout << "Don't pursue happiness - create it.";
  } 
  else if (randomNumber == 2) {
    std::cout << "All things are difficult before they are easy.";
  }
  else if (randomNumber == 3) {
    std::cout << "The early bird gets the worm, but the second mouse gets the cheese.";
  }
  else if (randomNumber == 4) {
    std::cout << "Someone in your life needs a letter from you.";
  }
  else if (randomNumber == 5) {
    std::cout << "The fortune you search for is in another cookie.";
  }
  else if (randomNumber == 6) {
    std::cout << "Help! I'm being held prisoner in a Chinese bakery!";
  }
  std::cout << "\n" << "Your lucky numbers: ";
  for (int i = 0; i < 6; i++) {
    std::cout << std::rand() % 50 << " ";
  }
}