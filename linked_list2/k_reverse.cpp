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

Node *kReverse(Node *head, int k)
{
    if(k==0)
    {
        return head;
    }
	Node *current=head;
  Node *prev=NULL;
  Node *next=NULL;
  int count=0;
  while(count<k && current != NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
    count++;
  }
  if(next != NULL)
  {
    head->next=kReverse(next,k);
  }
  return prev;
}