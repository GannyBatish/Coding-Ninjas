int shortestSubSeqRec(string s, string v, int n, int m, int **dp) {
  if (n == 0) {
    return 1001;
  }
  if (m <= 0) {
    return 1;
  }
  if (dp[n][m] >= 0) {
    return dp[n][m];
  }
  int ans1 = shortestSubSeqRec(s.substr(1), v, n - 1, m, dp);
  int i = 0;
  for (; i < m; i++) {
    if (s[0] == v[i]) {
      break;
    }
  }
  if (i == m) {
    return 1;
  }
  int ans2 =
      1 + shortestSubSeqRec(s.substr(1), v.substr(i + 1), n - 1, m - i - 1, dp);
  dp[n][m] = min(ans1, ans2);
  return dp[n][m];
}

int solve(string s, string v) {
  int n = s.length();
  int m = v.length();
  int **dp = new int *[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = new int[m + 1];
    for (int j = 0; j < m + 1; j++) {
      dp[i][j] = -1;
    }
  }
  return shortestSubSeqRec(s, v, n, m, dp);
  for (int i = 0; i < s.length() + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
}