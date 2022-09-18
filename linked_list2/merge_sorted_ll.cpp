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

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}