#include <iostream>
#include <string>
using namespace std;

/* 
int keypad(int num, string output[]){
   cout<<"num:"<<num<<endl;
    if(num == 0 || num == 1){
        output[0] = " ";
        return 1;
    }
    int size = keypad(num/10,output);
    int current = num%10;
    cout<<"current:"<<current<<endl;
    string str;
    switch(current){
        case 0:
            str = "";
            break;
        case 1:
            str = "";
            break;
        case 2:
            str = "abc";
            break;
        case 3:
            str = "def";
            break;
        case 4:
            str = "ghi";
            break;
        case 5:
            str = "jkl";
            break;
        case 6:
            str = "mno";
            break;
        case 7:
            str = "pqrs";
            break;
        case 8:
            str = "tuv";
            break;
        case 9:
            str = "wxyz";
            break;
    }
    cout<<str<<endl;
    for(int i=0;i<str.size();i++){
        cout<<"i: "<<i<<endl;
        for(int j=0;j<size;j++){
            output[j+size-1] = str[i]+output[j];
            cout<<"insert: "<<str[i]+output[j]<<endl;
        }
        size+=str.size();
        cout<<"size: "<<size<<"\n"<<endl;
    }
    return size;
}
 */


int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = " ";
        return 1;
    }
    int size = keypad(num/10,output);
    int current = num%10;
    string str;
    switch(current){
        case 2:
            str = "abc";
            break;
        case 3:
            str = "def";
            break;
        case 4:
            str = "ghi";
            break;
        case 5:
            str = "jkl";
            break;
        case 6:
            str = "mno";
            break;
        case 7:
            str = "pqrs";
            break;
        case 8:
            str = "tuv";
            break;
        case 9:
            str = "wxyz";
            break;
    }
    cout<<"size of array: "<<size<<endl;
    cout<<"size of str: "<<str.size()<<endl;
    
    for(int i=0;i<str.size();i++){
        /* for(int j=0;j<size;j++){
            output[j+size-1] = str[i]+output[j];
        } */

        cout<<"inserting "<<str[i]<<" at "<<i<<endl;
        output[i] = str[i]+output[i];
    }
    if(size==1){
        size+=str.size()-1;
    }else{
        size+=str.size();
    }
    return size;
}
/* x is str.size. This function copies array elements x-1 times */
void copyArrayElements(int *arr,int x,int size){
    if(size==1){
        return;
    }
    int k=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<size;j++){
            arr[j+size] = arr[j];
        }

    }
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
