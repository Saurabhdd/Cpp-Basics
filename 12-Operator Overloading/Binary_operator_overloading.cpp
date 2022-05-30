#include <stdio.h>
#include <stdlib.h>

class binary_operator
{
private:
	int data;

public:
	binary_operator(int _data): data(_data){}

	//operator overloading
	binary_operator operator+(const binary_operator& other);
	binary_operator operator-(const binary_operator& other);
	binary_operator operator*(const binary_operator& other);
	binary_operator operator/(const binary_operator& other);
	binary_operator operator%(const binary_operator& other);
	binary_operator operator<<(const binary_operator& other);
	binary_operator operator>>(const binary_operator& other);

	//logical opertaor
	bool operator<(const binary_operator& other);
	bool operator>(const binary_operator& other);
	bool operator<=(const binary_operator& other);
	bool operator>=(const binary_operator& other);
	bool operator!=(const binary_operator& other);
	bool operator==(const binary_operator& other);
	bool operator&&(const binary_operator& other);
	bool operator||(const binary_operator& other);

	//bitwise operator
	binary_operator operator&(const binary_operator& other);
	binary_operator operator|(const binary_operator& other);
	binary_operator operator^(const binary_operator& other);

	void show(char* msg);

};


void binary_operator::show(char* msg = NULL)
{
	if (msg)
		printf("%s: %d\n", msg, data);
	else
		printf("%d\n", data);
}

binary_operator binary_operator::operator+(const binary_operator& other)
{
	return binary_operator(this->data + other.data);
}

binary_operator binary_operator::operator-(const binary_operator& other)
{
	return binary_operator(this->data - other.data);
}

binary_operator binary_operator::operator*(const binary_operator& other)
{
	return binary_operator(this->data * other.data);
}

binary_operator binary_operator::operator/(const binary_operator& other)
{
	return binary_operator(this->data / other.data);
}

binary_operator binary_operator::operator%(const binary_operator& other)
{
	return binary_operator(this->data % other.data);
}

binary_operator binary_operator::operator<<(const binary_operator& other)
{
	return binary_operator(this->data << other.data);
}

binary_operator binary_operator::operator>>(const binary_operator& other)
{
	return binary_operator(this->data >> other.data);
}


//logical operators
bool binary_operator::operator<(const binary_operator& other)
{
	return this->data < other.data;
}

bool binary_operator::operator>(const binary_operator& other)
{
	return this->data > other.data;
}

bool binary_operator::operator<=(const binary_operator& other)
{
	return this->data <= other.data;
}

bool binary_operator::operator>=(const binary_operator& other)
{
	return this->data >= other.data;
}


bool binary_operator::operator!=(const binary_operator& other)
{
	return this->data != other.data;
}

bool binary_operator::operator==(const binary_operator& other)
{
	return this->data == other.data;
}


bool binary_operator::operator&&(const binary_operator& other)
{
	return this->data && other.data;
}


bool binary_operator::operator||(const binary_operator& other)
{
	return this->data || other.data;
}


//bitwise operator
binary_operator binary_operator::operator&(const binary_operator& other)
{
	return binary_operator(this->data & other.data);
}

binary_operator binary_operator::operator|(const binary_operator& other)
{
	return binary_operator(this->data | other.data);
}

binary_operator binary_operator::operator^(const binary_operator& other)
{
	return binary_operator(this->data ^ other.data);
}


int main(int argc, char* argv[])
{
	binary_operator obj1(40);
	binary_operator obj2(30);

	//addition
	binary_operator rs = obj1 + obj2;
	rs.show("addition:");

	//subtraction
	rs = obj1 - obj2;
	rs.show("subtraction:");

	//multiplication
	rs = obj1 * obj2;
	rs.show("Multiplication");

	//division
	rs = obj1 / obj2;
	rs.show("Division");

	//modulus
	rs = obj1 % obj2;
	rs.show("Modulus");

	//right shift operation
	rs = obj1 << obj2;
	rs.show("Right shift");

	//left shift operator
	rs = obj1 >> obj2;
	rs.show("Left shift");

	//bitwise operators
	rs = obj1 & obj2;
	rs.show("bitswise and:");

	rs = obj1 | obj2;
	rs.show("bitwise or");

	rs = obj1 ^ obj2;
	rs.show("bitwise xor");

}