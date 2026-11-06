#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string text = "";
    stack<string> undoStack;
    stack<string> redoStack;

    int choice;
    string value;

    do {
        cout << "\n\nCurrent Text: " << text;

        cout << "\n\n1. Type Text";
        cout << "\n2. Delete Last Character";
        cout << "\n3. Undo";
        cout << "\n4. Redo";
        cout << "\n5. Display Text";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text: ";
            cin.ignore();
            getline(cin, value);

            undoStack.push(text);
            text += value;

            while (!redoStack.empty()) {
                redoStack.pop();
            }

            cout << "Text added successfully!";
            break;

        case 2:
            if (text.empty()) {
                cout << "Text is empty!";
                break;
            }

            undoStack.push(text);
            text.pop_back();

            while (!redoStack.empty()) {
                redoStack.pop();
            }

            cout << "Last character deleted!";
            break;

        case 3:
            if (undoStack.empty()) {
                cout << "Nothing to undo!";
                break;
            }

            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();

            cout << "Undo successful!";
            break;

        case 4:
            if (redoStack.empty()) {
                cout << "Nothing to redo!";
                break;
            }

            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();

            cout << "Redo successful!";
            break;

        case 5:
            cout << "Current Text: " << text;
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