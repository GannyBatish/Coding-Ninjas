#include <iostream>
using namespace std;

#include<queue>
void findMedian(int *arr, int n)
{
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int> > min;
    for(int i=0;i<n;i++){
        //heaps
        if(max.empty() && min.empty()){
            max.push(arr[i]);
            cout<<arr[i]<<" \n";
            continue;
        }
        if(arr[i]<max.top()){
            max.push(arr[i]);
        }
        else if(arr[i]>max.top()){
            min.push(arr[i]);
        }
        
        // balance
        cout<<"max: "<<max.size()<<endl;
        cout<<"min: "<<min.size()<<endl;
        if((max.size()-min.size())>1){
            min.push(max.top());
            max.pop();
        }
        else if((min.size()-max.size())>1){
            cout<<min.size()-max.size();
            max.push(min.top());
            min.pop();
        }
        
        //print median
        cout<<"max: "<<max.size()<<endl;
        cout<<"min: "<<min.size()<<endl;
        if((max.size()+min.size())%2==0){
            cout<<(max.top()+min.top())/2<<" avg\n\n";
        }
        else if(max.size()>min.size()){
            cout<<max.top()<<" max\n\n";
        }
        else if(min.size()>max.size()){
            cout<<min.top()<<" min\n\n";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
