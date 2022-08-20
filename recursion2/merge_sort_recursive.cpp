#include <iostream>
using namespace std;

void sort(int input[],int si,int ei){
    int mid = (si+ei)/2;
    int mi = si;
    int len1 = mid-si+1;
    int len2 = ei-mid;
    
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    
    for(int i=0;i<len1;i++){
        arr1[i] = input[mi++];
    }
    mi=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i] = input[mi++];
    }
    
    int i1 = 0;
    int i2 = 0;
    mi = si;
    while(i1<len1 && i2<len2){
        if(arr1[i1]<arr2[i2]){
            input[mi++] = arr1[i1++];
        }
        else{
            input[mi++] = arr2[i2++];
        }
    }
    while(i1<len1){
        input[mi++] = arr1[i1++];
    }
    while(i2<len2){
        input[mi++] = arr2[i2++];
    }
    
    delete []arr1;
    delete []arr2;
}

void merge_sort(int input[],int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge_sort(input,start,mid);
    merge_sort(input,mid+1,end);
    sort(input,start,end);
}

void mergeSort(int input[], int size){
	if(size==0){
        return;
    }
    int mid = size/2;
    merge_sort(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
