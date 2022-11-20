#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int, int> ump;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += ump[arr[i] + k];
        if (k != 0)
        {
            count += ump[arr[i] - k];
        }
        ump[arr[i]]++;
    }
    return count;
}