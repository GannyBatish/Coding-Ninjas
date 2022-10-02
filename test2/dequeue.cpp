/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/
class Node{
    public:
    int data;
    Node *next;
    Node(int n){
        data = n;
    }
};


class Deque {
    // Complete this class
    Node *head;
    Node *tail;
    int size;
    int capacity;
    public:
    Deque(int n){
        head = NULL;
        tail = NULL;
        size = 0;
        capacity = n;
    }
    void insertFront(int n){
        if(size<capacity){
        	Node *tmp = new Node(n);
        	if(head==NULL){
            	head = tmp;
            	tail = tmp;
        	}
        	else{
            	tmp->next = head;
            	head = tmp;
        	}
        	size++;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    
    void insertRear(int n){
        if(size<capacity){
            Node *tmp = new Node(n);
            if(head==NULL){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
            size++;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    
    void deleteFront(){
        if(size==0){
            cout<<-1<<endl;
            return;
        }
        if(size==1){
            head=NULL;
            tail = NULL;
        }
        else{
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        size--;
    }
    
    void deleteRear(){
        if(size==0){
            cout<<-1<<endl;
            return;
        }
        if(size==1){
            head = NULL;
            tail = NULL;
        }
        else{
            Node *tmp = head;
            while(tmp->next!=tail){
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
        }
        size--;
    }
    
    int getFront(){
        if(size==0){
            return -1;
        }
        return head->data;
    }
    
    int getRear(){
        if(size==0){
            return -1;
        }
        return tail->data;
    }
    
};
