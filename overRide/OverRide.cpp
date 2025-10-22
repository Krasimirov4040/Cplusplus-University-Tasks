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
	Point operator+(Point b) {
		return Point(x + b.x, y + b.y, name + b.name);
	}
	Point operator+(float x) {
		return Point(this->x + x, this->y, name);
	}
	bool operator==(Point b) {
		return (x == b.x) && (y == b.y);
	}
	float operator[](int index) {
		if (index == 0)
			return x;
		if (index == 1)
			return y;
		else
			return 0;
	}

	friend ostream& operator<< (ostream& os, Point& a);
	friend istream& operator>>(istream& is, Point& p);
	friend ostream& operator<< (ostream& os, const Point& a); // добре е да промениш и това на const ref


};

class Quad {
private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
public:
	Quad(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {}


	Quad(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y)
		: p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y), p4(p4x, p4y) {}
	
	float perimeter() {
		float p1p2 = p1.vector_len(p2);
		float p2p3 = p2.vector_len(p3);
		float p3p4 = p3.vector_len(p4);
		float p4p1 = p4.vector_len(p1);
		return p1p2 + p2p3 + p3p4 + p4p1;
	}
	friend void operator>(Quad q1, Quad q2);
	friend istream& operator>>(istream& is, Point& p);
	friend ostream& operator<< (ostream& os, const Point& a); // добре е да промениш и това на const ref

};


ostream& operator<< (ostream& os, Point& a)
{
	os << a.name << " : (" << a.x << ", " << a.y << ") ";
	return os;
}

//Да се предефинира оператор > за клас Четириъгълник, като сравнява обиколките на два четириъгълника.

void operator>(Quad q1, Quad q2) {

	if (q1.perimeter() > q2.perimeter()) {
		cout << "Q1 has a bigger perimeter!!!" << endl;
	}
	else if (q2.perimeter() > q1.perimeter()) {
		cout << "Q2 has a bigger perimeter!!!" << endl;
	}
	else {
		cout << "Both Q1 and Q2 have equal perimeters!!!" << endl;
	}
}

//Да се предефинира оператор >> за прочитане на координатите на четириъгълник от входен поток(без cout prompt).

// Чете: name x y
istream& operator>>(istream& is, Point& p) {
	string name;
	float x, y;
	if (is >> name >> x >> y) {
		p = Point(x, y, name);
	}
	return is;
}

// След това Quad::operator>> може да използва operator>> за Point
istream& operator>>(istream& is, Quad& q) {
	Point p1, p2, p3, p4;
	if (is >> p1 >> p2 >> p3 >> p4) {
		q.p1 = p1;
		q.p2 = p2;
		q.p3 = p3;
		q.p4 = p4;
	}
	return is;
}

istream& operator>>(istream& is, Quad& q) {

}


int main()
{
	/*Point a(4, 3, "A"), b(3, 3, "B"), c(4, 5, "C"), d(6, 7, "D");
	Quad q2(a, b, c, d);

	Point k(2, 2, "K"), l(7, 2, "L"), m(7, 6, "M"), n(2, 6, "N");
	Quad q1(k, l, m, n);*/


	return 0;
}
