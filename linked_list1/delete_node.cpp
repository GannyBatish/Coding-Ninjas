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

int length(Node *head)
{
    //Write your code here
    Node *tmp = head;
    int len = 0;
    while(tmp!=NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}


Node *deleteNode(Node *head, int pos)
{
    int len = length(head);
    Node *tmp = head;
    if(pos<len){
        if(pos==0){
            head = head->next;
        }
        else if(pos==1){
            tmp = tmp->next;
            head->next = tmp->next;
            delete tmp;
        }
        else{
            for(int i=0;i<pos-1;i++){
            tmp = tmp->next;
        	}
            Node *a = tmp;
            tmp = tmp->next;
            a->next = tmp->next;
            delete tmp;
        }
    }
    return head;
}
