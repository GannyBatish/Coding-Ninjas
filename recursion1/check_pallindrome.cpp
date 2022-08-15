#include <bits/stdc++.h>
bool isPal(char input[],int s,int e){
    if(s==e){
        return true;
    }
    if(input[s]!=input[e]){
        return false;
    }
    if(s<e+1){
        return isPal(input,s+1,e-1);
    }
    return true;
}
bool checkPalindrome(char input[]) {
    int e=strlen(input);
    int s=0;
    if(e==0){
        return true;
    }
    return isPal(input,s,e-1);
}