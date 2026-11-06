
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

    void Insert(int value, int position) {
        Node* newNode = new Node(value);

        if (position < 1) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Delete(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        Node* temp = head;

        if (position == 1) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void Search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position " << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found!" << endl;
    }

    void Count() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total nodes: " << count << endl;
    }

    void Display() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, position;

    do {
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Search Element";
        cout << "\n4. Count Nodes";
        cout << "\n5. Display List";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.Insert(value, position);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> position;

            list.Delete(position);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            list.Search(value);
            break;

        case 4:
            list.Count();
            break;

        case 5:
            list.Display();
            break;

        case 6:
            cout << "Program ended!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
