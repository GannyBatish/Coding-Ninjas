
int knapsack(int *weights, int *values, int n, int maxWeight) {
  if (n == 0 || maxWeight == 0) {
    return 0;
  }

  if (weights[0] > maxWeight) {
    return knapsack(weights + 1, values + 1, n - 1, maxWeight);
  }
  int inc = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) +
            values[0];
  int notInclude = knapsack(weights + 1, values + 1, n - 1, maxWeight);

  return max(inc, notInclude);
}