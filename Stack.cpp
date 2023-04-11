#include <iostream>

using namespace std;

class Stack {
public:
    Stack() {
        top = -1;
    }
    void push(int data) {
        if(top == MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop() {
        if(top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }
    int peek() {
        if(top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
private:
    const int MAX_SIZE = 100;
    int arr[100];
    int top;
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl; // Output: 3
    stack.pop();
    cout << stack.peek() << endl; // Output: 2
    return 0;
}
