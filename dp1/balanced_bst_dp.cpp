const int m = 1e9 + 7;

int balancedBTs(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 3;
  }

  int *dp = new int[n + 1];
  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= n; i++) {
    int x = (int)(((long long)dp[i - 1] * dp[i - 1]) % m);
    int y = (int)((2 * (long long)dp[i - 1] * dp[i - 2]) % m);
    dp[i] = (int)(((long long)x + y) % m);
  }
  int result = dp[n];
  delete[] dp;
  return result;
}