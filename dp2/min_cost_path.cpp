int helper(int **input, int m, int n, int row, int col)
{
    if (row == m - 1 && col == n - 1)
    {
        return input[row][col];
    }
    int side = INT_MAX, down = INT_MAX, diagonal = INT_MAX;
    if (row + 1 < m)
    {
        side = helper(input, m, n, row + 1, col);
    }
    if (col + 1 < n)
    {
        down = helper(input, m, n, row, col + 1);
    }
    if (row + 1 < m && col + 1 < n)
    {
        diagonal = helper(input, m, n, row + 1, col + 1);
    }

    return input[row][col] + min(side, min(down, diagonal));
}

int minCostPath(int **input, int m, int n)
{
    return helper(input, m, n, 0, 0);
}
