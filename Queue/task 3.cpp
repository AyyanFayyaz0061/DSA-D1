#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseK(queue<int>& q, int k) {
    if (k <= 1 || q.empty()) {
        return;
    }

    int n = q.size();

    if (k > n) {
        k = n;
    }

    stack<int> s;

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        q.push(value);
    }

    cout << "Original Queue: ";
    display(q);

    cout << "Enter K: ";
    cin >> k;

    reverseK(q, k);

    cout << "Reversed Queue: ";
    display(q);

    return 0;
}