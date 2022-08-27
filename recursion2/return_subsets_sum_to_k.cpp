/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }
    int output1[10000][50], output2[10000][50];
    int size1 = subsetSumToK(input + 1, n - 1, output1, k - input[0]);
    int size2 = subsetSumToK(input + 1, n - 1, output2, k);
    for (int i = 0; i < size1; i++)
    {
        int s1 = output1[i][0];
        for (int j = 1; j <= s1; j++)
        {
            output[i][j + 1] = output1[i][j];
        }
        output[i][0] = s1 + 1;
        output[i][1] = input[0];
    }

    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j <= output2[i][0]; j++)
        {
            output[i + size1][j] = output2[i][j];
        }
    }
    return size1 + size2;
}