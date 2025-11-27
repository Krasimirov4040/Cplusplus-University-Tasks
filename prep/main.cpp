#include <iostream>
#include <vector>
using namespace std;

//Напишете клас Човек, който да има :
//Име
//Възраст
class Human {
protected:
	string name;
	int age;
	friend ostream& operator<<(ostream& os, Human& h);
public:
	Human(string name, int age) :name(name), age(age) {}

virtual void print() {
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}
};

//Напишете клас Клиент, който да наследява Човек и да има :
//Клиентски номер
class Client :virtual  public Human{
protected:
	double clientNum;
public:
	Client(string name,int age,double cNum):Human(name,age),clientNum(cNum){}
	virtual void print() {
		Human::print();
		cout << "Client number: " << clientNum<<endl;
	}
};
//Напишете клас Служител, който да наследява Човек и да има :
//Департамент
class Employee: virtual public Human {
protected:
	string department;
public:
	Employee(string name,int age,string dept):Human(name,age),department(dept){}
	virtual void print() {
		Human::print();
		cout << "Department: " << department << endl;
	}
};
//Напишете клас ProductTester, който да наследява Клиент и Служител и да има :
//Брой тествани продукти.
class ProductTester :virtual public Client, virtual public Employee {
protected:
	int prodTested;
public:
	ProductTester(string name,int age,double cNum,string dept,int prodTested):Human(name,age),Client(name,age,cNum),Employee(name,age,dept){}
	virtual void print() {
		Client::print();
		cout << "Department: " << department << endl
			<< "Tested products: " << prodTested<<endl;
	}
};
ostream& operator<<(ostream& os, Human& h) {
	cout << "Name: " << h.name << endl
		<< "Age: " << h.age << endl;
	return os;
}
//Имплементирайте във всеки клас метод print(), който да извежда цялата информация за обекта.
//Направете масив от обекти от тип Човек, който да включва по един представител на клас.
//Изпълнете print() за всеки обект от масива.

int main() {
	vector<shared_ptr<Human>> people;
	auto human = Human("Deni", 13);
	people.push_back(make_shared<Human>(human));
	people.push_back(make_shared<Client>(Client("ivan", 22, 12345)));
	people.push_back(make_shared<Employee>(Employee("Rosi", 34, "HR")));
	people.push_back(make_shared<ProductTester>(ProductTester("Wundi", 54, 5678, "IT", 23)));

	for (auto& p : people) {
		p->print();
		cout << "-------------------" << endl;
	}
	cout << human;
	
	return 0;
}
