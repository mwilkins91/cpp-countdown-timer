#include <iostream>
#include <chrono>
#include <stdio.h>

using namespace std::chrono;
using namespace std;

long long getNow() {
    return std::time(0);
}

int getDesiredSeconds() {
    int desiredSeconds;

    cout << "Please enter timer duration (in seconds): ";
    cin >> desiredSeconds;
    
    return desiredSeconds;
}

string spacePadding(long long seconds) {
    string secondsString = to_string(seconds);
    string padding = "";
    size_t paddingNeeded = 10 - secondsString.length();
    
    for(size_t i = 0; i < paddingNeeded; i++) {
        padding = padding + " ";
    };
    return padding;
}

int main() {
    int desiredSeconds = getDesiredSeconds();
    long long now = getNow();
    long long targetTime = now + desiredSeconds;
    long long currentTime = now;
    long long lastDisplayedTime = 0;

    while((targetTime - currentTime) > 0) {
       currentTime = getNow();
       long long currentDisplayTime = (targetTime - currentTime);

       if (currentDisplayTime == lastDisplayedTime) {
           continue;
       }
        
        lastDisplayedTime = currentDisplayTime;
        string padding = spacePadding(currentDisplayTime);
        cout << "  Time remaining: " << (to_string(currentDisplayTime) + padding) << "\r"; 
        fflush(stdout);
    }

    cout << endl << "****** Done!!! ******" << endl;
}