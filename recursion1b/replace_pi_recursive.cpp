#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
    int len=strlen(input);
    if( input[0]=='\0' || input[1]=='\0'){
        return;
    }
    replacePi(input+1);
    len=strlen(input);
    if(input[0]=='p' && input[1]=='i'){
        for(int i=len;i>1;i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
