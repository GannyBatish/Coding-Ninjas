#include<string>
using namespace std;
template <typename v>
class mapNode{
    public:
    string key;
    v value;
    mapNode *next;

    mapNode(int key,v value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapNode(){
        delete next;
    }
}

class ourmap{
    mapNode<v>** buckets;
    int count;
    int bucketSize;

    public:
    ourmap(){
        count = 0;
        bucketSize = 5;
        buckets = new mapNode<v>*[bucketSize];

        for(int i=0;i<bucketSize;i++){
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
       for(int i=0;i<bucketSize;i++){
            delete buckets[i];
        } 
        delete [] buckets;
    }

    private:
    int getBucketIndex(string key){
        int hash = 0;

        //get hash
        int coeff = 1;
        for(int i=key.length()-1;i>=0;i--){
            hash += key[i]*coeff;
            coeff *= 37;
            hash = hash % bucketSize;
            coef = coeff % bucketSize;
        }

        return hash%bucketSize;
    }

    void rehash(){
        mapNode<v>** tmp = buckets;
        buckets = newmapNode<v>*[2*bucketSize];
        for(int i=0;i<2*bucketSize;i++){
            buckets[i] = NULL;
        }

        int old = bucketSize;
        bucketSize*=2;
        count = 0;
        for(int i=0;i<old;i++){
            mapNode<v>* head = tmp[i];
            while(head!=NULL){
                string key = head->key;
                v value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0;i<old;i++){
            mapNode<v>* head = tmp[i];
            delete head;
        }
        delete [] tmp;
    }

    public:

    double getLoad(){
        return (1.0*count)/bucketSize;
    }

    int size(){
        return count;
    }

    v getValue(string key){
        int index = getBucketIndex(key);
        mapNode<v>* head = buckets[index];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key,v value){
        int index = getBucketIndex(key);
        mapNode<v>* head = buckets[index];
        while(head!=NULL){
            if(head->key==key){
                head->value = value;
                return;
            }
            head = head->next;
        }

        mapNode<v>* newNode = new mapNode<v>(key,value);
        newNode-> next = buckets[index];
        buckets[index] = newNode;
        count++;

        // rehashing
        double loadFactor = (1.0*count)/bucketSize;
        if(loadFactor>0.7){
            rehash();
        }
    }

    v remove(string key){
        int index = getBucketIndex(key);
        mapNode<v>* head = buckets[index];
        mapNode<v>* prev = NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[index] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                v res = head->value;
                head->next = NULL;
                delete head;
                count--;
                return res;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
}