#include <iostream>

using namespace std;

void heapSort(int arr[], int n){
    //build heap
    for(int i=1;i<n;i++){
        cout<<i<<endl;
        int child = i;
        while(child>0){
            int parent = (child-1)/2;
            if(arr[parent]>arr[child]){
                int tmp = arr[child];
                arr[child] = arr[parent];
                arr[parent] = tmp;
            }
            child = parent;
        }
    }

    // rearrange elements
    for(int i=0;i<n;i++){
        int tmp = arr[n-i-1];
        arr[n-i-1] = arr[0];
        arr[0] = tmp;
        bool placed = false;
        int parent = 0;
        int left = 2*parent+1;
        int right = 2*parent+2;
        while(left<n-i-1 && !placed){
            int min = parent;
            if(arr[min]>arr[left]){
                min = left;
            }
            if(right<n-i-1 && arr[min]>arr[right]){
                min = right;
            }
            if(min==parent){
                placed = true;
                continue;
            }
            int tmp = arr[parent];
            arr[parent] = arr[min];
            arr[min] = tmp;
            parent = min;
            left = 2*parent+1;
            right = 2*parent+2;
        }
    }
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}