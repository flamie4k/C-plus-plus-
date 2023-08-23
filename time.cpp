#include <iostream>
using namespace std;

class time {
    private:
    int hour;
    int min;
    int sec;
    public: 
    time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    void gettime(){
        cin>>hour>>min>>sec;
}
time add(const time& t2) {
        int totalSec = sec + t2.sec;
        int carryMinutes = totalSec / 60;
        totalSec %= 60;
        int totalMin = min + t2.min + carryMinutes;
        int carryHours = totalMin / 60;
        totalMin %= 60;
        int totalHour = hour + t2.hour + carryHours;
        return time(totalHour, totalMin, totalSec);
    }
        void displayTime() {
        cout << "Time: " << hour << " hours, " << min << " minutes, " << sec << " seconds" << endl;
    }
};
int main() {
    time t1(0, 0, 0);
    time t2(0, 0, 0);
    cout << "Enter data for the first time:" << endl;
    t1.gettime();
    cout << "\nEnter data for the second time:" << endl;
    t2.gettime();
    time result = t1.add(t2);
    cout << "\nFirst Time:" << endl;
    t1.displayTime();
    cout << "\nSecond Time:" << endl;
    t2.displayTime();
    cout << "\nSum of Times:" << endl;
    result.displayTime();
    return 0;
}