#include <bits/stdc++.h>
#include <conio.h>

char randomChar(int count);
void showCurGrid(char (&grid)[3][3], bool (&win)[3][3], int row, int col);
void mark(char (&grid)[3][3], int curRow, int curCol, int &count, int &move);
void pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move);
int  end(char (&grid)[3][3], bool (&win)[3][3], int move);

int main() {
  std::cout << "\033[2J\033[H";

  int count = 0, curRow = 1, curCol = 1, move = 0;
  char grid[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}};
  bool win[3][3] = {};          // ! tất cả = false: chưa ô nào thắng

  int state = 0;                // 0 = chơi tiếp | 1 = có người thắng | -1 = hòa
  do {
    count++;
    pick(grid, win, curRow, curCol, count, move);
    state = end(grid, win, move); 
  } while (state == 0);            // 0 = chua ket thuc

  // vẽ lần cuối: row/col = -1 để KHÔNG có ô con trỏ nào bị sáng trắng
  showCurGrid(grid, win, -1, -1);

  if (state == 1) {
    std::cout << "\n\033[42;30m'" << randomChar(count)   << "' has won!\033[0m"  << "\n";
    std::cout << "\n\033[41;37m'" << randomChar(count+1) << "' has lost!\033[0m" << "\n";
  } else {
    std::cout << "\n\033[33mDRAW!\033[0m\n";
  }

  std::cin.get();
  return 0;
}

char randomChar(int count) {
  return (count % 2 == 0) ? 'x' : '0';
}

void showCurGrid(char (&grid)[3][3], bool (&win)[3][3], int row, int col) {
  std::cout << "\033[2J\033[H";
  std::cout << "\n\n";
  std::cout << "       " << " A" << "  B" << "  C" << "\n\n";

  for (int i = 0; i < 3; i++) {
    std::cout << i + 1 << ".     ";
    for (int j = 0; j < 3; j++) {
      if (win[i][j]) {
        // ! ưu tiên 1: ô thuộc đường thắng → nền xanh lá
        std::cout << "\033[42;30m " << grid[i][j] << " \033[0m";
      } else if (i == row && j == col) {
        // ! ưu tiên 2: ô con trỏ → nền trắng
        std::cout << "\033[47;30m " << grid[i][j] << " \033[0m";
      } else {
        std::cout << " " << grid[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}

void mark(char (&grid)[3][3], int curRow, int curCol, int &count, int &move) {
  if (grid[curRow][curCol] == '-') {
    grid[curRow][curCol] = randomChar(count);
    move++;
  } else {
    std::cout << "\nInvalid Move! Press any key...";
    _getch();
    count -= 1;       // ? Why: main sẽ count++ lại, nên vẫn là lượt của người này
  }
}

void pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move) {
  showCurGrid(grid, win, curRow, curCol);
  do {
    int k = _getch();

    if (k == 27) break;

    if (k == 13) { mark(grid, curRow, curCol, count, move); break; }

    if (k == 224) {                 // ! 224 = "sắp có phím đặc biệt"
      int k2 = _getch();
      if      (k2 == 72 && curRow != 0) curRow -= 1;
      else if (k2 == 80 && curRow != 2) curRow += 1;
      else if (k2 == 75 && curCol != 0) curCol -= 1;
      else if (k2 == 77 && curCol != 2) curCol += 1;
      showCurGrid(grid, win, curRow, curCol);
    }
  } while (true);
}

int end(char (&grid)[3][3], bool (&win)[3][3], int move) {
  // hàng
  for (int i = 0; i < 3; i++) {
    if (grid[i][0] != '-' && grid[i][1] == grid[i][0] && grid[i][2] == grid[i][1]) {
      for (int j = 0; j < 3; j++) win[i][j] = true;
      return 1;
    }
  }  // WARNING: dấu } đóng vòng hàng nằm Ở ĐÂY, không phải tận cuối hàm

  // cột
  for (int i = 0; i < 3; i++) {
    if (grid[0][i] != '-' && grid[1][i] == grid[0][i] && grid[2][i] == grid[1][i]) {
      for (int j = 0; j < 3; j++) win[j][i] = true;
      return 1;
    }
  }

  // đường chéo chính  \  (row == col)
  if (grid[0][0] != '-' && grid[1][1] == grid[0][0] && grid[2][2] == grid[1][1]) {
    for (int k = 0; k < 3; k++) win[k][k] = true;
    return 1;
  }

  // đường chéo phụ  /  (row + col == 2)
  if (grid[0][2] != '-' && grid[1][1] == grid[0][2] && grid[2][0] == grid[1][1]) {
    for (int k = 0; k < 3; k++) win[k][2 - k] = true;
    return 1;
  }

  if (move == 9) return -1;   // hòa (kiểm tra SAU cùng, để nước thứ 9 mà thắng vẫn tính là thắng)
  return 0;                   // chơi tiếp
}