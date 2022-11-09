#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
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
};