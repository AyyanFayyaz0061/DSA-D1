#include <iostream>
#include <stack>
using namespace std;

class myQueue {
private:
    stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(int value) {
        s1.push(value);
        cout << "Element added!" << endl;
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (s2.empty()) {
            transfer();
        }

        cout << "Removed: " << s2.top() << endl;
        s2.pop();
    }

    void front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (s2.empty()) {
            transfer();
        }

        cout << "Front element: " << s2.top() << endl;
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        stack<int> temp = s2;
        stack<int> temp2;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        temp2 = s1;

        while (!temp2.empty()) {
            temp.push(temp2.top());
            temp2.pop();
        }

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
    myQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
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