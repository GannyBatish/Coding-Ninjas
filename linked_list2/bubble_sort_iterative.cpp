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
Node *bubbleSort(Node *head)
{
	Node *current=head;
  Node *index=NULL;
  int temp;
  if(head==NULL)
  {
    return head;
  }else
  {
    while(current!=NULL)
    {
      index=current->next;
      while(index!=NULL)
      {
        if(current->data > index->data)
        {
          temp=current->data;
          current->data=index->data;
          index->data=temp;
        }
        index=index->next;
      }
      current=current->next;
    }
    return head;
  }
}