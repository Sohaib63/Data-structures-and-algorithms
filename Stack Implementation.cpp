#include <iostream>
using namespace std;
 
#define MAX 100
 
class Stack {
    int top;
 	int a[MAX]; 
public:
    Stack() { top = -1; }
    ~Stack(){}
    void push(int x);
    void pop();
    void peek();
    bool isEmpty();
    void print();
};
 
void Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
    }
}
 
void Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
    }
    else {
        int x = a[top];
        a[top]=0;
        top=top-1;
        cout <<x<< " Popped from stack\n";
    }
}
void Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
    }
    else {
        int x = a[top];
        cout<<endl<<x;
    }
}
 
bool Stack::isEmpty()
{
	if (top<0)
	return true;
	else
	return false;
}
void Stack::print(){
	for(int i=0;i<=top;i++){
 		cout<<a[i]<<endl;
	 }
}

int main()
{
    Stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.pop();
 	obj.push(4);
 	obj.print();
    return 0;
}

