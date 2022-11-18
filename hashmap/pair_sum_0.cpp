#include<unordered_map>
#include<vector>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int,int> mp;
    int s = 0;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        s+=mp[0-arr[i]];
        if(0-arr[i] ==arr[i]){
            s--;
        }
    }
    return s/2;
}