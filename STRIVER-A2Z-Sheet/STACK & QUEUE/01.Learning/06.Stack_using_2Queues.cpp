#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1; // Main queue for stack operations
    queue<int> q2; // Auxiliary queue for transferring elements

public:
    /** Initialize the stack. */
    StackUsingQueues() {}

    /** Push element x onto the stack. */
    void push(int x) {
        // Enqueue the new element to q1
        q1.push(x);
        cout << "Pushed: " << x << endl;

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    /** Removes the element on the top of the stack and returns that element. */
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    /** Get the number of elements in the stack. */
    int size() {
        return q1.size();
    }

    /** Check if the stack is empty. */
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Size of the stack: " << s.size() << endl;
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
