const long long m = 1e9 + 7;

int balancedBTs(int n) {

  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 3;
  }
  int a = balancedBTs(n - 1);
  int b = balancedBTs(n - 2);
  int temp1 = (int)(((long long)(a)*a) % m);
  int temp2 = (int)((2 * (long long)(a)*b) % m);
  int ans = (int)(((long long)temp1 + temp2) % m);
  return ans;
}