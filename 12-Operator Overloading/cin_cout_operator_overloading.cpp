#include<iostream>

class date
{
private:
	int day, month, year;

public:
	//constructor
	date(int _day, int _month, int _year): day(_day), month(_month), year(_year){}

	friend std::istream& operator>>(std::istream& is, date& d);
	friend std::ostream& operator<<(std::ostream& os, const date& d);
};

//cin cout operator overloading
/*While overloading an operator, the lhs of the operator is the class wherein the 
operator is overloaded. However, in case of cin (>>) and count(<<) operators, the lhs and rhs 
is istream class object cin and ostream class object cout. So the first alternative for
cin and cout operator overloding is to implement the overloaded function in istream and ostream
classes. Sad part is that these are system classes and as a user we cannot not and will not be 
allowed to implement. 
So the second alternative to implement overloaded function on user defined type classes
and use the operators on the objects.
eg.

class T
{
private:
	int data;
public:
	T& operator>>(std::istream& is)
	{
		cin >> this->data >> std::endl;
	}
};

T obj;
std::istream& is;
obj >> is;

However, this is incorrect approach. Since the objects cin and cout must be the lhs for the 
cin and cout operators. So we can implement these overloaded functions out of class scope so that 
'this' pointer will not be available. And we can pass istream/ostream objects and user defined object 
as formal parameters.
However, in that case the data members of the class will not be available to the overloaded function.
Which makes the ambiguesness in the usability of the operator overloaded function.
As a solution to this, we can declare these functions friend of the user defined class, so that 
data members will get accessed from these functions. 
*/

std::istream& operator>>(std::istream& is, date& d)
{
	std::cout << "Enter a day:" << std::endl;
	is >> d.day;
	std::cout << "Enter the month: " << std::endl;
	is >> d.month;
	std::cout << "Enter the year:" << std::endl;
	is >> d.year;

	return is;
}

std::ostream& operator<<(std::ostream& os, const date& d)
{
	os << "month: " << d.month
		<< " day: " << d.day
		<< " year: " << d.year;

	return os;
}


//client
int main(int argc, char* argv[])
{
	date d(11, 5, 1992);

	std::cin >> d;

	std::cout << d;
}