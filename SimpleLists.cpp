#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void initFirstNode(Node *head, int n)
{
	head->data = n;
	head->next = NULL;
}

void addNode(Node *head, int n)
{
	Node *elem = head;	
	while (elem->next)
	{
		elem = elem->next;
	}
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	elem->next = newNode;
}

void insertFront(Node **head, int n)
{
	Node *newNode = new Node;
	newNode->next = *head;
	newNode->data = n;
	*head = newNode;
}

Node* searchNode(Node *head, int n)
{
	Node* cur = head;
	while(cur)
	{
		if(cur->data == n) return cur;
		else cur = cur->next;
	}
	cout<<"No node " << n << " in list.\n";
}

void deleteNode(Node **head, int n)
{
	Node *elem = *head;
	Node *found = elem;
	if (elem->data == n)
	{
		*head = elem->next;
	}
	else {
	while (elem)
	{
			
		if (elem->next->data == n)
		{
			found = elem->next;			
			elem->next = found->next;
			delete found;
			break;
		}
		elem = elem->next;	
	}}
}

void display(Node *head)
{
	Node *elem = head;
	
	while (elem)
	{
		cout<< elem->data << " ";
		elem = elem->next;	
	}
	cout<< endl;
}

int main()
{
	struct Node *head = new Node;

	initFirstNode(head,10);
	addNode(head,20);
	addNode(head,30);
	addNode(head,40);
	insertFront(&head,5);
	display(head);
	deleteNode(&head,30);
	deleteNode(&head,5);
	deleteNode(&head,40);
	display(head);

	return 0;
}
