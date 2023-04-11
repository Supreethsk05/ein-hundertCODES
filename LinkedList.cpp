#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }
    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
private:
    Node* head;
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display(); // Output: 3 2 1
    return 0;
}
