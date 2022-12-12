int longestIncreasingSubsequence(int *arr, int n) {
  int *dp = new int[n];
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] < arr[i]) {
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans < dp[i]) {
      ans = dp[i];
    }
  }
  delete[] dp;
  return ans;
}