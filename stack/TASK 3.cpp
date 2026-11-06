#include <iostream>
#include <stack>
using namespace std;

class myCarStack {
private:
    stack<int> cars;
    int size;

public:
    myCarStack() {
        size = 8;
    }

    void parkCar(int car) {
        if (cars.size() == size) {
            cout << "Parking is full!" << endl;
            return;
        }

        cars.push(car);
        cout << "Car parked successfully!" << endl;
    }

    void removeCar(int car) {
        if (cars.empty()) {
            cout << "Parking is empty!" << endl;
            return;
        }

        stack<int> temp;
        bool found = false;

        while (!cars.empty()) {
            if (cars.top() == car) {
                cars.pop();
                found = true;
                break;
            }

            temp.push(cars.top());
            cars.pop();
        }

        while (!temp.empty()) {
            cars.push(temp.top());
            temp.pop();
        }

        if (found) {
            cout << "Car removed successfully!" << endl;
        }
        else {
            cout << "Car not found!" << endl;
        }
    }

    void searchCar(int car) {
        stack<int> temp = cars;
        bool found = false;

        while (!temp.empty()) {
            if (temp.top() == car) {
                found = true;
                break;
            }
            temp.pop();
        }

        if (found) {
            cout << "Car is present in parking!" << endl;
        }
        else {
            cout << "Car not found!" << endl;
        }
    }

    void display() {
        if (cars.empty()) {
            cout << "Parking is empty!" << endl;
            return;
        }

        stack<int> temp = cars;

        cout << "Parked Cars:" << endl;

        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
    }

    void totalCars() {
        cout << "Total parked cars: " << cars.size() << endl;
    }

    void showTop() {
        if (cars.empty()) {
            cout << "Parking is empty!" << endl;
            return;
        }

        cout << "Last parked car: " << cars.top() << endl;
    }
};

int main() {
    myCarStack p;
    int choice, car;

    do {
        cout << "\n1. Park a car";
        cout << "\n2. Remove a car";
        cout << "\n3. Search a car";
        cout << "\n4. Display parked cars";
        cout << "\n5. Total cars";
        cout << "\n6. Show last parked car";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            p.parkCar(car);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> car;
            p.removeCar(car);
            break;

        case 3:
            cout << "Enter car number to search: ";
            cin >> car;
            p.searchCar(car);
            break;

        case 4:
            p.display();
            break;

        case 5:
            p.totalCars();
            break;

        case 6:
            p.showTop();
            break;

        case 7:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}