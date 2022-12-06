int knapsack(int *wt, int *values, int n, int W) {
  int **dp = new int *[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new int[W + 1];
  }
  for (int i = 0; i <= W; i++) {
    dp[n][i] = 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (wt[i] <= j) {
        dp[i][j] = max(dp[i + 1][j - wt[i]] + values[i], dp[i + 1][j]);
      } else {
        dp[i][j] = dp[i + 1][j];
      }
    }
  }
  int ans = dp[0][W];
  for (int i = 0; i <= n; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return ans;
}