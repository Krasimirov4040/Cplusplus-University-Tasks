#include <iostream>
using namespace std;

//В кода добавете функция за промяна на размера на колекцията и направете примерен код за тестване:
template<class T>
class MyArray
{
private:
	T* array;
	int size;
public:
	MyArray(int size) :size(size), array(new T[size]) {}
	T get(int index) {
		if (index < size && index >= 0) return array[index];
	}
	int getSize() { return size; }
	T& operator[](int index) {

		if (index < size && index >= 0) return array[index];
		T a;
		return a;
	}
	void resize(int newSize) {
		if (newSize == 0) return;
		T* newArray = new T[newSize]();
		int copySize = (newSize < size) ? newSize : size;
		for (int i = 0; i < copySize; i++) {
			newArray[i] = array[i];
		}
		delete[]array;
		array = newArray;
		size = newSize;
	}
	/*Напишете предефиниран оператор += който да приема :
	Друг обект MyArray и добавя копие на елементите му в колекцията
		Обект от тип Т, който се добавя в края на колекцията.*/

	void operator+=( MyArray& otherArr) {
		int oldSize = size;
		int otherSize = otherArr.getSize();
		int newSize = size + otherSize;
		this->resize(newSize);
		for (int i = 0; i < otherSize; i++) {
			array[oldSize+i] = otherArr[i];
		}
	}

	void operator+=(const T& element) {
		int oldSize = size;
		resize(size + 1);
		array[oldSize] = element;
	}
};

int main() {
		
	MyArray<int> arr(5);
	arr[0] = 5;
	arr[1] = 4;
	arr[2] = 4;
	arr[3] = 4;
	arr[4] = 4; 
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "Element: " << arr.get(i) << endl;
	}
	cout << "------------------" << endl;
	MyArray<int> bar(5);
	bar[0] = 7;
	bar[1] = 8;
	bar[2] = 9;
	bar[3] = 10;
	bar[4] = 42;
	for (int i = 0; i < bar.getSize(); i++) {
		cout << "Element: " << bar.get(i) << endl;
	}
	cout << "------------------" << endl;
	arr += bar;
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "Element: " << arr.get(i) << endl;
	}
	arr += 69;
	cout << "------------------" << endl;

	for (int i = 0; i < arr.getSize(); i++) {
		cout << "Element: " << arr.get(i) << endl;
	}
	
	return 0;
}