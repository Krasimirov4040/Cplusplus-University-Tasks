#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Date {
private:
	int day;
	int month;
	int year;
public:
	int getDay()const {
		return day;
	}
	int getMonth()const {
		return month;
	}
	int getYear()const {
		return year;
	}
	void setDay(int day) {
		this->day = day;
	}
	void setMonth(int month) {
		this->month = month;
	}
	void setYear(int year) {
		this->year = year;
	}

	Date() {
		day=0;
		month=0;
		year=0;
	}
	Date(int day, int month, int year):day(day),month(month),year(year){}
};
class Student {
private:
	string name;
	int facNum;
	Date birthDate;
	double avgGrade;
public:
	string getName()const {
		return name;
	}
	int getFacNum()const {
		return facNum;
	}
	Date getBirthDate()const {
		return birthDate;
	}
	double getAverageGrade() const {
		return avgGrade;
	}

	void setName(string name) {
		this->name = name;
	}
	void setFacNum(int facNum) {
		this->facNum = facNum;
	}
	void setBirthDate(Date birthDate) {
		this->birthDate = birthDate;
	}
	void setAverageGrade(double avgGrade) {
		this->avgGrade = avgGrade;
	}
	int getAge(Date& date) {
		int age = date.getYear() - birthDate.getYear();

		if (birthDate.getMonth() < date.getMonth()) {
			age++;
		}
		else if (birthDate.getMonth() == date.getMonth()) {
			if (birthDate.getDay() < date.getDay()|| birthDate.getDay() == date.getDay()) {
				age++;
			}
		}
		return age;
	}
	Student(){
		name="";
		facNum=0;
		birthDate;
		avgGrade=0;
	}
	Student(string name,int facNum,Date bd,double avgGrade):name(name),facNum(facNum),birthDate(bd),avgGrade(avgGrade){}
};

//като се предефинира операцията << 
ostream& operator<<(ostream& os, const Date& d){
	os << d.getDay() << "." << d.getMonth() << "." << d.getYear();
	return os;
}
ostream& operator<<(ostream& os,const Student& s) {
	os << "Name: " << s.getName() << endl
		<< "Faculty number: " << s.getFacNum() << endl
		<< "Birth date:" << s.getBirthDate() << endl
		<< "Average grade: " << s.getAverageGrade() << endl<<endl;
	return os;
}


//Да се намери студента с максимален успех от потока.
class Potok {
private:
	vector<Student> students;
public:
	void addStudent(Student& s) {
		students.push_back(s);
	}

	Student findTheBest() {
		Student theBest=*students.begin();
		for (auto& s : students) {
			if (s.getAverageGrade() > theBest.getAverageGrade())
				theBest = s;
		}
		return theBest;
	}
//Да се извеждат студентите от потока, които са между 18 и 26 години включително,
	void findStudentsBetween18N26() {
		Date today(19, 11, 2025);
		for (auto& s : students) {
			if (s.getAge(today) > 18 && s.getAge(today) < 26) {
				cout << s;
			}
		}
	}
//Данните да се съхраняват във файл.
	void savetoFile() {
		ofstream myFile("studentsInfo.txt");
		for (auto& s : students) {
			myFile << s;
			myFile << "-----------------" << endl;
		}
	}

};


int main() {
	Date bd1(12, 10, 1998);
	Date bd2(15, 4, 2012);
	Date bd3(1, 11, 2003);
	Date bd4(1, 1, 2005);

	Student s1("Ivan", 1234555, bd1, 5.45);
	Student s2("Gundi", 454555, bd2, 4.45);
	Student s3("Dundi", 45678988, bd3, 3.45);
	Student s4("Mundi", 45678988, bd4, 5.00);

	Potok p1;
	p1.addStudent(s1);
	p1.addStudent(s2);
	p1.addStudent(s3);
	p1.addStudent(s4);

	Student s=p1.findTheBest();
	cout << s;
	p1.findStudentsBetween18N26();
	p1.savetoFile();

	return 0;
}