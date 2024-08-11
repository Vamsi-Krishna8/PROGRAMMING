#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        StackNode* element = new StackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed: " << x << "\n";
        size++;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        int topData = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    void printStack() {
        StackNode* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.getSize() << "\n";
    cout << "Stack empty or not? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack's top element: " << s.peek() << "\n";
    return 0;
}
