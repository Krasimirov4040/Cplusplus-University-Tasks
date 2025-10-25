#include <iostream>
using namespace std;

class Time {

private:
	int hours;
	int minutes;
	int seconds;
	bool valid = 1;

public:

	Time(int h = 0, int m = 0, int s = 0) :
		hours(h % 24), minutes(m % 60), seconds(s % 60)
	{

	}
	void setTime(int h,int m,int s) {
		if (h < 0 || m < 0 || s < 0||h>23||m>59||s>59) {
			cout << "Invalid time input" << endl;
			valid = 0;
			return;
		}
		hours = h%24;
		minutes = m%60;
		seconds = s%60;

	}

	void printTime() {

		if (valid) {

		cout << "The time is : " << hours << ":" << minutes << ":" << seconds<<endl;
		if (hours > 12) {
		cout << "The time is : " << hours%12 << ":" << minutes << ":" << seconds<<" PM";
		}
		else {
			cout << "The time is : " << hours % 12 << ":" << minutes << ":" << seconds << " AM";
		}
		}

		
	}


};



int main() {

	Time time;
	int h, m, s;
	cout << "What time is it? : \n";
	cin >> h;
	cin >> m;
	cin >> s;
	time.setTime(h,m,s);
	time.printTime();



	return 0;
}