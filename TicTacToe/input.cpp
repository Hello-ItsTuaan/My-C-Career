#include "output.hpp"
#include "input.hpp"
#include "board.hpp"

char randomChar(int count) { return (count % 2 == 0) ? 'x' : '0'; }
void nextTurn(int &count) { count++; }
void undoTurn(int &count) { count--; }
void addMove(int &move) { move++; }

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
    // bot is picking a spot...
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