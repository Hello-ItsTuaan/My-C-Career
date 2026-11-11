#pragma once 
#include "output.hpp"

void showCurGrid(char (&grid)[3][3], bool (&win)[3][3], int row, int col);
int end(char (&grid)[3][3], bool (&win)[3][3], int move);
