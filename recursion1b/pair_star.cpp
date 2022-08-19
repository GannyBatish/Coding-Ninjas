#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    int len = strlen(input);
    if(len==0){
        return;
    }
    pairStar(input+1);
    char x = input[0];
    if(input[1]==x){
        len = strlen(input);
        for(int i=len+1;i>1;i--){
            input[i] = input[i-1];
        }
        input[1] = '*';
    }
    return;
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
