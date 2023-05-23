#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10
 

template <class Tp> class Stack
{
    Tp *arr;
    Tp top;
    int capacity;
 
public:
    Stack(int size = SIZE);         
    ~Stack();                       
 
    void push(Tp);
    void show();
    Tp pop();
    Tp peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 
template <class Tp> Stack <Tp>::Stack(int size)
{
    arr = new Tp[size];
    capacity = size;
    top = -1;
}
 
template <class Tp> Stack <Tp>::~Stack() {
    delete[] arr;
}
 

template <class Tp> void Stack <Tp>::push(Tp x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

template <class Tp> void Stack <Tp>::show(){
    cout << "top is" << this->top << endl;
    cout << "Stack elements:";
    for (auto i=0;i<=this->size()-1;i++){
        cout << arr[top-i] << ",";
    } 
    cout << endl;
}
 

template <class Tp> Tp Stack <Tp>::pop()
{
   
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 

    return arr[top--];
}
 

template <class Tp> Tp Stack <Tp>::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 

template <class Tp> int Stack <Tp>::size() {
    return top + 1;
}
 

template <class Tp> bool Stack <Tp>::isEmpty() {
    return top == -1;               
}
 

template <class Tp> bool Stack <Tp>::isFull() {
    return top == capacity - 1;   
}

int main(){
    Stack <char> pt(3);
 
    pt.push('i');
    pt.push('e');
 
    pt.pop();
    pt.pop();
 
    pt.push('v');
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
    pt.show();
    pt.pop();
 
    if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
    
    Stack<int> stc(6);

    stc.push(1);
    stc.push(6);
    stc.push(10);

    stc.show();

    stc.pop();

    stc.show();

    cout << "The top element is " << stc.peek() << endl;
    cout << "The stack size is " << stc.size() << endl;
    return 0;
}