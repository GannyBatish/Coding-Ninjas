int countStepsToOne(int n) {
  int *dp = new int[n + 1];

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  for (int i = 4; i <= n; i++) {
    int a = n, b = n;
    if (i % 2 == 0) {
      a = dp[i / 2];
    }
    if (i % 3 == 0) {
      b = dp[i / 3];
    }
    dp[i] = min(dp[i - 1], min(a, b)) + 1;
  }
  return dp[n];
}