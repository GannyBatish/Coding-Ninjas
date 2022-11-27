#include<bits/stdc++.h>
using namespace std;
void printBoard(char **board) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
bool isValidVertical(char **board, string currWord, int x, int y) {
  // cout << "isValidVertical :: " << currWord << " " << x << " " << y << endl;
  if (currWord.empty()) {
    return true;
  }
  if (x >= 10) {
    return false;
  }
  if (board[x][y] == '-' || board[x][y] == currWord[0]) {
    return isValidVertical(board, currWord.substr(1), x + 1, y);
  }
  return false;
}
bool isValidHorizontal(char **board, string currWord, int x, int y) {
  // cout << "isValidHorizontal :: " << currWord << " " << x << " " << y <<
  // endl;
  if (currWord.empty()) {
    return true;
  }
  if (y >= 10) {
    return false;
  }
  if (board[x][y] == '-' || board[x][y] == currWord[0]) {
    return isValidHorizontal(board, currWord.substr(1), x, y + 1);
  }
  return false;
}
void setVertical(char **board, bool *updated, int size, string currWord, int x,
                 int y, int idx) {
  // cout << "setVertical :: " << currWord << " " << x << " " << y << " " << idx
  // << endl;
  if (idx == size) {
    return;
  }
  if (board[x][y] == '-') {
    board[x][y] = currWord[idx];
    updated[idx] = true;
  }
  setVertical(board, updated, size, currWord, x + 1, y, idx + 1);
}
void resetVertical(char **board, bool *updated, int size, int x, int y,
                   int idx) {
  // cout << "resetVertical :: " << x << " " << y << " " << idx << endl;
  if (idx == size) {
    return;
  }
  if (updated[idx]) {
    board[x][y] = '-';
    updated[idx] = false;
  }
  resetVertical(board, updated, size, x + 1, y, idx + 1);
}
void setHorizontal(char **board, bool *updated, int size, string currWord,
                   int x, int y, int idx) {
  // cout << "setHorizontal :: " << currWord << " " << x << " " << y << " " <<
  // idx << endl;
  if (idx == size) {
    return;
  }
  if (board[x][y] == '-') {
    board[x][y] = currWord[idx];
    updated[idx] = true;
  }
  setHorizontal(board, updated, size, currWord, x, y + 1, idx + 1);
}
void resetHorizontal(char **board, bool *updated, int size, int x, int y,
                     int idx) {
  // cout << "resetHorizontal :: " << " " << x << " " << y <<" " << idx << endl;
  if (idx == size) {
    return;
  }
  if (updated[idx]) {
    board[x][y] = '-';
    updated[idx] = false;
  }
  resetHorizontal(board, updated, size, x, y + 1, idx + 1);
}
void crossword(char **board, vector<string> &words, int index) {
  if (index == words.size()) {
    printBoard(board);
    return;
  }
  string currWord = words[index];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board[i][j] == '-' || board[i][j] == currWord[0]) {
        // cout << "main :: " << currWord << " " << i << " " << j << endl;
        int wordSize = words[index].length();
        bool *updated = new bool[wordSize];
        if (isValidVertical(board, currWord, i, j)) {
          // cout<< "Inside vertical set" << endl;
          setVertical(board, updated, wordSize, currWord, i, j, 0);
          // printBoard(board);
          crossword(board, words, index + 1);
          resetVertical(board, updated, wordSize, i, j, 0);
          // printBoard(board);
        }
        if (isValidHorizontal(board, currWord, i, j)) {
          // cout<< "Inside horizontal set" << endl;
          setHorizontal(board, updated, wordSize, currWord, i, j, 0);
          // printBoard(board);
          crossword(board, words, index + 1);
          resetHorizontal(board, updated, wordSize, i, j, 0);
          // printBoard(board);
        }
        delete[] updated;
      }
    }
  }
}
int main() {
  char **board = new char *[10];
  for (int i = 0; i < 10; i++) {
    board[i] = new char[10];
    for (int j = 0; j < 10; j++) {
      cin >> board[i][j];
    }
  }
  string words;
  cin >> words;
  vector<string> wordList;
  int i = 0;
  while (i != -1) {
    i = words.find(";");
    wordList.push_back(words.substr(0, i));
    words = words.substr(i + 1);
  }
  crossword(board, wordList, 0);
  for (int i = 0; i < 10; i++) {
    delete[] board[i];
  }
  delete[] board;

  return 0;
}