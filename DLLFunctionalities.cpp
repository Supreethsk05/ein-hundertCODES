#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedList() {
        this->head = NULL;
    }
    ~DoublyLinkedList() {
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
        if(head == NULL) {
            head = newNode;
            return;
        }
        head->prev = newNode;
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
        newNode->prev = current;
    }
    void insertAt(int index, int data) {
        if(index < 0) {
            return;
        }
        if(index == 0) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
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
        newNode->prev = current;
        if(current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
    void deleteAtBeginning() {
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
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
        while(current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
        delete current;
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
        while(current != NULL && i < index) {
            current = current->next;
            i++;
        }
        if(current == NULL) {
            return;
        }
        current->prev->next = current->next;
        if(current->next != NULL) {
            current->next->prev = current->prev;
        }
        delete current;
    }
    void reverse() {
        Node* current = head;
        Node* temp = NULL;
        while(current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if(temp != NULL) {
            head = temp->prev;
        }
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
    DoublyLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAt(1, 3);
    list.printList(); // Output: 1 3 2
    list.deleteAt(1);
    list.reverse();
    list.printList(); // Output: 2 1
    return 0;
}
