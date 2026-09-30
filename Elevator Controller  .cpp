#include <iostream>
using namespace std;

class ElevatorController {
private:
    int currentFloor;

public:
    ElevatorController(int startFloor) {
        currentFloor = startFloor;
    }

    void moveToFloor(int destinationFloor) {

        if (destinationFloor < 1 || destinationFloor > 4) {
            cout << "Invalid floor! Please select 1 to 4." << endl;
            return;
        }

        if (destinationFloor == currentFloor) {
            cout << "Elevator is already at Floor "
                 << currentFloor << "." << endl;
            return;
        }

        cout << "\nElevator Moving..." << endl;

        if (destinationFloor > currentFloor) {
            while (currentFloor < destinationFloor) {
                currentFloor++;
                cout << "Elevator reached Floor "
                     << currentFloor << endl;
            }
        }
        else {
            while (currentFloor > destinationFloor) {
                currentFloor--;
                cout << "Elevator reached Floor "
                     << currentFloor << endl;
            }
        }

        cout << "\nDoor: OPEN" << endl;
        cout << "Elevator stopped at Floor "
             << currentFloor << "." << endl;
    }

    void displayStatus() {
        cout << "\n-----------------------------" << endl;
        cout << "Elevator Current Floor: "
             << currentFloor << endl;
        cout << "Door Status: CLOSED" << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {

    int startFloor;
    int destinationFloor;

    cout << "==================================" << endl;
    cout << "       ELEVATOR CONTROLLER" << endl;
    cout << "==================================" << endl;

    cout << "\nFloors available: 1, 2, 3, 4" << endl;

    cout << "Enter current floor: ";
    cin >> startFloor;

    if (startFloor < 1 || startFloor > 4) {
        cout << "Invalid starting floor!" << endl;
        return 0;
    }

    ElevatorController elevator(startFloor);

    elevator.displayStatus();

    cout << "\nEnter destination floor: ";
    cin >> destinationFloor;

    elevator.moveToFloor(destinationFloor);

    elevator.displayStatus();

    return 0;
}
