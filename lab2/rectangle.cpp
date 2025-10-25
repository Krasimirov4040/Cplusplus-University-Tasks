#include <iostream>
using namespace std;


class Rectangle {
private:
	float a;
	float b;

public:

	Rectangle(float a, float b):
	a(a),b(b)
	{
		cout << "rectangle created!\n";
	}

	void face() {
		cout << "The area of this Recatngle is :" << a * b << "sq cm \n";
	}

	void face(float a,float b,float sumOfSides){
		cout << "The area of this Recatngle is :" << a * b << "sq cm \n";
		cout << "The parameter of this rectangle is : " << sumOfSides * 2 << "cm \n";
	}

	~Rectangle() {
		cout << "Rectangle object destructed! " << endl;
	}

};


int main() {
	Rectangle r1(4, 5);

	Rectangle r2(7, 8);

	r1.face();
	r1.face(4, 5, 9);

	r2.face();
	r1.face(7, 8, 15);


	return 0;
}