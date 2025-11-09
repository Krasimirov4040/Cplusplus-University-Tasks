#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Device {
protected:
	string name;
	double price;
	string maker;
public:
	Device(string name,double price,string maker):
	name(name),price(price),maker(maker)
	{}

	void changePrice(const double& newPrice) {
		if (newPrice < 0) {
			cout << "Invalid price!" << endl;
			return;
		}
		else {
		price = newPrice;
		cout << "New price is " << newPrice <<"$"<< endl;
		}
	}
	virtual double calculateWarranty() = 0;
	virtual void print() = 0;
	virtual ~Device() {}
};
class Phone :virtual public Device {
protected:
	double screenSize;
	int batterySize;
public:
	Phone(string name,double price,string maker,double screenSize,int batterySize):
	Device(name,price,maker),screenSize(screenSize),batterySize(batterySize)
	{
		if (this->batterySize < 1000)
			this->batterySize = 2000;
	}

	void print() override {
		cout << "Name: " << name << endl
			<< "Price: " << price << endl
			<< "Maker: " << maker << endl
			<< "Screen size: " << screenSize << "inches" << endl
			<< "Battery size: " << batterySize << "mAh" << endl;
	}
	double calculateWarranty() override {
		if (batterySize > 3000) {
			return 12;
		}
		else {
			return 6;
		}
	}

	Phone operator+(Phone& p) {
		Phone temp(*this);
		temp.name += "+ "+p.name;
		temp.price += p.price;
		return temp;
	}

	Phone& operator=(Phone& p) {
		this->name = p.name;
		this->price = p.price;
		this->maker = p.maker;
		this->screenSize = p.screenSize;
		this->batterySize = p.batterySize;

		return *this;
	}

	Phone& operator-(Phone& p) {
		if (this->batterySize - p.batterySize > 0) {
			this->batterySize -= p.batterySize;
		}
		else {
			this->batterySize = 0;
		}
		return *this;
	}

};
class Laptop :public Device {
private:
	string cpu;
	int memory;
public:
	Laptop(string name,double price,string maker,string cpu,int memory):
		Device(name,price,maker),cpu(cpu),memory(memory)
	{
		if (this->memory < 4)
			this->memory = 8;
	}

	void print() override {
		cout << "Name: " << name << endl
			<< "Price: " << price << endl
			<< "Maker: " << maker << endl
			<< "CPU: " << cpu << endl
			<< "Memory: " << memory <<"GB"<< endl;
	}
	double calculateWarranty()override {
		if (memory > 8) {
			return 24;
		}
		else {
			return 12;
		}
	}


	Laptop operator+(Laptop& l) {
		Laptop temp(*this);
		temp.name += "+"+l.name;
		temp.price += l.price;
		return temp;
	}

	Laptop& operator=(Laptop& l) {
		this->name = l.name;
		this->price = l.price;
		this->maker = l.maker;
		this->cpu = l.cpu;
		this->memory = l.memory;
		return *this;
	}

};
class Accessory:virtual public  Device {
protected:
	string compatibility;
public:
	Accessory(string name, double price, string maker,string comp) :
		Device(name, price, maker), compatibility(comp)
	{
	}
	double calculateWarranty()override {
		return 3.0;
	}
	void print() override {
		cout << "Accessory - Compatibility: " << compatibility << endl;
	}
};
class PhoneAccessory:public Phone,virtual public Accessory {
public:
	PhoneAccessory(string name, double price, string maker, double screenSize, int batterySize, string comp) :
		Device(name, price, maker),
		Phone(name,price,maker,screenSize,batterySize),
		Accessory(name, price, maker,comp)
		
	{
		compatibility = "Phones";
		this->batterySize = 0;
	}
	double calculateWarranty() override {
		double warranty = (Phone::calculateWarranty() + Accessory::calculateWarranty()) / 2;

		return warranty;
	}
	void print()override {
		Phone::print();
		cout << "Compatibility: " << compatibility<<endl;

	}
};

class Market {
private:
	vector<Device*>devices;

public:

	void addDevice(Device* d) {
		devices.push_back(d);
	}
	void removeDevice(Device* d) {
		auto it = std::find(devices.begin(), devices.end(), d);
		if (it == devices.end()) {
			cout << "Error: Device is not found in the market!" <<endl;
		}

		devices.erase(remove(devices.begin(), devices.end(), d), devices.end());
		cout << "Device removed successfully from the market." << endl;
	}

	void calculateTotalWarranty() {
		double totalWarranty = 0;
		for(auto&d :devices){
			totalWarranty += d->calculateWarranty();
		}
		cout << "Total warranty of all devices in the market is: "
			<< totalWarranty << " months" << endl;
	}
};
int main() {

	Phone iphone16("Iphone 16 ", 100, "Apple", 6, 500);
	Phone iphone17("Iphone 17 ", 600, "Apple", 6, 6000);
	Phone iphone13("Iphone 13 ", 300, "Apple", 6, 4000);
	Phone iphone14("Iphone 14 ", 350, "Apple", 6, 40000);
	Laptop lenovoLaptop("ThinkPad", 500, "Lenovo", "Intel core i7", 1);
	Laptop dellLaptop("Inspiron", 400, "Dell", "AMD Ryzen 5", 16);
	Laptop sonyLaptop("Vivo", 450, "Sony", "AMD Ryzen 5", 18);
	PhoneAccessory phoneCase("Phone Case", 25, "FOXI", 6.0, 0, "Iphone 13,Iphone 14");


	vector<Device*> devices;


	devices.push_back(&iphone16);
	devices.push_back(&lenovoLaptop);
	devices.push_back(&iphone17);
	devices.push_back(&dellLaptop);
	devices.push_back(&phoneCase);






	/*В main() създайте обект Магазин, добавете обекти от всички класове(включително от Задача 5), 
		използвайте предефинираните оператори за да модифицирате цени, и изведете общата гаранция.*/
	
	Market market;
	market.addDevice(&iphone16);
	market.addDevice(&lenovoLaptop);	
	market.addDevice(&iphone17);	
	market.addDevice(&dellLaptop);
	market.addDevice(&phoneCase);
	iphone16.changePrice(567);
	lenovoLaptop.changePrice(700);
	market.calculateTotalWarranty();

	/*sonyLaptop = lenovoLaptop;

	Phone iphone1=iphone14 - iphone13;

	Phone hybridPhone = iphone16 + iphone17;
	hybridPhone.print();
	Laptop hybridLaptop = dellLaptop + lenovoLaptop;
	hybridLaptop.print();
	iphone1.print();
	sonyLaptop.print();*/


	/*for (auto& d : devices)
	{
		d->print();
		cout << "Warranty of this device is: " << d->calculateWarranty() << " months\n" <<
			"----------------------" << endl;
	}*/




	return 0;
}
