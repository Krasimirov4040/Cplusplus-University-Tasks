#include <iostream>

using namespace std;


class Stack {
private:
	int top;
	char arr [25];

public:
	Stack() { top = -1; }

	void loadStack() {
		char a=97;
		for (int i = 0; i < 26; i++) {
			arr[i] = a + i;
		}
	}

	void loadStack(int upper) {
		if (upper != 1) {
			loadStack();
		}
		else {
			char a = 65;
			for (int i = 0; i < 26; i++) {
				arr[i] = a + i;
			}
		}
	}
	
	void print() {
		for (int i = 0; i < 26; i++) {
			cout << "Letter from the stack: " << arr[i] << endl;
		}
	}
};

int main() {
	Stack s;
	s.loadStack();
	s.print();

	Stack s1;
	s1.loadStack(1);
	s1.print();

	return 0;
}