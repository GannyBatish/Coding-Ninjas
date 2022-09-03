#include<algorithm>
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    return min_element(input,input+size)-input;
}