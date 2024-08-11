#include <iostream>
#include <queue>
using namespace std;

class StackUsingSingleQueue {
private:
    queue<int> q;

public:
    StackUsingSingleQueue() {}

    void push(int x) {
        int size = q.size();
        q.push(x);
        cout << "Pushed: " << x << "\n";

        // Rotate the queue to make the last inserted element to the front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int popped = q.front();
        q.pop();
        return popped;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    int size() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingSingleQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << "\n";
    cout << "Stack size: " << s.size() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    cout << "Top element: " << s.top() << "\n";
    cout << "Stack size: " << s.size() << "\n";
    cout << "Stack empty or not? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    return 0;
}
