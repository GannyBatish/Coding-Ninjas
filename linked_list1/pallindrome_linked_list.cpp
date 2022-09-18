/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* reverse(Node *head){
    Node *tmp = head;
    Node *head2 = NULL;
    while(tmp!=NULL){
        Node *newNode = new Node(tmp->data);
        newNode->next = head2;
        head2 = newNode;
        tmp = tmp->next;
    }
    return head2;
    
}

bool isPalindrome(Node *head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *head2 = reverse(head);
    bool isPal = true;
    Node *tmp = head;
    Node *tmp2 = head2;
    while(isPal && (tmp!=NULL || tmp2!=NULL)){
        if(tmp->data!=tmp2->data){
            isPal = false;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    return isPal;
}