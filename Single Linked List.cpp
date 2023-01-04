#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* link;
};
void count_of_nodes(Node* head) {
	int count = 0;
	if (head == NULL)
		cout << "Linked list is empty";
	Node* ptr = NULL;
	ptr = head;
	while (ptr != NULL) {
		count++;
		ptr = ptr->link;
	}
	count << count;
}
void print_data(Node* head) {
	if (head == NULL)
		cout << "Linked list is empty";
	Node* ptr = NULL;
	ptr = head;
	while (ptr != NULL) {
		cout << " " << ptr->data;
		ptr = ptr->link;
	}
	cout << "\n";
}
Node* add_at_end(Node* ptr, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return temp;
}
void add_beg(Node** head, int d) {
	Node* ptr = new Node();
	ptr->data = d;
	ptr->link = NULL;
	ptr->link = *head;
	*head = ptr;
}
void add_at_pos(Node* head, int data, int pos) {
	Node* ptr = head;
	Node* ptr2 = new Node();
	ptr2->data = data;
	ptr2->link = NULL;
	pos--;
	while (pos != 1) {
		ptr = ptr->link;
		pos--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}
Node* del_first(Node* head) {
	if (head == NULL)
		cout << "List is already empty!";
	else {
		Node* temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	return head;
}
void del_last(Node* head) {
	if (head == NULL)
		cout << "List is already empty!";
	else if (head->link == NULL) {
		free(head);
		head = NULL;
	}
	else {
		Node* temp = head;
		while (temp->link->link != NULL) {
			temp = temp->link;
		}
		free(temp->link);
		temp->link = NULL;
	}
}
void del_pos(Node** head, int position) {
	Node* current = *head;
	Node* previous = *head;
	if (*head == NULL)
		cout << "List is already empty!";
	else if (position == 1) {
		*head = current->link;
		free(current);
		current = NULL;
	}
	else {
		while (position != 1) {
			previous = current;
			current = current->link;
			position--;
		}
		previous->link = current->link;
		free(current);
		current = NULL;
	}
}
Node* del_list(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->link;
		free(head);
		head = temp;
	}
	return head;
}
Node* reverse(Node* head) {
	Node* prev = NULL;
	Node* next = NULL;
	while (head != NULL) {
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}
int main() {
	Node* head = new Node();
	head->data = 45;
	head->link = NULL;
	Node* ptr = head;
	ptr = add_at_end(ptr, 98);				//adding at end
	ptr = add_at_end(ptr, 3);
	ptr = add_at_end(ptr, 67);
	print_data(head);
	add_beg(&head, 4);					//adding at beginning
	add_beg(&head, 5);
	print_data(head);
	add_at_pos(head, 8, 4);				//add at position
	add_at_pos(head, 12, 6);
	print_data(head);
	head = del_first(head);				//deleting first node
	print_data(head);
	del_last(head);					//deleting last node
	print_data(head);
	del_pos(&head, 3);				//deleting node at position
	print_data(head);
	head = reverse(head);			//Reversing linked list
	print_data(head);
	head = del_list(head);
	if (head == NULL)
		cout << "Linked List Deleted Successfully.";
	return 0;
}