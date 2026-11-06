#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliverySystem {
private:
    queue<Package> packages;

public:
    void enqueue(int id, string address, int start, int end) {
        if (start > end) {
            cout << "Invalid time window!" << endl;
            return;
        }

        Package p;
        p.id = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;

        packages.push(p);

        cout << "Package added successfully!" << endl;
    }

    void dequeue() {
        if (packages.empty()) {
            cout << "No packages available!" << endl;
            return;
        }

        cout << "Package delivered: " << packages.front().id << endl;
        packages.pop();
    }

    void front() {
        if (packages.empty()) {
            cout << "No packages available!" << endl;
            return;
        }

        Package p = packages.front();

        cout << "\nPackage ID: " << p.id;
        cout << "\nAddress: " << p.address;
        cout << "\nStart Time: " << p.startTime;
        cout << "\nEnd Time: " << p.endTime << endl;
    }

    void display() {
        if (packages.empty()) {
            cout << "No pending packages!" << endl;
            return;
        }

        queue<Package> temp = packages;

        while (!temp.empty()) {
            Package p = temp.front();

            cout << "\nPackage ID: " << p.id;
            cout << "\nAddress: " << p.address;
            cout << "\nTime Window: " << p.startTime
                << " - " << p.endTime << endl;

            temp.pop();
        }
    }

    void timeToDeliver(int currentTime) {
        while (!packages.empty()) {
            Package p = packages.front();

            if (currentTime > p.endTime) {
                cout << "Package expired: " << p.id << endl;
                packages.pop();
            }
            else if (currentTime >= p.startTime) {
                cout << "Package can be delivered: " << p.id << endl;
                break;
            }
            else {
                cout << "Package is not ready for delivery yet!" << endl;
                break;
            }
        }

        if (packages.empty()) {
            cout << "No packages remaining!" << endl;
        }
    }
};

int main() {
    DeliverySystem d;
    int choice, id, start, end, currentTime;
    string address;

    do {
        cout << "\n1. Add Package";
        cout << "\n2. Deliver Package";
        cout << "\n3. View Next Package";
        cout << "\n4. Display All Packages";
        cout << "\n5. Check Delivery Time";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Package ID: ";
            cin >> id;

            cin.ignore();
            cout << "Enter Address: ";
            getline(cin, address);

            cout << "Enter Start Time: ";
            cin >> start;

            cout << "Enter End Time: ";
            cin >> end;

            d.enqueue(id, address, start, end);
            break;

        case 2:
            d.dequeue();
            break;

        case 3:
            d.front();
            break;

        case 4:
            d.display();
            break;

        case 5:
            cout << "Enter Current Time: ";
            cin >> currentTime;
            d.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}