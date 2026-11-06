
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void InsertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void InsertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void Display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.InsertAtBeginning(20);
    list.InsertAtBeginning(10);

    list.InsertAtEnd(30);
    list.InsertAtEnd(40);

    cout << "Linked List: ";
    list.Display();

    list.DeleteNode(20);

    cout << "After Deletion: ";
    list.Display();

    return 0;
}
