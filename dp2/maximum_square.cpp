int findMaxSquareWithAllZeros(int **arr, int n, int m) {
  int **dp = new int *[n];
  for (int i = 0; i < n; i++) {
    dp[i] = new int[n];
    for (int j = 0; j < n; j++) {
      if ((i == 0 || j == 0) && arr[i][j] == 0) {
        dp[i][j] = 1;
      } else if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (arr[i][j] == 0) {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
      } else {
        dp[i][j] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}