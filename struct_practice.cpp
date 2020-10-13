#include <iostream>
#include <string>

using namespace std;

struct timeStamp {
    string amPM;
    int hour;
    int minute;
    int second;
};

// Function to check what time is in other timezones
// pass by value
void timeInCanadaEast(timeStamp time){
    timeStamp est = time;
    est.hour = time.hour - 5;
    if (est.hour <= 0){
        if ((est.hour == 0 && time.minute == 0 && time.second == 0) || (est.hour < 0)){
            if (time.amPM == "AM"){
                est.amPM = "PM";
            } else {
                est.amPM = "AM";
            }
       } 
        if (est.hour == 0){
            est.hour = 12;
        } else {
            est.hour = 12 + est.hour;
        }
    }
    cout << est.hour << ", " << est.minute << ", " << est.second << ", " << est.amPM << ".";
}

// Function to change the summer time to winter time
// pass by reference
void endSummerTime(timeStamp& time){
    time.hour = time.hour + 1;
    cout << time.hour << ", " << time.minute << ", " << time.second << ", " << time.amPM << ".";
} 

int main(){
    timeStamp currentTime = {"PM", 3, 48, 54};
    cout << "currentTime before function timeInCanadaEast: " << currentTime.hour << ", " << currentTime.minute << ", " << currentTime.second << ", " << currentTime.amPM << "." << endl;
    cout << "Time in Canada East: " << endl;
    timeInCanadaEast(currentTime);
    cout << "\n" << "currentTime after function timeInCanadaEast: " << currentTime.hour << ", " << currentTime.minute << ", " << currentTime.second << ", " << currentTime.amPM << "." << endl;
    cout << "currentTime before function endSummerTime: " << currentTime.hour << ", " << currentTime.minute << ", " << currentTime.second << ", " << currentTime.amPM << "." << endl;
    cout << "New time: " << endl;
    endSummerTime(currentTime);
    cout << "\n" << "currentTime after function endSummerTime: " << currentTime.hour << ", " << currentTime.minute << ", " << currentTime.second << ", " << currentTime.amPM << "." << endl;
    return 0;
}
