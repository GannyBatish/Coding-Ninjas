#include <iostream>
using namespace std;

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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *midPoint(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *a, Node *b){
    Node *head = NULL;
    Node *ptr = NULL;
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    if(a->data > b->data){
        head = b;
        ptr = b;
        b = b->next;
    }
    else{
        head = a;
        ptr = a;
        a = a->next;
    }
    
    while(a!=NULL && b!=NULL){
        if(a->data > b->data){
            ptr->next = b;
            ptr = ptr->next;
            b = b->next;
        }
        else{
            ptr->next = a;
            ptr = ptr->next;
            a = a->next;
        }
    }
    if(a==NULL){
        ptr->next = b;
    }
    else{
        ptr->next = a;
    }
    return head;
}

Node* mergeSort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid = midPoint(head);
    Node *right = mid->next;
    Node *left = head;
    mid->next = NULL;
    Node *tmp = mergeSort(left);
    Node *tmp2 = mergeSort(right);
    Node *newHead = mergeTwoSortedLinkedLists(tmp,tmp2);
    return newHead;

}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}