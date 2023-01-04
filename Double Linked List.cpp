#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* prev;
	Node* next;
};

void print_data(Node* head) {
	if (head == NULL)
		cout << "Linked list is empty";
	Node* ptr = NULL;
	ptr = head;
	while (ptr != NULL) {
		cout << " " << ptr->data;
		ptr = ptr->next;
	}
	cout << "\n";
}
Node* addToEmpty(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	head = temp;
	return head;
}
Node* addAtBeg(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
}
Node* addAtEnd(Node* head, int data) {
	Node* temp = new Node();
	Node* tp = new Node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	tp = head;
	while (tp->next != NULL) {
		tp = tp->next;
	}
	tp->next = temp;
	temp->prev = tp;
	return head;
}
Node* addAfterPos(Node* head, int data, int position) {
	Node* newp = NULL;
	Node* temp = head;
	Node* temp2 = NULL;
	newp = addToEmpty(newp, data);
	while (position != 1) {
		temp = temp->next;
		position--;
	}
	if (temp->next == NULL) {
		temp->next = newp;
		newp->prev = temp;
		return head;
	}
	else {
		temp2 = temp->next;
		temp->next = newp;
		temp2->prev = newp;
		newp->next = temp2;
		newp->prev = temp;
		return head;
	}
}
Node* addBeforePos(Node* head, int data, int position) {
	Node* newp = NULL;
	Node* temp = head;
	Node* temp2 = NULL;
	newp = addToEmpty(newp, data);
	int pos = position;
	while (pos > 2) {
		temp = temp->next;
		pos--;
	}
	if (position == 1) {
		head = addAtBeg(head, data);
		return head;
	}
	else {
		temp2 = temp->next;
		temp->next = newp;
		temp2->prev = newp;
		newp->next = temp2;
		newp->prev = temp;
		return head;
	}
}
Node* createList(Node* head) {
	int n, d, i;
	cout << "Enter number of nodes: ";
	cin >> n;
	if (n == 0) 
		return head;
	cout << "Enter the element for the node 1: ";
	cin >> d;
	head = addToEmpty(head, d);
	for (i = 1; i < n; i++) {
		cout << "Enter the element for the node " << i + 1 << ": ";
		cin >> d;
		head = addAtEnd(head, d);
	}
	return head;
}
Node* delFirst(Node* head) {
	Node* temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
	head->prev = NULL;
	return head;
}
Node* delLast(Node* head) {
	Node* temp = head;
	Node* temp2 = new Node();
	while (temp->next != NULL) 
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	free(temp);
	return head;
}
int main() {
	Node* head = NULL;
	Node* ptr = new Node();
	head = createList(head);	//creating doubly link list
	print_data(head);
	int position = 2;
	head = addAtBeg(head, 56);	//adding at beginning
	head = addAtEnd(head, 49);	//adding at end
	head = addAfterPos(head, 23, position);	//adding after position
	print_data(head);
	head = addBeforePos(head, 12, position);	//adding before position
	print_data(head);
	head = delFirst(head);		//deleting first
	head = delLast(head);		//deleting last
	print_data(head);
	return 0;
}