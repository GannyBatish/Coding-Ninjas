string findWinner(int n, int x, int y, int index = 0) {
  int *arr = new int[n + 1];
  for (int i = 0; i <= n; i++) {
    arr[i] = -1;
  }
  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    int ans1 = 1 ^ arr[i - 1];
    int ans2 = 0, ans3 = 0;
    if (i >= x) {
      ans2 = 1 ^ arr[i - x];
    }
    if (i >= y) {
      ans3 = 1 ^ arr[i - y];
    }
    if (ans1 + ans2 + ans3 > 0) {
      arr[i] = 1;
    } else {
      arr[i] = 0;
    }
  }
  if (arr[n] == 1) {
    return "Beerus";
  }
  return "Whis";
}