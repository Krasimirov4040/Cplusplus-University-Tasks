#include <iostream>
using namespace std;

class Line {
private:
	int len;

public:
	Line(int len):
	len(len)
	{
		for (int i = 0; i < len; i++) {
			cout << "*";
		}
		cout << endl;

	}
	~Line() {
		cout << "Destructor called for line "<<len<<"!!!" << endl;

	}

};

int main() {

	Line l1(7);
	Line l2(16);

	return 0;
}