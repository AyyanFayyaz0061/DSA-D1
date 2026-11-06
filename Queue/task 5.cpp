#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PrintQueue {
private:
    queue<string> documents;

public:
    void enqueue(string name) {
        documents.push(name);
        cout << "Print job added successfully!" << endl;
    }

    void dequeue() {
        if (documents.empty()) {
            cout << "No documents to print!" << endl;
            return;
        }

        cout << "Printing document: " << documents.front() << endl;
        documents.pop();
    }

    void front() {
        if (documents.empty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }

        cout << "Next document: " << documents.front() << endl;
    }

    void display() {
        if (documents.empty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }

        queue<string> temp = documents;

        cout << "Pending Documents:" << endl;

        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {
    PrintQueue p;
    int choice;
    string name;

    do {
        cout << "\n1. Add Print Job";
        cout << "\n2. Print Document";
        cout << "\n3. Next Document";
        cout << "\n4. Display Documents";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin.ignore();
            getline(cin, name);
            p.enqueue(name);
            break;

        case 2:
            p.dequeue();
            break;

        case 3:
            p.front();
            break;

        case 4:
            p.display();
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