#include <iostream>
#include <queue>
using namespace std;

class TicketSystem {
private:
    queue<int> tickets;

public:
    void enqueue(int id) {
        if (id < 1000 || id > 9999) {
            cout << "Enter a valid 4-digit ticket ID!" << endl;
            return;
        }

        tickets.push(id);
        cout << "Ticket added successfully!" << endl;
    }

    void dequeue() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Ticket resolved: " << tickets.front() << endl;
        tickets.pop();
    }

    void front() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Next ticket: " << tickets.front() << endl;
    }

    void display() {
        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        queue<int> temp = tickets;

        cout << "Pending Tickets: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
    TicketSystem t;
    int choice, id;

    do {
        cout << "\n1. Add Ticket";
        cout << "\n2. Resolve Ticket";
        cout << "\n3. Next Ticket";
        cout << "\n4. Display Tickets";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> id;
            t.enqueue(id);
            break;

        case 2:
            t.dequeue();
            break;

        case 3:
            t.front();
            break;

        case 4:
            t.display();
            break;

        case 5:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}