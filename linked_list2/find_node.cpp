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

int findNodeRec(Node *head,int data)
{
  if(head == NULL)
  {
    return -1;
  }
  else if(head->data==data)
  {
    return 0;
  }
  int smallAns=findNodeRec(head->next,data);
  if(smallAns==-1)
  {
    return -1;
  }
  return smallAns+1;
}