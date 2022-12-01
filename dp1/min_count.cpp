int minCount(int n)
{
	//Write your code here
        if (n <= 2) {
          return n;
        }

        int *dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
          int minimum = n;
          for (int j = 1; j * j <= i; j++) {
            minimum = min(minimum, dp[i - (j * j)]);
          }
          dp[i] = minimum + 1;
        }
        int result = dp[n];
        delete[] dp;
        return result;
}