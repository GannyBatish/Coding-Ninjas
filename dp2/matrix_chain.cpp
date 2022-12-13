#include<bits/stdc++.h>
int matrixChainMultiplication(int *arr, int n) {
  n++;
  int **out = new int *[n];
  for (int i = 0; i < n; i++) {
    out[i] = new int[n];
  }
  for (int i = 1; i < n; i++) {
    out[i][i] = 0;
  }
  for (int loop = 2; loop < n; loop++) {
    for (int i = 1; i < n - loop + 1; i++) {
      int j = i + loop - 1;
      out[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
        int ans = out[i][k] + out[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
        if (ans < out[i][j]) {
          out[i][j] = ans;
        }
      }
    }
  }
  return out[1][n - 1];
}