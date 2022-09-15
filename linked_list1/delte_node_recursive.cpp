Node* deleteNodeRec(Node *head,int i)
{
  if(head==NULL){
      return NULL;
  }
    if(i==0){
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    head->next = deleteNodeRec(head->next,i-1);
    retur
}