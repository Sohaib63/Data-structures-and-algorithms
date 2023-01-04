#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* front = NULL;
node* rear = NULL;
node* temp=new node;
void Enqueue() {
    int val;
    cout << "Insert the element in queue : ";
    cin >> val;
    if (rear == NULL) {     //when list is empty then a node is created and is stored in front and rear both
        rear = new node;
        rear->next = NULL;
        rear->data = val;
        front = rear;
    }
    else {                  //a node is added at tail and that new node is stored in rear here front is not disturbed
        temp = new node;        //it involves both case (front==rear) and when (front!=rear)
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}
void Dequeue() {
    temp = front;
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
    }
    else if (front==rear){
        cout << "Element deleted from queue is : " << front->data << endl;
        free(temp);
        front = NULL;
        rear = NULL;
    }
    else{
        cout << "Element deleted from queue is : " << front->data << endl;
        front = front->next;
        free(temp);
    }
}
void Front() {
    if ((front == NULL) && (rear == NULL)) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Front element is: ";
        cout << front->data<<endl;            //it involves both case (front==rear) and when (front!=rear)
    }
    
}
void Print() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout << "Queue is empty" << endl;
    }
    cout << "Queue elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int ch;
    
    do {
        cout << "1) Insert element to queue" << endl;
        cout << "2) Delete element from queue" << endl;
        cout << "3) Display the front element of queue" << endl;
        cout << "4) Display all the elements of queue" << endl;
        cout << "5) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        if (ch == 1) {
            Enqueue();
        }
        else if (ch == 2) {
            Dequeue();
        }
        else if (ch == 3) {
            Front();
        }
        else if (ch == 4) {
            Print();
        }
        else if (ch == 5) {
            cout << "Exit" << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
    return 0;
}
