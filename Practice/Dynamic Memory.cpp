#include <bits/stdc++.h>

int main() {
  int *x = new int;
  int *y = x;
  *x = 4;
  *y = 9;

  std::cout << *x;
  delete x;


  return 0;
}
