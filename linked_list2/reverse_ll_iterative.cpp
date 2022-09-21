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

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL ||head->next==NULL)
  {
    return head;
  }
  Node *tail=head->next;
  Node *newHead=reverseLinkedList(head->next);
  tail->next=head;
  head->next=NULL;
  return newHead;
}