double geometricSum(int k) {
    // Write your code here
    if(k==0){
        return 1.0;
    }
    return 1.0/pow(2,k)+geometricSum(k-1);
}