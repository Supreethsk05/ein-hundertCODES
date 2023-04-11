#include <iostream>

using namespace std;

class Queue {
public:
    Queue() {
        front = rear = -1;
    }
    void enqueue(int data) {
        if(rear == MAX_SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if(front == -1) {
            front = rear = 0;
            arr[rear] = data;
            return;
        }
        rear++;
        arr[rear] = data;
    }
    void dequeue() {
        if(front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        if(front == rear) {
            front = rear = -1;
            return;
        }
        front++;
    }
    int peek() {
        if(front == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
private:
    const int MAX_SIZE = 100;
    int arr[100];
    int front, rear;
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.peek() << endl; // Output: 1
    queue.dequeue();
    cout << queue.peek() << endl; // Output: 2
    return 0;
}
