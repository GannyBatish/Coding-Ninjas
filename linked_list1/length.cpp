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
