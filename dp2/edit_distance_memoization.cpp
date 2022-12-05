
int helper(string s1, string s2, int **output) {
  if (s1.length() == 0 || s2.length() == 0) {
    return max(s1.length(), s2.length());
  }
  int m = s1.length();
  int n = s2.length();

  if (output[m][n] != -1) {
    return output[m][n];
  }

  if (s1[0] == s2[0]) {
    output[m][n] = helper(s1.substr(1), s2.substr(1), output);
    return output[m][n];
  } else {
    // Insert
    int a = helper(s1.substr(1), s2, output);
    // Delete
    int b = helper(s1, s2.substr(1), output);
    // Replace
    int c = helper(s1.substr(1), s2.substr(1), output);

    output[m][n] = min(a, min(b, c)) + 1;
    return output[m][n];
  }
}

int editDistance(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();

  int **output = new int *[m + 1];
  for (int i = 0; i <= m; i++) {
    output[i] = new int[n + 1];
    for (int j = 0; j <= n; j++) {
      output[i][j] = -1;
    }
  }
  int ans = helper(s1, s2, output);
  for (int i = 0; i <= m; i++) {
    delete[] output[i];
  }
  delete[] output;

  return ans;
}