#include <iostream>
using namespace std;


class Item {
private:
	string title;
	float price;
	string format;
	string date;

public:
	Item(string title, float price, string format,string date):
	title(title),price(price),format(format),date(date)
	{
	}

	void printI() {
		cout << "Title: " << title << endl
			<< "Price: " << price << endl
			<< "Format: " << format << endl
			<< "Date bought: " << date << endl;
	}
};
//Movie : наследява Item + рейтинг.
class Movie:public Item {
private:
	float rating;
public:

	Movie(string title, float price, string format, string date,float rating): 
		Item(title,price,format,date),rating(rating)
	{
	}

	void print() {
		printI();
		cout << "Rating: " << rating<<endl;
	}

};
//Game : наследява Item + ниво на трудност.

class Game : public Item
{
private:
	int difficulty;
public:
	Game(string title, float price, string format, string date, int difficulty) :
		Item(title, price, format, date), difficulty(difficulty)
	{}
	
	void print() {
		printI();
		cout << "Difficulty: " << difficulty << endl;
	}
};
//Music : наследява Item + изпълнители.

class Music :public Item {
private:
	string performer;
public:
	Music(string title, float price, string format, string date, string performer) :
		Item(title, price, format, date),performer(performer)
	{
	}

	void print() {
		printI();
		cout << "Performer: " << performer << endl;
	}
};

int main() {
	// Примерни обекти
	Movie m("Inception", 15.99, "DVD", "2023-01-15", 8.8);
	m.print();
	cout << endl;

	Game g("Dark Souls", 29.99, "Blu-ray", "2022-05-20", 10);
	g.print();
	cout << endl;

	Music mu("Thriller", 9.99, "CD", "1982-11-30", "Michael Jackson");
	mu.print();

	return 0;
}