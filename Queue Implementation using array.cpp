/*Drawbacks of Implementing the Queue using Array
Memory wastage
The space of array, which is used to store queue elements, can never be reused to store the elements of that queue because elements  
can only be inserted at front end and the value of front might be so high so that, all the space before that, can never be filled.
One disadvantage is the limited space. The queue will only hold as many or even lesser elements as the array’s size is fixed. 
Unfilled space will not be utilized as the front pointer of the queue would have moved ahead.
The best way to implement a queue is by using a linked list. It 
will allow insertion of as many elements as needed without any performance loss.
*/

#include <iostream>
using namespace std;
int queue[10], n = 10, front = -1, rear = -1;
void qinser() {
    int val;
    if (rear == n - 1)                  //Bcz array size is now full
        cout << "Queue Overflow" << endl;
    else {
        if (front == -1) {
            front = 0;
        }
        cout << "Enter the number to be added  ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}
void qdelete() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow \n";
    }
    else {
        cout << "The number to be deleted is " << queue[front] << endl;
        front++;
    }
}
void qdisplay() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "The queue is ";
        for (int i = front; i <= rear; i++) {  
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int ch;

    do {
        cout << "Enter the operation to be performed :" << endl;
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cin >> ch;
        if (ch == 1) {
            qinser();
        }
        else if (ch == 2) {
            qdelete();
        }
        else if (ch == 3) {
            qdisplay();
        }
        else if (ch == 4) {
            cout << "Exit" << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    return 0;
}

