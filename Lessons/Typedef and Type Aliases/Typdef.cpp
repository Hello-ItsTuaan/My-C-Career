/* typdef = reserved keyword used to create an additional name 
 New identifier for an existing type
 Helps with readablitiy and reduce typos.*/
 //? Use when there is a clear benefit
 //? replace with 'using' (work better w/ templates - learn later)

#include <iostream>
#include <vector>

// typedef std::vector<std::pair<std::string, int>> pairlist_t;
// typedef std::string text_t;
// typedef int number_t;

using text_t = std::string;
using number_t = int;

int main() {
    // std::vector<std::pair<std::string, int>> pairlist;
    // pairlist_t pairlist;
    //? std::string firstName;
    text_t firstName = "Tuan";
    number_t age = 13;

    std::cout << firstName << '\n';
    std::cout << age<< '\n';
    return 0;

}