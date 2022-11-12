bool isMaxHeap(int arr[], int n) {
    // Write your code here
    if(n<2){
        return true;
    }
    bool res = true;
    for(int i=0;i<n;i++){
        int left =  2*i+1;
        int right = 2*i+2;
        if(left<n && arr[left]>arr[i]){
            res = res && false;
        }
        if(right<n && arr[right]>arr[i]){
            res = res && false;
        }
    }
    return res;
}