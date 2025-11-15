#include <iostream>
#include <vector>
using namespace std;	

class Stock {
protected:
	string name;
	string date;
	double price;

public:
	Stock(string date,double price,string name):
		date(date),price(price),name(name){ }

	void printS() {
		cout << "Name: " << name << endl
			<< "Date: " << date << endl
			<< "Price: " << price << endl;
	}
};

class FoodStock:public Stock {
private:
	string expiry;
	vector<string> ingredients;
	double nutValue;
public:
	FoodStock(string da,double pr,string nm,string exp,vector<string>ingr,double nV):
		Stock(da,pr,nm),expiry(exp),ingredients(ingr),nutValue(nV)
	{}
};
class Book :public Stock {
private:
	string title;
	string author;
public:
	Book(string da, double pr, string nm, string title, string auhtor) :
		Stock(da, pr, nm), title(title), author(author) {
		this->name = "book";
	}
};

int main() {


	return 0;
}
