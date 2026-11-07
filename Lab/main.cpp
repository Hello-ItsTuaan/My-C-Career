#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::string n;
  if (!(std::cin >> n) || n.size() < 2) {
    std::cout << 0;
    return 0;
  }

  int total = 0;
  for (size_t i = 0; i < n.size() - 1; i++) {
    total += ((n[i] - '0') + (n[i + 1] - '0'));
  }
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << total;
  return 0;
}

void shit() { std::system("cls"); }

void hellWorld() { std::cout << "Hello World!" << std::endl; }
