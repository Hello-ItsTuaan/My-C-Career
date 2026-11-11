// ═════════════════════════════════════════════════════════════
// | TIC TAC TOE (TUI) — bản dọn dẹp |
// ═════════════════════════════════════════════════════════════
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

// ───────────── Kiểu dữ liệu + hằng số ─────────────
// ? Why this exists:
//   Đặt tên cho mấy con số "ma thuật" (27, 13, 224...) để đọc code khỏi phải đoán.
using Grid = char[3][3];
using Mask = bool[3][3];

const char EMPTY = '-';
const char PLAYER_X = 'x';
const char PLAYER_O = 'O';

const int KEY_ESC = 27;
const int KEY_ENTER = 13;
const int KEY_SPECIAL = 224; // ! "sắp có phím đặc biệt (mũi tên)"
const int KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77;

// ───────────── Khai báo hàm ─────────────
void showCurGrid(Grid &grid, Mask &win, int row, int col, char turn = ' ');
bool mark(Grid &grid, int curRow, int curCol, char symbol, int &move);
bool pick(Grid &grid, Mask &win, int &curRow, int &curCol, char symbol, int &move);
void botMove(Grid &grid, char symbol, int &move);
void quitGame();
int end(Grid &grid, Mask &win, int move);

// ═════════════════════════════════════════════════════════════
// | MAIN SECTION: main() — 1 vòng lặp cho cả 2 chế độ |
// ═════════════════════════════════════════════════════════════
int main() {
  srand(time(NULL)); // ! chỉ gọi 1 LẦN ở đây, đừng gọi trong hàm bot

  int curRow = 1, curCol = 1, move = 0, gamemode = 0;
  Grid grid = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
  Mask win = {}; // ! tất cả = false: chưa ô nào thắng

  std::cout << "\033[2J\033[H";
  std::cout << "What gamemode do you want to play: \n"
               "(0) Player VS Player\n(1) BOT VS Player\n> ";
  std::cin >> gamemode;
  std::cin.ignore(10000, '\n'); // ! xóa Enter còn sót, không là cin.get() cuối bị "ăn" mất

  char turn = PLAYER_X; // x đi trước. Bot (nếu có) luôn cầm '0'
  int state = 0;        // 0 = chơi tiếp | 1 = có người thắng | -1 = hòa

  while (state == 0) {
    if (gamemode == 1 && turn == PLAYER_O) {
      botMove(grid, turn, move);
    } else if (!pick(grid, win, curRow, curCol, turn, move)) {
      continue; // đánh vào ô có người → giữ nguyên lượt, vẽ lại
    }

    state = end(grid, win, move);

    // ! IMPORTANT: chỉ đổi lượt khi ván CHƯA kết thúc,
    //   nên lúc thắng thì 'turn' chính là người thắng.
    if (state == 0)
      turn = (turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // vẽ lần cuối: row/col = -1 để KHÔNG có ô con trỏ nào bị sáng trắng
  showCurGrid(grid, win, -1, -1);

  if (state == 1) {
    char loser = (turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
    std::cout << "\n\033[42;30m'" << turn << "' has won!\033[0m\n";
    std::cout << "\n\033[41;37m'" << loser << "' has lost!\033[0m\n";
  } else {
    std::cout << "\n\033[33mDRAW!\033[0m\n";
  }

  std::cin.get();
  return 0;
}

// ═════════════════════════════════════════════════════════════
// | VẼ BÀN CỜ |
// ═════════════════════════════════════════════════════════════
// turn = ' ' nghĩa là không hiện dòng "Turn" (dùng cho lần vẽ cuối)
void showCurGrid(Grid &grid, Mask &win, int row, int col, char turn) {
  std::cout << "\033[2J\033[H";
  std::cout << "\n\n";
  std::cout << "       " << " A" << "  B" << "  C" << "\n\n"; // Hiển thị cột

  for (int i = 0; i < 3; i++) {
    std::cout << i + 1 << ".     ";
    for (int j = 0; j < 3; j++) {
      if (win[i][j]) {
        std::cout << "\033[42;30m " << grid[i][j] << " \033[0m"; // ô thắng: xanh
      } else if (i == row && j == col) {
        std::cout << "\033[47;30m " << grid[i][j] << " \033[0m"; // con trỏ: trắng
      } else {
        std::cout << " " << grid[i][j] << " ";
      }
    }
    std::cout << "\n";
  }

  if (turn != ' ')
    std::cout << "\nTurn: '" << turn << "'\n";
}

// ═════════════════════════════════════════════════════════════
// | ĐÁNH CỜ |
// ═════════════════════════════════════════════════════════════
// mark: đánh thử vào ô → true nếu thành công, false nếu ô đã có người
bool mark(Grid &grid, int curRow, int curCol, char symbol, int &move) {
  if (grid[curRow][curCol] == EMPTY) {
    grid[curRow][curCol] = symbol;
    move++;
    return true;
  }
  std::cout << "\nInvalid Move! Press any key...";
  _getch();
  return false;
}

// pick: người chơi di chuyển con trỏ + Enter để đánh
// Trả về true nếu đã đánh thành công (để main() biết mà đổi lượt)
bool pick(Grid &grid, Mask &win, int &curRow, int &curCol, char symbol, int &move) {
  showCurGrid(grid, win, curRow, curCol, symbol);

  while (true) {
    int k = _getch();

    if (k == KEY_ESC)
      quitGame();

    if (k == KEY_ENTER)
      return mark(grid, curRow, curCol, symbol, move);

    if (k == KEY_SPECIAL) {
      int k2 = _getch();
      if (k2 == KEY_UP && curRow != 0) curRow--;
      else if (k2 == KEY_DOWN && curRow != 2) curRow++;
      else if (k2 == KEY_LEFT && curCol != 0) curCol--;
      else if (k2 == KEY_RIGHT && curCol != 2) curCol++;
      showCurGrid(grid, win, curRow, curCol, symbol);
    }
  }
}

// botMove: bốc ngẫu nhiên 1 ô còn trống
// ! IMPORTANT: phải gọi end() TRƯỚC, bàn đầy mà gọi hàm này là kẹt vòng lặp
void botMove(Grid &grid, char symbol, int &move) {
  while (true) {
    int r = rand() % 3, c = rand() % 3; // random LẠI mỗi vòng
    if (grid[r][c] == EMPTY) {
      grid[r][c] = symbol;
      move++;
      return;
    }
  }
}

// ───────────── Thoát game bằng ESC (giữ nguyên cái MessageBox của bro :D) ─────────────
void quitGame() {
  std::system("cls");
  MessageBox(nullptr, "You have quit the Application", "Tic-Tac-Toe",
             MB_OK | MB_ICONINFORMATION);
  std::exit(0);
}

// ═════════════════════════════════════════════════════════════
// | KIỂM TRA KẾT THÚC (logic y như cũ) |
// ═════════════════════════════════════════════════════════════
// Trả về:  1 = có người thắng | -1 = hòa | 0 = chơi tiếp
int end(Grid &grid, Mask &win, int move) {
  // hàng
  for (int i = 0; i < 3; i++) {
    if (grid[i][0] != EMPTY && grid[i][1] == grid[i][0] &&
        grid[i][2] == grid[i][1]) {
      for (int j = 0; j < 3; j++)
        win[i][j] = true;
      return 1;
    }
  }
  // cột
  for (int i = 0; i < 3; i++) {
    if (grid[0][i] != EMPTY && grid[1][i] == grid[0][i] &&
        grid[2][i] == grid[1][i]) {
      for (int j = 0; j < 3; j++)
        win[j][i] = true;
      return 1;
    }
  }

  // đường chéo chính  \  (row == col)
  if (grid[0][0] != EMPTY && grid[1][1] == grid[0][0] &&
      grid[2][2] == grid[1][1]) {
    for (int k = 0; k < 3; k++)
      win[k][k] = true;
    return 1;
  }

  // đường chéo phụ  /  (row + col == 2)
  if (grid[0][2] != EMPTY && grid[1][1] == grid[0][2] &&
      grid[2][0] == grid[1][1]) {
    for (int k = 0; k < 3; k++)
      win[k][2 - k] = true;
    return 1;
  }

  // WARNING: để SAU CÙNG, để nước thứ 9 mà thắng vẫn tính là thắng
  if (move == 9)
    return -1;
  return 0;
}