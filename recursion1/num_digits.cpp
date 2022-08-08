int count(int n){
    //write your code here
    if(n>=0 && n<=9){
        return 1;
    }
    return count(n/10)+1;
}
