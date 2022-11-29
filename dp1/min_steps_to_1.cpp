int countMinStepsToOne(int n) {
  if (n <= 1)
    return 0;
  int x = INT_MAX, y = INT_MAX, z = INT_MAX;
  if (n % 3 == 0)
    x = 1 + countMinStepsToOne(n / 3);
  if (n % 2 == 0)
    y = 1 + countMinStepsToOne(n / 2);
  z = 1 + countMinStepsToOne(n - 1);
  return min(x, min(y, z));
}