////? Exercise 1:
// #include <iostream>

// namespace first {
//   int x = 1;

// }

// namespace second {
//   int x = 2;
// }

// namespace third {
//   int x = 3;
  
// }

// int main() {
//   std::cout << first::x << std::endl;
//   std::cout << second::x << std::endl;
//   std::cout << third::x<< std::endl;
//   return 0;
// }

    // //? Exercise 2:
    // #include <iostream>

    // namespace first {
    //     int x = 1;

    // }

    // namespace second {
    //     int x = 2;

    // }

    // namespace third {
    //     int x = 3;

    // }


    // int main() {
    //     //TODO: Thử using namespace first; và using namespace second; 
    //     //TODO: cùng lúc rồi in x không có :: — xem trình biên dịch báo lỗi gì (gợi ý: ambiguous).

    //     using namespace first;
    //     using namespace second;

    //         std::cout << x << std::endl;
    //     return 0;

    // }
    // //! ERROR:
    // /* exercises.cpp: In function 'int main()':
    // exercises.cpp:53:22: error: reference to 'x' is ambiguous
    //    53 |         std::cout << x << std::endl;
    //       |                      ^
    //   • there are 2 candidates
    //     • candidate 1: 'int first::x'
    //       exercises.cpp:31:9:
    //          31 |     int x = 1;
    //             |         ^
    //     • candidate 2: 'int second::x'
    //       exercises.cpp:36:9:
    //          36 |     int x = 2;
    //             |         ^
    // */