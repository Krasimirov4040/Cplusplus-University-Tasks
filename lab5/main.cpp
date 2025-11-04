#include <iostream>
#include <vector>
using namespace std;

//В класа за Стока добавете метод, който да отпечатва данни за стоката на екрана(чрез print() или << ).
//В класа за Хранителна стока добавете да се отпечатва и срока на годност, 
//състава и хранителната стойност
//В класа за Книга добавете да се отпечатват полетата на книгата.

class Stock {
private:
	string name;
	string date;
	float price;
public:
	Stock(string n,string d,float p):
		name(n),date(d),price(p)
	{
	}
	void printS() {
		cout << "Name: " << name << endl
			<< "Date produced: " << date << endl
			<< "Price: " << price << endl;
	}
	virtual void print() {
		printS();
	}
};

class FoodStock:public Stock {
private:
	string expiry;
	vector<string> ingredients;
	float nutritionalValue;

public:
	FoodStock(string n,string d,float p,string exp,vector<string>ingr,float ntVal) : 
		Stock(n,d,p),expiry(exp),ingredients(ingr),nutritionalValue(ntVal){}

	void print() override {
		printS();
		cout << "Expiry date: " << expiry << endl
		<<"Ingredients: ";
		for (size_t i = 0; i < ingredients.size(); ++i) {
			cout << ingredients[i];
			if (i < ingredients.size() - 1) cout << ", ";
		}

		cout << endl << "Nutritional value kcal/100gr: " << nutritionalValue << endl;
	}
};

class Book :public Stock {
private:
	string title;
	string author;
public:
	Book( string d, float p, string t, string a, string n = "book") :
		Stock(n, d, p), title(t), author(a) {
	}

	void print() override{
		printS();
		cout << "Title: " << title << endl
			<< "Author: " << author << endl;
	}
};

int main() {
	vector<string> ing = { "salt","meat","water" };
	Book* atomicHabits = new Book("2022-12-03", 12.99f, "Atomic Habits", "James Clear");
	FoodStock* ham = new FoodStock("Ham", "2025-03-05", 6.99f, "2025-12-12", ing, 150);
	Book* book2 = new Book("2022-12-03", 15.99, "Art of War", "Sun Tzu");
	FoodStock* salami = new FoodStock("salami", "2025-03-05", 6.99f, "2025-12-12", ing, 250);

	// Vector of raw pointers (simpler syntax)
	vector<Stock*> stocks = { ham, salami, atomicHabits, book2 };

	// Loop: Use -> for pointers
	for (auto s : stocks) {
		s->print();
		cout << "------------------" << endl;
	}

	// Cleanup: Delete each to avoid leaks
	for (auto s : stocks) {
		delete s;
	}

	return 0;
}