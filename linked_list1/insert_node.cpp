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



Node* insertNode(Node *head,int i,int data)
{
  Node *newNode = new Node(data);
  Node *tmp = head;
  if(tmp==NULL)
  {
    return tmp;
  }
  if(i==0)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }
  head->next = insertNode(tmp->next,i-1,data);
  return head;
}