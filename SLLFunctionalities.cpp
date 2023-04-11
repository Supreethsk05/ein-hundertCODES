#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    LinkedList() {
        this->head = NULL;
    }
    ~LinkedList() {
        Node* current = head;
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
    }
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    void insertAt(int index, int data) {
        if(index < 0) {
            return;
        }
        Node* newNode = new Node(data);
        if(index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        int i = 0;
        while(current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if(current == NULL) {
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void deleteAtBeginning() {
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd() {
        if(head == NULL) {
            return;
        }
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while(current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }
    void deleteAt(int index) {
        if(index < 0) {
            return;
        }
        if(index == 0) {
            deleteAtBeginning();
            return;
        }
        Node* current = head;
        int i = 0;
        while(current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if(current == NULL || current->next == NULL) {
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void printList() {
        Node* current = head;
        while(current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
private:
    Node* head;
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(0);
    list.insertAt(3, 4);
    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAt(1);
    list.printList(); // Output: 1 3
    list.reverse();
    list.printList(); // Output: 3 1
    return 0;
}
