#include <bits/stdc++.h>
int main() {
  // freopen("MatrixCPP_INP.txt", "r", stdin);
  int rowsCount = 0, columnsCount = 0, currentRow = 0, currentColumns;
  std::string input;
  int array[5][5] = {};
  const int columns = 5;
  const int rows = 5;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> array[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (array[i][j] == 0) {
        rowsCount++;
      } else {
        currentRow = (rowsCount + rows) / rows;
        std::cout << "So 1 nam o hang(row) so: " << currentRow << "\n";
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (array[i][j] == 0) {
        columnsCount++;
      } else {
        currentColumns = (columnsCount % columns + 1);
        std::cout << "So 1 nam o cot(columns) so: " << currentColumns << "\n";
      }
    }
  }
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << (abs(3 - currentColumns) + abs(3 - currentRow));
  return 0;
}
