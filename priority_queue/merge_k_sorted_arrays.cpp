#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    /*for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i]->size();j++){
            pq.push(input[i]->at(j));
        }
    }*/
    for(int i=0;i<input.size();i++){
        vector<int> &v = *input[i];
        for(int j=0;j<v.size();j++){
            pq.push(v[j]);
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}