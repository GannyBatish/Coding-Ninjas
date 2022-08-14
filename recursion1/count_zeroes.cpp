
int countZeros(int n) {
    // Write your code here
    if(n==0){
        return 1;
    }
    if(n>=1 && n<=9){
        return 0;
    }
    if(n%10==0){
        return 1+countZeros(n/10);
    }else{
        return 0+countZeros(n/10);
    }
}