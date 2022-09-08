#include<iostream>
using namespace std;

class dynamicArray{
    private:
    int *arr;
    int index;
    int size;

    public:
    dynamicArray(){
        arr = new int[10];
        index = 0;
        size = 10;
    }
    dynamicArray(dynamicArray& array){
        int *tmp = new int[array.size];
        for(int i=0;i<array.index;i++){
            tmp[i] = array.arr[i];
        }
        this->arr = tmp;
        this->index = array.index;
        this->size = array.size;
    }
    void operator= (dynamicArray const &array){
        int *tmp = new int[array.size];
        for(int i=0;i<array.index;i++){
            tmp[i] = array.arr[i];
        }
        this->arr = tmp;
        this->index = array.index;
        this->size = array.size;
    }

    void push(int ele){
        if(index==size){
            int *newArr = new int[size*2];
            for(int i=0;i<size;i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
            size*=2;
        }
        arr[index++] = ele;
    }

    void push(int ele,int i){
        if(i<index){
            arr[i] = ele;
        }
        else if(i==index){
            arr[index++] = ele;
        }
        else{
            return;
        }
    }

    int get(int i){
        if(i<index){
            return arr[i];
        }
        else{
            return -1;
        }
    }

    void print(){
        for(int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }
    }


};

int main(){
    
}