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
Node* removeDuplicates(Node *head)
{
    Node *tmp = head;
    if(tmp==NULL || tmp->next==NULL){
        return head;
    }
    while(tmp->next!=NULL){
        if(tmp->data==tmp->next->data){
            tmp->next = tmp->next->next;
        }
        else{
            tmp = tmp->next;
        }
    }
    return head;
}

