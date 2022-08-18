#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]) {
    int len = strlen(input);
    if(len==1){
        int a = input[0]-48;
        return a;
    }
    int a = stringToNumber(input+1);
    len = strlen(input);
    int b = input[0]-48;
    int power = pow(10,len-1);
    return (b*power)+a;  
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
