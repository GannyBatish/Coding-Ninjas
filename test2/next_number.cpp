/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
Node *newNode(int data) 
{ 
    Node *new_node = new Node(data);
    return new_node; 
} 
Node *reverse(Node *head) 
{ 
    Node * prev = NULL; 
    Node * current = head; 
    Node * next; 
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    return prev; 
} 
  
/* Adds one to a linked lists and return the head 
node of resultant list */
Node *addOneUtil(Node *head) 
{ 
    // res is head node of the resultant list 
    Node* res = head; 
    Node *temp; 
  
    int carry = 1, sum; 
  
    while (head != NULL) //while both lists exist 
    { 
        // Calculate value of next digit in resultant list. 
        // The next digit is sum of following things 
        // (i) Carry 
        // (ii) Next digit of head list (if there is a 
        // next digit) 
        sum = carry + head->data; 
  
        // update carry for next calculation 
        carry = (sum >= 10)? 1 : 0; 
  
        // update sum if it is greater than 10 
        sum = sum % 10; 
  
        // Create a new node with sum as data 
        head->data = sum; 
  
        // Move head and second pointers to next nodes 
        temp = head; 
        head = head->next; 
    } 
  
    // if some carry is still there, add a new node to 
    // result list. 
    if (carry > 0) 
        temp->next = newNode(carry); 
  
    // return head of the resultant list 
    return res; 
} 
  
// This function mainly uses addOneUtil(). 
Node* addOne(Node *head) 
{ 
    // Reverse linked list 
    head = reverse(head); 
  
    // Add one from left to right of reversed 
    // list 
    head = addOneUtil(head); 
  
    // Reverse the modified list 
    return reverse(head); 
} 
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    head = reverse(head); 
  
    // Add one from left to right of reversed 
    // list 
    head = addOneUtil(head); 
  
    // Reverse the modified list 
    return reverse(head);
    /*if(head==NULL){
        return head;
    }
    if(head->next==NULL && head->data<9){
        head->data++;
        return head;
    }
    
    head->next = NextLargeNumber(head->next);
    return head;
    */
    /*else if(head->next==NULL && head->data==9){
        Node *tmp = new Node(1);
        tmp->next = head;
        head = tmp;
        return head;
    }
    else{
        
    }*/
}


