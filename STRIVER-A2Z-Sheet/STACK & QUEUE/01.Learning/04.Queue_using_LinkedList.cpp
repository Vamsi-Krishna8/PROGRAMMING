#include <iostream>
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(int x) {
        QueueNode* newNode = new QueueNode(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued: " << x << "\n";
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        int data = front->data;
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void printQueue() {
        QueueNode* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue: ";
    q.printQueue();
    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Queue size: " << q.getSize() << "\n";
    cout << "Queue empty or not? " << (q.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Queue's front element: " << q.peek() << "\n";
    return 0;
}
