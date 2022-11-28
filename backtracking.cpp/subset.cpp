#include<bits/stdc++.h>
using namespace std;

int countSubsetSumToK(int* arr,int n,int sum){
    int count =0;
    if(n==0){
        if(sum==0){
            count++;
        }
        return count;
    }
    if(arr[n-1] > sum){
        count += countSubsetSumToK(arr, n-1, sum);
    } else {
        count += countSubsetSumToK(arr, n-1, sum);
        count += countSubsetSumToK(arr, n-1, sum-arr[n-1]);
    }
    return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum;
    cin >> n >> sum;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int **out = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
      out[i] = new int[sum + 1];
      for (int j = 0; j <= sum; j++) {
        out[i][j] = -1;
      }
    }
    cout << countSubsetSumToK(arr, n, sum) << endl;
    for (int i = 0; i < n; i++) {
      delete[] out[i];
    }
    delete[] arr;
    delete[] out;
  }

  return 0;
}