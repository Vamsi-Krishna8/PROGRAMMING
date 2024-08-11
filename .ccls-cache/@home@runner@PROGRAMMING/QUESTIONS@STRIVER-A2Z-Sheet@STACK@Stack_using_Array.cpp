
#include <bits/stdc++.h>
using namespace std;
class Stack {
    int size;
    int *arr;
    int top;

    void resize() {
        size *= 2;
        int* newArr = new int[size];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    Stack() {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    void push(int x) {
        if (top + 1 == size) {
            resize();
        }
        top++;
        arr[top] = x;
    }
    int pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }
    int Top() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    int Size() {
        return top + 1;
    }
};
int main() {
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}