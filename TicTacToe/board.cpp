#include "output.hpp"
#include "board.hpp"

void showCurGrid(char (&grid)[3][3], bool (&win)[3][3], int row, int col) {
  std::cout << "\033[2J\033[H";
  std::cout << "\n\n";
  std::cout << "       " << " A" << "  B" << "  C" << "\n\n"; // Hiển thị cột

  for (int i = 0; i < 3; i++) {
    std::cout << i + 1 << ".     ";
    for (int j = 0; j < 3; j++) {
      if (win[i][j]) {
        std::cout << "\033[42;30m " << grid[i][j] << " \033[0m";
      } else if (i == row && j == col) {
        std::cout << "\033[47;30m " << grid[i][j] << " \033[0m";
      } else {
        std::cout << " " << grid[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}


int end(char (&grid)[3][3], bool (&win)[3][3], int move) {
  // hàng
  for (int i = 0; i < 3; i++) {
    if (grid[i][0] != '-' && grid[i][1] == grid[i][0] && grid[i][2] == grid[i][1]) {
      for (int j = 0; j < 3; j++)
        win[i][j] = true;
      return 1;
    }
  }
  // cột
  for (int i = 0; i < 3; i++) {
    if (grid[0][i] != '-' && grid[1][i] == grid[0][i] && grid[2][i] == grid[1][i]) {
      for (int j = 0; j < 3; j++)
        win[j][i] = true;
      return 1;
    }
  }

  // đường chéo chính  \  (row == col)
  if (grid[0][0] != '-' && grid[1][1] == grid[0][0] && grid[2][2] == grid[1][1]) {
    for (int k = 0; k < 3; k++)
      win[k][k] = true;
    return 1;
  }

  // đường chéo phụ  /  (row + col == 2)
  if (grid[0][2] != '-' && grid[1][1] == grid[0][2] &&
      grid[2][0] == grid[1][1]) {
    for (int k = 0; k < 3; k++)
      win[k][2 - k] = true;
    return 1;
  }

  if (move == 9)
    return -1; // hòa (kiểm tra SAU cùng, để nước thứ 9 mà thắng vẫn tính là
               // thắng)
  return 0;    // chơi tiếp
}