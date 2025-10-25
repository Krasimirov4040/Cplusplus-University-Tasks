#include <iostream>
#include <cmath>  // За sqrt
using namespace std;

class Point {
private:
    float x, y;
    string name;
public:
    Point(float x = 0, float y = 0, string name = "") : x(x), y(y), name(name) {}
    float vector_len() {
        return sqrt(x * x + y * y);
    }
    float vector_len(Point o) {
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }
    void print() { cout << name << ": (" << x << ", " << y << ") "; }
    float getX() const { return x; }  // Getter за x
    float getY() const { return y; }  // Getter за y
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
        : p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y), p4(p4x, p4y) {
    }
    float perimeter() {
        float p1p2 = p1.vector_len(p2);
        float p2p3 = p2.vector_len(p3);
        float p3p4 = p3.vector_len(p4);
        float p4p1 = p4.vector_len(p1);
        return p1p2 + p2p3 + p3p4 + p4p1;
    }
};

int main() {
    Point a(4, 3, "A"), b(3, 3, "B"),c(4,5,"C"),d(6, 7, "D");;
    Quad q1(a, b, c, d);

    return 0;
}