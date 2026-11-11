#include "board.hpp"
#include "output.hpp"
#include "input.hpp"
const char EMPTY = '-';

int main() {
  std::cout << "\033[2J\033[H";
  int count = 0, curRow = 1, curCol = 1, move = 0, gamemode = 0;
  char grid[3][3] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
  bool win[3][3] = {}; // ! tất cả = false: chưa ô nào thắng

  std::cout << "What gamemode do you want to play: \n(0) Player VS Player\n(1) "
               "BOT VS Player\n> ";
  std::cin >> gamemode;

  if (gamemode == 0) {
    int state = 0; // 0 = continue, 1 = win/lost, 2 = draw
    do {
      nextTurn(count);
      GAMEMODE0_pick(grid, win, curRow, curCol, count, move);
      state = end(grid, win, move);
    } while (state == 0); // 0 = chua ket thuc

    showCurGrid(grid, win, -1, -1);

    if (state == 1) {
      std::cout << "\n\033[42;30m'" << randomChar(count) << "' has won!\033[0m"
                << "\n";
      std::cout << "\n\033[41;37m'" << randomChar(count + 1)
                << "' has lost!\033[0m" << "\n";
    } else {
      std::cout << "\n\033[33mDRAW!\033[0m\n";
    }

    std::cin.get();
  } else {
    int state = 0; // 0 = continue, 1 = win/lost, 2 = draw
    do {
      nextTurn(count);
      GAMEMODE1_pick(grid, win, curRow, curCol, count, move);
      state = end(grid, win, move);
    } while (state == 0); // 0 = chua ket thuc

    showCurGrid(grid, win, -1, -1);

    if (state == 1) {
      std::cout << "\n\033[42;30m'" << randomChar(count) << "' has won!\033[0m"
                << "\n";
      std::cout << "\n\033[41;37m'" << randomChar(count + 1)
                << "' has lost!\033[0m" << "\n";
    } else {
      std::cout << "\n\033[33mDRAW!\033[0m\n";
    }

    std::cin.get();
  }

  return 0;
}
