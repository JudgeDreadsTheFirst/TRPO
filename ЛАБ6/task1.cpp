#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>


template <typename T>
struct Node
{
    T data;
    std::shared_ptr<Node> next;
    Node(T d, std::shared_ptr<Node> n) : data(d), next(n) {}
};


template <typename T>
class Stack {
private:
    std::shared_ptr<Node<T>> head;
public:
    Stack() : head(NULL) {}
    Stack(const Stack<T> &rhs) = delete;
    Stack& operator=(const Stack<T> &rhs) = delete;
    void push(const T&);
    void pop();
    T top() const;
    void print() const;
};


template <typename T>
void Stack<T>::push(const T &data) {
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(data,nullptr);
    if (head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

template <typename T>
void Stack<T>::pop() {
    head = head->next;
}

template <typename T>
T Stack<T>::top() const {
    return head->data;
}

template <typename T>
void Stack<T>::print() const {

    for (auto temp = head; temp != nullptr; temp = temp->next)
        std::cout << temp->data << std::endl;
}

int main()
{
    std::cout << "String data" << std::endl;
    {
        Stack<std::string> strStack;
        strStack.push("Test1");
        strStack.push("Test2");
        strStack.push("Test3");
        strStack.print();
        strStack.pop();
        strStack.print();
    }
    std::cout << "Integer data" << std::endl;
    {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.print();
        intStack.pop();
        intStack.print();
    }
    return 0;
}