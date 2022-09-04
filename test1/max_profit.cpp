#include<algorithm>
/*int maximumProfit(int budget[], int n) {
    int *profits = new int[n];
    int k=0;
    for(int i=0;i<n;i++){
        int rate = budget[i];
        int profit = 0;
        for(int j=0;j<n;j++){
            if(budget[j]>=rate){
                profit+=rate;
            }
        }
        profits[k++] = profit;
    }
    sort(profits,profits+k,greater<int>());
    return profits[0];
}*/
int maximumProfit(int budget[],int n){
    sort(budget,budget+n);
    int profit = 0;
    for(int i=0;i<n;i++){
        int rate = budget[i];
        int people = n-i;
        int tmp = rate*people;
        if(tmp>profit){
            profit = tmp;
        }
    }
    return profit;
}