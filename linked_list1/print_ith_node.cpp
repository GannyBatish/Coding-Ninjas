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



void printIthNode(Node *head, int i)
{
    //Write your code here
    int len = length(head);
    if(i<len){
        Node *tmp = head;
    	for(int j=0;j<i;j++){
        	tmp = tmp->next;
    	}
    	if(tmp!=NULL ){
			cout<<tmp->data;
    	}
    }
}