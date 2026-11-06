
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string patientName) {
        name = patientName;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    void AddPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << name << " added to the queue." << endl;
    }

    void RemovePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << name << " removed from the queue." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << name << " removed from the queue." << endl;
    }

    void Display() {
        if (head == nullptr) {
            cout << "No patients in the queue." << endl;
            return;
        }

        Node* temp = head;

        cout << "\nPatients Waiting for Consultation:\n";

        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

    void CountPatients() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Patients: " << count << endl;
    }
};

int main() {
    PatientQueue queue;

    queue.AddPatient("Ali");
    queue.AddPatient("Ahmed");
    queue.AddPatient("Sara");
    queue.AddPatient("Ayesha");

    queue.Display();
    queue.CountPatients();

    cout << "\nAfter Cancellation:\n";

    queue.RemovePatient("Ahmed");

    queue.Display();
    queue.CountPatients();

    return 0;
}
