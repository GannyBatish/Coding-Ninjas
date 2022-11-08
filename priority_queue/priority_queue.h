#include<vector>
class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue(){}
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(!isEmpty()){
            return pq[0];
        }
        else{
            return 0;
        }
    }

    void insert(int n){
        pq.push_back(n);
        int child = pq.size() - 1;
        while(child>0){
            int parent = (child-1)/2;
            if(pq[parent]>pq[child]){
                int tmp = pq[parent];
                pq[parent] = pq[child];
                pq[child] = tmp;
            }
            child = parent;
        }
    }

    int removeMin() {
        if(pq.size()==0){
            return 0;
        }
        int ans = getMin();
        int n = getSize()-1;
        int tmp = pq[n];
        pq[n] = pq[0];
        pq[0] = tmp;
        pq.pop_back();
        
        
        int parent = 0;
        int left = 2*parent+1;
        int right = 2*parent+2;
        bool placed = false;
        while(left<n && !placed){
            int min = parent;
            if(pq[min]>pq[left]){
                min = left;
            }
            if(right<n && pq[min]>pq[right]){
                min = right;
            }
            if(min==parent){
                placed = true;
                continue;
            }
            int tmp = pq[parent];
            pq[parent] = pq[min];
            pq[min] = tmp;
            parent = min;
            left = 2*parent+1;
            right = 2*parent+2;
        }
        return ans;
    }

    /*void balance(int n){
        if(n<2){
            return;
        }
        else{
            int parent = (n-1)/2;
            if(pq[n]<pq[parent]){
                swap(pq[n],pq[parent]);
                balance(parent);
            }
        }
    }

    void insert(int n){
        pq.push_back(n);
        balance(this->next++);
    }
    */
}