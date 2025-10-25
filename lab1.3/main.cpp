#include <iostream>
#include <vector>
using namespace std;


class Worker {

private:
	int ssn;
	string name;
	int xp;
	string position;
	vector<float> salaries;

public:
	Worker(string name="", int ssn=0, int xp = 0, string position = "", vector<float>salaries = {}) :
		name(name), ssn(ssn), xp(xp), position(position), salaries(salaries)
	{
		if (name == "") {
			cout << "Worker unknown with 0 years of xp who is unemployed and doesn't have salaries is CREATED!!!" << endl;
		}
		else {
			cout << "Worker "<<name<<" with 0 years of xp who is unemployed and doesn't have salaries is CREATED!!!" << endl;

		}
		}
	
	Worker(string name, int ssn, int xp = 0,vector<float>salaries = {}) :
		name(name), ssn(ssn), xp(xp),salaries(salaries)
	{
		string currPos;

		cout << "What position does this worker have: \n";
		cin >> this->position;
		cout << "Worker "<<name<<" with "<<xp<<"xp who is "<<position<<" and does have "<<salaries.size()<<" salaries is CREATED!!!" << endl;
	}


};

int main() {



	vector<float>salaries;
	salaries.push_back(2000);
	salaries.push_back(4050);
	salaries.push_back(7000);

	Worker jimmy("jimmy");


	Worker jack("Jack", 234556, 2, salaries);
	
	cout << "cool" << endl;

















	/*
	string name = "bob";
	string *pName = &name;
	cout << "name is: " << name<<endl;
	cout << "&name is: " << &name << endl;
	cout << "pName is: " << pName << endl;
	cout << "*pName is: " << *pName << endl;
	cout << "&pName is: " << &pName << endl;
	*/





	return 0;
}

