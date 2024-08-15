#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> s; // Stack to store elements
    int mini;     // Variable to store the minimum element

public:
    /** Initialize your data structure here. */
    MinStack() {
        while (!s.empty()) s.pop(); // Ensure the stack is empty
        mini = INT_MAX;             // Set the initial minimum to the maximum integer value
    }
    /** Push element x onto the stack. */
    void push(int value) {
        if (s.empty()) {
            mini = value;       // Set mini to the new value if stack is empty
            s.push(value);      // Push the new value onto the stack
        } else {
            if (value < mini) {
                s.push(2 * value - mini); // Push modified value to track previous minimum
                mini = value;             // Update mini to the new value
            } else {
                s.push(value);  // Push the new value onto the stack
            }
        }
    }

    /** Removes the element on top of the stack. */
    void pop() {
        if (s.empty()) return;
        int topElement = s.top();
        s.pop();

        if (topElement < mini) {
            mini = 2 * mini - topElement; // Retrieve the previous minimum value
        }
    }

    /** Get the top element. */
    int top() {
        if (s.empty()) return -1;
        int topElement = s.top();
        return (topElement < mini) ? mini : topElement; // Return mini if topElement is modified value
    }

    /** Retrieve the minimum element in the stack. */
    int getMin() {
        return mini;
    }
};
