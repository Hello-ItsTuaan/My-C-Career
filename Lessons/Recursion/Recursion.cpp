#include <bits/stdc++.h>
long long factorial(int num);
void walk(int steps);

int main() {
  std::cout << "It's Đệ Quy TIME!!!\n";
  // Recursion = a programming technique where a function
  //             invoke itself from within 
  //             break a complex concept into a repeatable single step
  //
  //        (iterative vs recursive)
  // advantages = less code and it's cleaner, help with sorting algorithms, that when recursion is going to help you alot, it makes the code simpler;
  //              useful for sorting and search algorithms
  //
  //
  // disadvantages = use more memory
  //                 slower
  //
  std::cout << factorial(10);

  return 0;
}

long long factorial(int num) {
  // int result = 1;
  // for (int i = 1; i <= num; i++) {
  //   result = result * i;
  // }
  
  if (num > 1) {
    return num* factorial(num-1);
  } else {
    return 1;
  }
}

void walk (int steps) {
  // for (int i = 0; i < steps; i++) {
  //   std::cout << "You just take a step! \n";
  // }
  //
   if (steps > 0) {
    std::cout << "You take a step!\n";
    walk(steps-1);
  } // walk(steps); without -1 will run infinitely, which we call Stack Overflow =)!
}
