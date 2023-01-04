#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;


bool isempty()      //to check if queue is empty or not
{
    if (front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

void enqueue()
{
                                    
    if ((rear + 1) % SIZE == front)     //to check if queue is full it is for both cases when a circular array is created
        cout << "Queue is full \n";
    else
    {
        int value;
        cout << "Enter Value:\n";
        cin >> value;
        if (front == -1) {      //queue is empty here and first element is being inserted here
            front = 0;
        }
                                      //adds element at rear
        rear = (rear + 1) % SIZE;     //this is for adding elements as we know that at least one space will be there
        A[rear] = value;             //to insert element bcoz it has gone pass through upper check of queue capacity
    }
}

void dequeue()
{
    if (isempty()) {
        cout << "Queue is empty\n";
    }
    else {
                                            //only one element present in queue
        if (front == rear) {
            cout << A[front] << " is deleted.\n";
            front = rear = -1;
        }
        else {
            cout << A[front] << " is deleted.\n";
            front = (front + 1) % SIZE;    //this will also del the front value when rear is less than front
        }
            
    }
        
}
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << A[front] << endl;
}

//function to display queue
void displayQueue()
{
    if (isempty()) {
        cout << "Queue is empty\n";
    }
    else{
        int i;
        if (front <= rear)          //this is a case of linear simple queue
        {
            for (i = front; i <= rear; i++)
                cout << A[i] << " ";
        }
        else{   //case of circular queue
            i = front;                           
            while (i < SIZE)
            {
                cout << A[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear) 
            {
                cout << A[i] << " ";
                i++;
            }
        }
    }
}


int main()
{
    int choice, flag = 1;
    while (flag == 1)
    {
        cout << "\n 1.enqueue\n 2.dequeue\n 3.showfront\n 4.displayQueue\n 5.exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: 
            enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: showfront();
            break;
        case 4: displayQueue();
            break;
        case 5: 
            cout << "\nExit"; flag = 0;
            break;
        }
    }

    return 0;
}
