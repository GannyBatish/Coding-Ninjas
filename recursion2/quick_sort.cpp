#include<iostream>
using namespace std;

/*
	To apply the method explained in the hint video, we have to add
    two more parameters in the function call. This can be done by calling
    a helper function from given function. The helper function can have 
    three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	*/
void quickSort(int input[], int start, int end){
    if(start>=end){
        return;
    }
    int pivot = input[start];
    int smallCount = 0;
    int largeCount = 0;
    for(int i=start+1;i<=end;i++){
        if(input[i]>=pivot){
            largeCount++;
        }else{
            smallCount++;
        }
    }
    int pivotIndex = start+smallCount;
    int temp = input[start + smallCount];
    input[start + smallCount] = pivot;
    input[start] = temp;
    int i = start;
    int j = end;
    while(input[i]!=pivot || input[j]!=pivot){
        if(input[i]<pivot){
            i++;
        }
        else if(input[j]>pivot){
            j--;
        }else{
            int temp = input[j];
            input[j] = input[i];
            input[i] = temp;
            i++;
            j--;
        }
    }
    
    quickSort(input,start,start + smallCount-1);
    quickSort(input,start+smallCount+1,end);
    
}	


void quickSort(int input[], int size) {
    if(size==0||size==1){
        return;
    }
    quickSort(input, 0, size - 1);
}

/* void quickSort(int input[], int start, int end){
    if(start>=end){
        return;
    }
    int random = input[start];
    int smallCount = 0;
    int largeCount = 0;
    for(int i=start;i<=end;i++){
        if(input[i]>=random){
            largeCount++;
        }else{
            smallCount++;
        }
    }
    cout<<smallCount<<" "<<largeCount<<endl;
    int temp = input[smallCount];
    input[smallCount] = random;
    input[start] = temp;
    quickSort(input,start,smallCount-1);
    quickSort(input,smallCount+1,end);
    int i = start;
    int j = end;
    while(i<smallCount && j>smallCount+1){
        if(input[i]<random){
            i++;
        }
        else if(input[j]>random){
            j--;
        }else{
            int temp = input[j];
            input[j] = input[i];
            input[i] = temp;
        }
    }
}
		


void quickSort(int input[], int size) {
    if(size==0||size==1){
        return;
    }
    quickSort(input, 0, size - 1);
}

 */
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

