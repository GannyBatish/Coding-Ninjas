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

Node *evenAfterOdd(Node *head)
{
  Node *temp=head;
  Node *evenHead=NULL;
  Node *oddTail=NULL;
  Node *oddHead=NULL;
  Node *evenTail=NULL;
  if(head==NULL || head->next==NULL)
  {
    return head;
  }
  while(temp != NULL)
  {
    if(temp->data%2!=0)
    {
      if(oddHead==NULL)
      {
        oddHead=temp;
        oddTail=temp;
      }else
      {
        oddTail->next=temp;
        oddTail=temp;
      }
    }else if(temp->data%2==0)
    {
      if(evenHead==NULL)
      {
        evenHead=temp;
        evenTail=temp;
      }else
      {
        evenTail->next=temp;
        evenTail=temp;
      }
    }
    temp=temp->next;
  }
  if(oddHead==NULL)
  {
    head=evenHead;
  }else
  {
    oddTail->next=evenHead;
    head=oddHead;
  }
  if(evenTail!=NULL)
  {
    evenTail->next=NULL;
  }
  return head;
}
