#pragma once

void GAMEMODE0_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move);
void GAMEMODE1_pick(char (&grid)[3][3], bool (&win)[3][3], int &curRow, int &curCol, int &count, int &move);
char randomChar(int count);
void mark(char (&grid)[3][3], int curRow, int curCol, int &count, int &move);
void nextTurn(int &count);
void undoTurn(int &count);
void addMove(int &move);