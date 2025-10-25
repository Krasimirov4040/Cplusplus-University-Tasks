#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Workman {
private:
	int ssn;
	string name;
	float xp;
	string role;
	vector<float> salaries;

public:
	Workman(string name="", int ssn = 0, float xp = 0, string role="", vector<float>salaries={}) :
		ssn(ssn),xp(xp),name(name),role(role),salaries(salaries)
	{	
		if (role.empty()) {
		string role;
		cout << "What  is the role of the current worker:  ";
		cin >> role;
		this->role = role;
		}
	}

	//getters

	int getSsn() {
		return ssn;
	}
	string getName() {
		return name;
	}
	float getXp() {
		return xp;
	}
	string getRole() {
		return role;
	}
	vector<float> getSalaries() {
		return salaries;
	}

	//setters bez referencii

	void setSsn(int newSsn) {
		ssn = newSsn;
	}
	void setName(string newName) {
		name = newName;
	}
	void setXp(float newXp) {
		xp = newXp;
	}
	void setRole(string newRole) {
		role = newRole;
	}
	void setSalaries(vector<float> newSalaries) {
		salaries = newSalaries;
	}

	void avgSalary() {
		float sum=0;
		int counter = 0;
		float avg;
		for (float salary : salaries) {
			sum += salary;
			counter++;
		}
		avg = sum / counter;
		cout << "Average salary is : " << avg << endl;
	}

	void minSalary() {
		float min = salaries.front();

		for (float salary : salaries) {
			if (salary < min) {
				min = salary;
			}
		}
	}
	void introduce() {
		cout << "Name is : " << name << "\n SSN: " << ssn << "\n Role is : " << role << endl;
	}
};


int main() {

	Workman man("ivan",123445,2);
	man.setSsn(667);
	man.introduce();

	return 0;
}