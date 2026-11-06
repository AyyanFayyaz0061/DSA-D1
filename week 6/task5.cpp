
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string studentName;
    string priority;
    int rank;
    Node* next;

    Node(string name, string p, int r) {
        studentName = name;
        priority = p;
        rank = r;
        next = nullptr;
    }
};

class ReservationQueue {
private:
    Node* head;

    int getRank(string priority) {
        if (priority == "Research")
            return 1;
        else if (priority == "Assignment")
            return 2;
        else
            return 3;
    }

public:
    ReservationQueue() {
        head = nullptr;
    }

    void AddStudent(string name, string priority = "Casual") {
        int rank = getRank(priority);
        Node* newNode = new Node(name, priority, rank);

        if (head == nullptr || rank < head->rank) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr &&
                temp->next->rank <= rank) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << name << " added successfully." << endl;
    }

    void RemoveStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        if (head->studentName == name) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << name << " removed successfully." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->studentName != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << name << " removed successfully." << endl;
    }

    void UpdatePriority(string name, string newPriority) {
        if (head == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->studentName != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        RemoveStudent(name);
        AddStudent(name, newPriority);

        cout << "Priority updated for " << name << "." << endl;
    }

    void Display() {
        if (head == nullptr) {
            cout << "No students in reservation list." << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->studentName
                << " (" << temp->priority << ")";

            if (temp->next != nullptr)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void CountStudents() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Students: " << count << endl;
    }

    void BookReturned() {
        if (head == nullptr) {
            cout << "No student waiting for this book." << endl;
            return;
        }

        Node* temp = head;

        cout << "Book issued to: " << temp->studentName << endl;

        head = head->next;
        delete temp;
    }

    ~ReservationQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ReservationQueue book1;
    ReservationQueue book2;

    cout << "===== BOOK 1: C++ Programming =====" << endl;

    book1.AddStudent("Ali", "Casual");
    book1.AddStudent("Ahmed", "Research");
    book1.AddStudent("Sara", "Assignment");

    cout << "\nReservation List:" << endl;
    book1.Display();

    cout << "\nUpdating Priority:" << endl;
    book1.UpdatePriority("Ali", "Research");

    cout << "\nUpdated Reservation List:" << endl;
    book1.Display();

    cout << "\nCancelling Reservation:" << endl;
    book1.RemoveStudent("Sara");

    cout << "\nCurrent Reservation List:" << endl;
    book1.Display();

    cout << "\nReturning Book:" << endl;
    book1.BookReturned();

    book1.CountStudents();

    cout << "\n===== BOOK 2: Data Structures =====" << endl;

    book2.AddStudent("Usman", "Assignment");
    book2.AddStudent("Ayesha", "Casual");
    book2.AddStudent("Hassan", "Research");

    cout << "\nReservation List:" << endl;
    book2.Display();

    cout << "\nUpdating Priority:" << endl;
    book2.UpdatePriority("Ayesha", "Research");

    cout << "\nUpdated Reservation List:" << endl;
    book2.Display();

    cout << "\nReturning Book:" << endl;
    book2.BookReturned();

    cout << "\nFinal Reservation List:" << endl;
    book2.Display();

    book2.CountStudents();

    return 0;
}
