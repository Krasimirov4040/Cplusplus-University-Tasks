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
	void print() { cout << name << ": (" << x << ", " << y << ") "; }
	float getX() { return x; }
	float getY() { return y; }
	friend ostream& operator<<(ostream& os, Point& p);
	void setX(float x1) {
		x = x1;
	}
	void setY(float y1) {
		y = y1;
	}
	
};
	ostream& operator<<(ostream& os, Point& p) {
		os << p.name << ": (" << p.x << "," << p.y <<")"<< endl;
		return os;
	}

class Quad {
private:
	Point p1, p2, p3, p4;

public:
	Quad(Point p1, Point p2, Point p3, Point p4) :
		p1(p1), p2(p2), p3(p3), p4(p4) {}

	double perimeter() {

		double AB = p1.vector_len(p2);
		double BC = p2.vector_len(p3);
		double CD = p3.vector_len(p4);
		double DA = p4.vector_len(p1);

		return AB + BC + CD + DA;
	}
	friend istream& operator>>(istream& is, Quad& q);
	friend ostream& operator<<(ostream& os, Quad& q);
//3
	
//3.3
//Да се предефинира оператор ++obj, инкрементира всички на фигурата x - координати с 1.
void operator++() {  
	p1.setX(p1.getX() + 1);
	p2.setX(p2.getX() + 1);
	p3.setX(p3.getX() + 1);
	p4.setX(p4.getX()+1);
}
//3.4
//Да се предефинира оператор obj++, инкрементира всички на фигурата y - координати с 1.
void operator++(int) {
	p1.setY(p1.getY() + 1);
	p2.setY(p2.getY() + 1);
	p3.setY(p3.getY() + 1);
	p4.setY(p4.getY() + 1);
}

};

//3.5
//Да се предефинира оператор << за извеждане на координатите на четириъгълник в изходен поток.
ostream& operator<<(ostream& os,Quad& q) {
	os << q.p1 << q.p2 << q.p3 << q.p4 << endl;
	return os;
}

//3.1
//Да се предефинира оператор > за клас Четириъгълник, като сравнява обиколките на два четириъгълника.
bool operator>(Quad q1, Quad q2) {
	if (q1.perimeter() > q2.perimeter())
		cout << "Q1 is bigger\n";
		return 0;
	if (q1.perimeter() < q2.perimeter())
		cout << "Q2 is bigger\n";
		return 1;
}

//3.2
//Да се предефинира оператор >> за прочитане на координатите на четириъгълник от входен поток(без cout prompt).

istream& operator>>(istream& is, Point& p) {
	string name;
	float x, y;
	if (is >> name >> x >> y)
		p = Point( x, y,name);
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
int main()
{
	Point a(4, 3, "A"), b(3, 3, "B"), c(5, 7, "C"), d(8, 9, "D");
	Quad q1(a, b, c, d);
	cout << q1;
	q1++;
	cout << q1;
	++q1;
	cout << q1;
	
	return 0;
}

