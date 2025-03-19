#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second;

public:
    // Default constructor
    Time() : hour(0), minute(0), second(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Getters
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSeconds() { return second; }

    // Setters
    void setHour(int h) { hour = (h >= 0 && h < 24) ? h : 0; }
    void setMinute(int m) { minute = (m >= 0 && m < 60) ? m : 0; }
    void setSeconds(int s) { second = (s >= 0 && s < 60) ? s : 0; }

    // Display time in HH:MM:SS format
    void printTime() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main() {
    int size;

    // Asking user for the number of time objects
    cout << "Enter the number of Time objects: ";
    cin >> size;

    // Dynamically allocate memory for the array of Time objects
    Time* timeArray = new Time[size];

    // Taking input for each Time object
    for (int i = 0; i < size; i++) {
        int h, m, s;
        cout << "Enter time (HH MM SS) for object " << i + 1 << ": ";
        cin >> h >> m >> s;
        timeArray[i] = Time(h, m, s); // Using parameterized constructor
    }

    // Displaying all Time objects
    cout << "\nStored Time values:\n";
    for (int i = 0; i < size; i++) {
        cout << "Time " << i + 1 << ": ";
        timeArray[i].printTime();
    }

    // Free the allocated memory
    delete[] timeArray;

    return 0;
}
