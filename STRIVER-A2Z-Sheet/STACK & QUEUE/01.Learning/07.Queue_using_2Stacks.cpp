#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; // Main stack to hold elements for enqueue and dequeue operations
    stack<int> s2; // Temporary stack to assist in transferring elements

public:
    /** Initialize the queue. */
    QueueUsingStacks() {}

    /** Add an element to the end of the queue. */
    void enqueue(int x) {
        // Transfer all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element onto s1
        s1.push(x);
        cout << "Enqueued: " << x << endl;

        // Transfer all elements back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Remove the element from the front of the queue and return it. */
    int dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int frontElement = s1.top();
        s1.pop();
        return frontElement;
    }

    /** Get the front element of the queue. */
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    /** Get the number of elements in the queue. */
    int size() {
        return s1.size();
    }

    /** Check if the queue is empty. */
    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(3);
    q.enqueue(4);
    cout << "Dequeued: " << q.dequeue() << endl;
    q.enqueue(5);
    cout << "Front of the queue: " << q.front() << endl;
    cout << "Size of the queue: " << q.size() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
