#include <stdio.h>
#include <stdlib.h>

class unary_operator
{
private:
	int data;

public:

	unary_operator(int _data) : data(_data){}
	/*The symbols of the post-increment and pre-increment operators are same
	Hence we need to pass an int as formal parameter to post-increment operator overloading 
	function. So that compiler understands the difference between these two. 
	So eventually along with operator overloading it also acts as function overloding.*/

	unary_operator operator++();
	unary_operator operator++(int);

	//similar behaviour with pre and post decrement 
	unary_operator operator--();
	unary_operator operator--(int);
	unary_operator operator~();
	bool operator!();
	unary_operator operator-();
	void show(char* msg);
};

unary_operator unary_operator::operator++()
{
	++(this->data);
	return *this;
}

unary_operator unary_operator::operator++(int)
{
	unary_operator temp(data);
	data++;
	return temp;
}

unary_operator unary_operator::operator--()
{
	--(this->data);
	return *this;
}

unary_operator unary_operator::operator--(int)
{
	unary_operator temp(data);
	data--;
	return temp;
}

unary_operator unary_operator::operator-()
{
	unary_operator temp(-data);
	return temp;
}

bool unary_operator::operator!()
{
	return !(this->data);
}

unary_operator unary_operator::operator~()
{
	return unary_operator(~data);
}

void unary_operator::show(char *msg = NULL)
{
	if (msg)
		printf("%s: %d\n", msg, data);
	else
		printf("%d\n", data);
}


//clinet
int main(int argc, char* argv[])
{
	unary_operator temp(10);

	//pre-increment
	++temp;
	temp.show("pre-increment");

	//post-increment
	unary_operator rs = temp++;
	rs.show("post-increment");

	//logical not
	!temp;
	temp.show("logical not");

	//negation operator
	-temp;
	temp.show("negation");

	//pre-decrement
	--temp;
	temp.show("pre-decrement");

	//post-decrement
	temp--;
	temp.show("post-decrement");

	~temp;
	temp.show();
}