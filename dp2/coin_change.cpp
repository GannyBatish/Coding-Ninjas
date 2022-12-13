int countWaysToMakeChange(int denominations[], int numDenominations,
                           int value) {
  int arr[numDenominations + 1][value + 1];
  for (int i = 0; i <= numDenominations; i++) {
    for (int j = 0; j <= value; j++) {
      if (i == 0) {
        arr[i][j] = 0;
      }
      if (j == 0) {
        arr[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= numDenominations; i++) {
    for (int j = 1; j <= value; j++) {
      if (denominations[i - 1] > j) {
        arr[i][j] = arr[i - 1][j];
      } else {
        arr[i][j] = arr[i - 1][j] + arr[i][j - denominations[i - 1]];
      }
    }
  }
  return arr[numDenominations][value];
}