#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLocation(int **grid, int &row, int &col) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}

// check for row
bool checkRow(int **grid, int row, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num)
      return false;
  }
  return true;
}

// check col
bool checkCol(int **grid, int col, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[i][col] == num)
      return false;
  }
  return true;
}

// check for 3X3 grid
bool checkGrid(int **grid, int row, int col, int num) {
  int rowFactor = row - (row % 3);
  int colFactor = col - (col %3);
  for (int i = rowFactor; i < rowFactor + 3; i++) {
    for (int j = colFactor; j < colFactor + 3; j++) {
      if (grid[i][j] == num)
        return false;
    }
  }
  return true;
}

bool isPossible(int **grid, int row, int col, int num) {
  if (checkRow(grid, row, num) && checkCol(grid, col, num) &&
      checkGrid(grid, row, col, num))
    return true;
  else
    return false;
}

bool solve(int **grid) {
  int row, col;
  if (!findEmptyLocation(grid, row, col)) {
    return true;
  }

  for (int i = 1; i <= 9; i++) {
    if (isPossible(grid, row, col, i)) {
      grid[row][col] = i;
      if (solve(grid))
        return true;
      else
        grid[row][col] = 0;
    }
  }
  return false;
}

int main() {
  int **grid = new int *[N];
  for (int i = 0; i < N; i++) {
    grid[i] = new int[N];
  }
  for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
          cin>>grid[i][j];
      }
  }
  if(solve(grid))
    cout<<"true";
  else
    cout<<"false";
}