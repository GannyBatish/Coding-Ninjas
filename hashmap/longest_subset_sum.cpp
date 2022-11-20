#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> ump;
    int sum = 0, maxCount = 0;
    ump[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (ump.count(sum) > 0)
        {
            maxCount = max(maxCount, i - ump[sum]);
        }
        else
        {
            ump[sum] = i;
        }
    }
    return maxCount;
}