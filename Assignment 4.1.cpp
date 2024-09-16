#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }

    void setHour(int h) {
        hour = h;
    }

    void setMinute(int m) {
        minute = m;
    }

    void setSecond(int s) {
        second = s;
    }

    void printTime() const {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main() {
    int h, m, s;
    Time* timeArray[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter time for object " << i + 1 << " (hours minutes seconds): ";
        cin >> h >> m >> s;
        timeArray[i] = new Time(h, m, s);
    }

    cout << "\nThe times entered are: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Time for object " << i + 1 << ": ";
        timeArray[i]->printTime();
    }

    for (int i = 0; i < 5; i++) {
        delete timeArray[i];
    }

    return 0;
}





