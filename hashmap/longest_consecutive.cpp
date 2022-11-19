#include<vector>
#include<unordered_map>
#include<algorithm>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
     unordered_map<int, bool> ump;
    unordered_map<int, int> index;
    int start, end, maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]] = true;
        if (index.count(arr[i]) == 0)
        {
            index[arr[i]] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ump[arr[i]])
        {
            int startT = arr[i], endT = arr[i], count = 1;
            while (ump[endT + 1])
            {
                count++;
                ump[++endT] = false;
            }
            while (ump[startT - 1])
            {
                count++;
                ump[--startT] = false;
            }
            if (count > maxCount)
            {
                start = startT;
                end = endT;
                maxCount = count;
            }
            else if (count == maxCount)
            {
                if (index[startT] < index[start])
                {
                    start = startT;
                    end = endT;
                    maxCount = count;
                }
            }
        }
    }

    vector<int> ans;
    ans.push_back(start);
    if (maxCount > 1)
    {
        ans.push_back(end);
    }
    return ans;

}