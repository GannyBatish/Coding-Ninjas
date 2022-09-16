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
int findNode(Node *head,int data)
{
	int i=0;
    Node *tmp = head;
    while(tmp!=NULL){
        if(tmp->data==data){
            return i;
        }
        i++;
        tmp = tmp->next;
    }
    return -1;
}