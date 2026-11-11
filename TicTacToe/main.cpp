#include <bits/stdc++.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

char randomChar(int count);
void showCurGrid(char (&grid)[3][3], bool (&win)[3][3], int row, int col);
void mark(char (&grid)[3][3], int curRow, int curCol, int &count, int &move);
void GAMEMODE0_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move);
void GAMEMODE1_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move);
int end(char (&grid)[3][3], bool (&win)[3][3], int move);

void nextTurn(int &count);
void undoTurn(int &count);
void addMove(int &move);

CONST char EMPTY = '-';

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

void nextTurn(int &count) {count++;}
void undoTurn(int &count) {count--;}
void addMove(int &move) {move++;}
char randomChar(int count) {return (count % 2 == 0) ? 'x' : '0';}

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

void mark(char (&grid)[3][3], int curRow, int curCol, int &count, int &move) {
  if (grid[curRow][curCol] == '-') {
    grid[curRow][curCol] = randomChar(count);
    addMove(move);
  } else {
    std::cout << "\nInvalid Move! Press any key...";
    _getch();
    undoTurn(count);
  }
}

void GAMEMODE0_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move) {
  showCurGrid(grid, win, curRow, curCol);
  do {
    int k = _getch();

    if (k == 27) {
      std::system("cls");
      MessageBox(nullptr, "You have quit the Application",
                 "Tic-Tac-Toe", // HEHE:)) it's fun lol
                 MB_OK | MB_ICONINFORMATION);
      std::exit(0);
    }
    if (k == 13) {
      mark(grid, curRow, curCol, count, move);
      break;
    }

    if (k == 224) { // ! 224 = "sắp có phím đặc biệt"
      int k2 = _getch();
      if (k2 == 72 && curRow != 0)
        curRow -= 1;
      else if (k2 == 80 && curRow != 2)
        curRow += 1;
      else if (k2 == 75 && curCol != 0)
        curCol -= 1;
      else if (k2 == 77 && curCol != 2)
        curCol += 1;
      showCurGrid(grid, win, curRow, curCol);
    }
  } while (true);
}

void GAMEMODE1_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow,
                    int &curCol, int &count, int &move) {
  showCurGrid(grid, win, curRow, curCol);
  // std::string firstOne = "Player";
  // std::cout << "You want to play first against the bot?" << "\n> ";
  // std::cin >> firstOne;

  // if (firstOne != "Player") {count--;}
  if (count % 2 == 0) {
    std::cout << "Your Turn: Player" << std::endl;
  } else {
    std::cout << "Your Turn: BOT" << std::endl;
  } // Current Turn

  if (count % 2 == 0) {
    GAMEMODE0_pick(grid, win, curRow, curCol, count, move);
  } else {
    srand(time(NULL));
    int botRows = rand() % 3 + 1;
    int botCollumns = rand() % 3 + 1;
    // bot is picking a spot... :v
    bool valid = false;
    do {
      int botRows = rand() % 3;
      int botCollumns = rand() % 3;

      if (grid[botRows][botCollumns] == '-') {
        grid[botRows][botCollumns] = '0';
        valid = true;
        addMove(move);
      }
    } while (!valid);
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