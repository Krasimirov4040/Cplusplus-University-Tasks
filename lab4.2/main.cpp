#include <iostream>
using namespace std;
//Задача 1
//Напишете клас Линийка, който притежава :
//
//стойност(реално число)
//мерна единица(стринг)
//Този клас да има :
//Конструктор с параметри
//Copy конструктор
//оператор + за събиране на две линийки(взима се мерната ед.на първата линийка) (5м + 2см = 7м)
//оператор << за извеждане на стойноста на линийката


//Copy конструктор от реално число(мер.ед.е "м")

class Ruler {
private:
	double value;
	string unit;
public:
	Ruler(double v,string u):
		value(v),unit(u)
	{

	}

	//copy constructor
	Ruler(Ruler& obj,string u) {
		value = obj.value;
		unit = obj.unit;
	}

	Ruler operator+(Ruler& obj) {
		double newValue = value;
		if (unit == obj.unit) {
			newValue += obj.value;
		}
		else if (unit == "м" && obj.unit == "см") {
			newValue += obj.value / 100;
		}
		else if (unit == "см" && obj.unit == "м") {
			newValue += obj.value * 100;
		}
		return Ruler(newValue, unit);
	}


};

int main(){



	return 0;
}