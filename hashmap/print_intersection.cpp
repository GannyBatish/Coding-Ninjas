#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(mp[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            mp[arr2[i]]--;
        }
    }
}