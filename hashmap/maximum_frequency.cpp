#include<unordered_map>
int highestFrequency(int arr[], int n) {
    unordered_map<int,int> freq;
    int max = 0;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        if(freq[arr[i]]>max){
            max = freq[arr[i]];
        }
    }
    int m = 0;
    for(int i=0;i<n;i++){
        if(freq[arr[i]]==max){
            m = arr[i];
            break;
        }
    }
    return m;
}