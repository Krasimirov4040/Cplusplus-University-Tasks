#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Изисквания :
//конструктори и деструктори А
//функции за извеждане А
//добавяне и изтриване на елементи A
//намиране на кондензатори в дадени граници по стойност A
//предефиниране на operator<< A
//съхранение във файл A

class ElectronicComponent {
protected:
	string nomenclature;
	string name;
	double value;
	string unit;
	friend class Components;
public:
	ElectronicComponent(string nomenclature, string name, double value, string unit) :
		nomenclature(nomenclature), name(name), value(value), unit(unit) 
	{
	//	cout << "ElectronicComponent created!!!" << endl;

	}

	virtual void print() {
		cout << "Name: " << name << endl
			<< "Nomenclature: " << nomenclature << endl
			<< "Value: " << value << " " << unit << endl;
	}

	// copy constructor
	ElectronicComponent(const ElectronicComponent& other)
		: nomenclature(other.nomenclature),
		name(other.name),
		value(other.value),
		unit(other.unit)
	{
		//cout << "ElectronicComponent COPIED!!!" << endl;
	}
	virtual string toString() {
		return "Name: " + name + "\nNomenclature: " + nomenclature +
			"\nValue: " + to_string(value) + " " + unit;
	}

	virtual ~ElectronicComponent() {
		//cout << "ElectronicComponent destroyed!!!" << endl;
	}
};
class Capacitor:public ElectronicComponent {
protected:
	string country;
	double price;
	friend ostream& operator<<(ostream& os, Capacitor& cap);
public:
	Capacitor(string nomenclature, string name, double value, string unit, string country, double price) :
		ElectronicComponent(nomenclature, name, value, unit), country(country), price(price)
	{
		//cout << "Capacitor created!!!" << endl;

	}


	Capacitor(const Capacitor& other)
		: ElectronicComponent(other),
		country(other.country),
		price(other.price)
	{
		//cout << "Capacitor COPIED!!!" << endl;
	}

	virtual void print() {
		ElectronicComponent::print();
		cout << "Made in " << country << endl
			<< "Costs: " << price << "$" << endl;
	}

	string getNomenclature() {
		return nomenclature;
	}

	virtual string toString() {
		return ElectronicComponent::toString() + "\nMade in: " + country 
			+ "\nPrice: " + to_string(price) + "$";
	}

	virtual ~Capacitor() {
	//	cout << "Capacitor destroyed!!!" << endl;
	}
};
class Resistor:public ElectronicComponent {
protected:
	string country;
	double price;
	friend ostream& operator<<(ostream& os, Resistor& res);
public:
	Resistor(string nomenclature,string name,double value,string unit,string country,double price):
		ElectronicComponent(nomenclature, name, value, unit), country(country), price(price)
	{ 
		//cout << "Resistor created!!!" << endl;
	}
	

	Resistor(const Resistor& other)
		: ElectronicComponent(other),  // вика copy на базовия клас
		country(other.country),
		price(other.price)
	{
		//cout << "Resistor COPIED!!!" << endl;
	}

	virtual void print() {
		ElectronicComponent::print();
		cout << "Made in " << country << endl
			<< "Costs: " << price << "$" << endl;
	}
	string getNomenclature() {
		return nomenclature;
	}
	virtual string toString() {
		return ElectronicComponent::toString() + "\nMade in: " + country
			+ "\nPrice: " + to_string(price) + "$";
	}

	virtual ~Resistor() {
		//cout << "Resistor destroyed!!!" << endl;
	}
};

class Components {
private:
	vector<shared_ptr<ElectronicComponent>> list;
public:
	Components() {}

	void addComponent(Resistor& resistor) {
		list.push_back(make_shared<Resistor>(resistor));
	}
	void addComponent(Capacitor& capacitor) {
		list.push_back(make_shared<Capacitor>(capacitor));
	}

	void removeComponent(const string& nomenclature) {
		for (auto i = list.begin(); i != list.end();) {
			if ((*i)->nomenclature == nomenclature) {
				i= list.erase(i);
			}
			else {
				++i;
			}
		}
	}
	void print() {
		for (auto elComp : list) {
			elComp->print();
			cout << "--------------------------" << endl;
		}
	}

	void printToFile() {
		ofstream file("test.txt");
		for (auto comp : list) {
			file<<comp->toString()<<"\n-------------\n";
		}
		file.close();
	}

	void findCapacitors(double min, double max, const string& unit = "F") {
		for (auto capacitor : list) {
			double capacitorValue = capacitor->value;
			string capacitorUnit = capacitor->unit;

			if (unit == "mF") {
				capacitorValue *= 0.001;  // millifarad to farad
			}
			else if (unit == "kF") {
				capacitorValue *= 1000;   // kilofarad to farad
			}

			if (capacitorValue >= min && capacitorValue <= max && (capacitor->unit=="F"|| capacitor->unit == "mF"|| capacitor->unit == "kF")) {

				cout << "--------------------------" << endl;
				capacitor->print();
			}
		}
	}
};

ostream& operator<<(ostream& os, Capacitor& cap) {
	os << "Name: " << cap.name << endl
		<< "Nomenclature: " << cap.nomenclature << endl
		<< "Value: " << cap.value << " " << cap.unit << endl
		<< "Made in: " << cap.country << endl
		<< "Price: " << cap.price << endl;
	return os;
}
ostream& operator<<(ostream& os, Resistor& res) {
	os << "Name: " << res.name << endl
		<< "Nomenclature: " << res.nomenclature << endl
		<< "Value: " << res.value << " " << res.unit << endl
		<< "Made in: " << res.country << endl
		<< "Price: " << res.price << endl;
	return os;
}

int main() {

	Components list;
	auto resistor1 = Resistor("R-100om-5%", "Resistor 1.0", 100, "OM", "Bangladesh", 0.25);
	auto resistor2 = Resistor("R-500om-5%","Resistor 2.0",500,"OM","Bangladesh",1.25);
	auto capacitor1 = Capacitor("C-250f-0", "Capacitor 1.0", 250, "F", "India", 2.00);
	auto capacitor2 = Capacitor("C-760f-0", "Capacitor 2.0", 760, "F", "China", 5.20);


	list.addComponent(resistor1);
	list.addComponent(resistor2);
	list.addComponent(capacitor1);
	list.addComponent(capacitor2);
	cout << capacitor1 << endl;
	cout << resistor1 << endl;
	cout << capacitor2 << endl;
	cout << resistor2<<endl;
	list.printToFile();


	list.findCapacitors(200, 800);
	//list.removeComponent(resistor1.getNomenclature());
	//list.removeComponent(capacitor2.getNomenclature());
	//list.print();

	return 0;
}