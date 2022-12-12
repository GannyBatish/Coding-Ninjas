
int helper(int a, int b, int currNum, int currSum) {
  int result = 0;
  int p = pow(currNum, b);
  while (p + currSum < a) {
    result += helper(a, b, currNum + 1, currSum + p);
    currNum++;
    p = pow(currNum, b);
  }

  if (p + currSum == a) {
    result++;
  }
  return result;
}

int getAllWays(int a, int b) { return helper(a, b, 1, 0); }
