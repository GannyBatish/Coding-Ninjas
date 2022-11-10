#include<vector>
class PriorityQueue{
    vector<int> pq;
    public:
    PriorityQueue(){}
    
    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }
        else{
            return pqq[0];
        }
    }

    void insert(int element){
        pq.push_back(element);
        int child = pq.size()-1;
        while(child>0){
            int parent = (child-1)/2;
            if(pq[child]>pq[parent]){
                int tmp = pq[parent];
                pq[parent] = pq[child];
                pq[child] = tmp;
            }
            child = parent;
        }
    }

    int removeMax(){
        if(isEmpty()){
            return 0;
        }
        int res = getMax();
        int n = getSize() -1;
        int tmp = pq[n];
        pq[n] = pq[0];
        pq[0] = tmp;
        pq.pop_back();

        int parent = 0;
        int left = 2*parent+1;
        int right = 2*parent+2;
        bool placed = false;
        while(left<n && !placed){
            int max = parent;
            if(pq[max]<pq[left]){
                max = left;
            }
            if(right<n && pq[max]<pq[right]){
                max = right;
            }
            if(max==parent){
                placed = true;
                continue;
            }
            int tmp = pq[max];
            pq[max] = pq[parent];
            pq[parent] = tmp;
            parent = max;
            left = 2*parent+1;
            right = 2*parent+2;
        }
        return res;
    }
};