#include <iostream>
using namespace std;
class Point
{
private:
	float x, y;
	string name;
public:
	Point(float x = 0, float y = 0, string name = "") :
		x(x), y(y), name(name) {
	}
	float vector_len() {
		return sqrt(x * x + y * y);
	}
	float vector_len(Point o) {
		return sqrt((x - o.x) * (x - o.x)
			+ (y - o.y) * (y - o.y));
	}
};

//Има четири точки(Point)
//Има конструктор, който получава всички координати като параметри(може и като 4 points)
//Има функция за пресмятане на обиколката на четириъгълника,
//използвайки функциите за дължина на вектор.

class Quad {
private:
	Point p1, p2, p3, p4;

public:
	Quad(Point p1, Point p2, Point p3, Point p4) :
		p1(p1), p2(p2), p3(p3), p4(p4) {

	}



};

int main()
{
	Point a(4, 3, "A"), b(3, 3, "B");
	cout << "len (OA) = " << a.vector_len() << endl;
	return 0;
}

