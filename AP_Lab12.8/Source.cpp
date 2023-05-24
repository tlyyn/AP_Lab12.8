#include <iostream>
using namespace std;
const int MAX_NAME_SIZE = 50;


struct BusStop {
    char name[MAX_NAME_SIZE];
    int arrivalTime;
    BusStop* next;
    BusStop* prev;
};

BusStop* createStop(const char* name, int arrivalTime) {
    BusStop* stop = new BusStop;
    for (int i = 0; i < MAX_NAME_SIZE; i++) {
        stop->name[i] = name[i];
        if (name[i] == '\0') {
            break;
        }
    }
    stop->arrivalTime = arrivalTime;
    stop->next = nullptr;
    stop->prev = nullptr;
    return stop;
}

void addStop(BusStop*& first, BusStop*& last, BusStop* newStop) {
    if (first == nullptr) {
        first = newStop;
        last = newStop;
    }
    else {
        last->next = newStop;
        newStop->prev = last;
        last = newStop;
    }
}

bool compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int calculateTime(BusStop* first, BusStop* last, const char* startStop, const char* endStop) {
    BusStop* current = first;
    while (current != nullptr) {
        if (compareStrings(current->name, startStop)) {
            break;
        }
        current = current->next;
    }

    int totalTime = 0;
    while (current != nullptr) {
        totalTime += current->arrivalTime;
        if (compareStrings(current->name, endStop)) {
            break;
        }
        current = current->next;
    }

    return totalTime;
}



int main() {
    BusStop* first = nullptr;
    BusStop* last = nullptr;

    // Додати зупинки до маршруту
    addStop(first, last, createStop("Lviv", 40));
    addStop(first, last, createStop("Bibrka", 35));
    addStop(first, last, createStop("Rogatyn", 35));
    addStop(first, last, createStop("Halych", 35));
    addStop(first, last, createStop("Frankivsk", 30));

    char startStop[MAX_NAME_SIZE];
    char endStop[MAX_NAME_SIZE];

    cout << "Enter the starting bus stop: ";
    cin >> startStop;

    cout << "Enter the destination bus stop: ";
    cin >> endStop;

    int totalTime = calculateTime(first, last, startStop, endStop);
    if (totalTime > 0) {
        cout << "Total time from " << startStop << " to " << endStop << " is " << totalTime << " minutes" << endl;
    }
    else
        cout << "Rout is not found" << endl;
    return 0;
}
