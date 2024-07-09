#pragma once
#include <iostream>
using namespace std;
class clsClock {
public:
    int _Hour;
    int _Minute;
    int _Second;

    clsClock(int hour, int minute, int second) : _Hour(hour), _Minute(minute), _Second(second) {}

    static string clockToString(clsClock clock, string dilm = ":") {
    string timeString = "";
    timeString = (clock._Hour < 10 ? "0" : "") + to_string(clock._Hour) + dilm;
    timeString += (clock._Minute < 10 ? "0" : "") + to_string(clock._Minute) + dilm;
    timeString += (clock._Second < 10 ? "0" : "") + to_string(clock._Second);
    return timeString;
}

static clsClock getSystemTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    return clsClock(localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

};

