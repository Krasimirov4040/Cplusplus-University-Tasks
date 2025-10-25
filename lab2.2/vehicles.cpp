#include <iostream>
using namespace std;

class Car {
private:
	int passengers;
	int speed;
public:

	Car(int p, int s):
		passengers(p),speed(s)
	{
	}
		friend float TimeTravel(Car c, float distance);

};

class Truck {
private:
	int weight;
	int speed;
public:
	Truck(int w,int s):
	weight(w),speed(s)
	{

	}
	friend float TimeTravel(Truck t, float distance);
};


float TimeTravel(Car c, float distance) {
	float time;

	time = distance / c.speed;
	return time;
}

float TimeTravel(Truck t, float distance) {
	float time;

	time = distance / t.speed;
	return time;
}

int main() {


	Car car1(5, 60);
	Truck truck1(5000, 55);
	float timeCar = TimeTravel(car1, 300);
	float timeTruck = TimeTravel(truck1, 550);

	cout << "The car will travel: " << timeCar << "hours to its destination\n";
	cout << "The truck will travel: " << timeTruck << "hours to its destination\n";
	
	
	return 0;

}