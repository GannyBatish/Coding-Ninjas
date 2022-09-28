/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Queue {
	// Define the data members
    Node *head;
    Node *tail;
    int size;
   public:
    Queue() {
		// Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return head==NULL;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *tmp = new Node(data);
        if(isEmpty()){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
        	tail = tail->next;
        }
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        int res = head->data;
        if(size==1){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->next;
        }
        size--;
        return res;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
};