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
    if(head==NULL)
    {
        return 0;
    }
    return 1+length(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    if(n==0){
        return head;
    }
    else if(head==NULL){
        return head;
    }
    int len = length(head);
    Node *tmp = head;
    for(int i=0;i<len-n;i++){
        tmp = tmp->next;
    }
    Node *tmpH = head;
    head = tmp;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = tmpH;
    for(int i=0;i<len-n;i++){
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return head;
    
}
