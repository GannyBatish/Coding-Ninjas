#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        q.push(i);
        pq.push(arr[i]);
    }
    int time = 0;
    while (!q.empty()){
        if(arr[q.front()] == pq.top()){
            int index = q.front();
            q.pop();
            pq.pop();
            time++;
            if (index == k){
                break;
            }
        }
        else{
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
    return time;
}