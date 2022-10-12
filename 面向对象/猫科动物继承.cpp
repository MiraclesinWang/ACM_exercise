#include <iostream>

class Cat
{
	int data;
public:
	Cat();
	Cat(int);
};

Cat::Cat()
{
	std::cout << "Default Constructor of Cat is Running\n";
}

Cat::Cat(int d)
{
	std::cout << "Constructor of Cat is Running " << d << std::endl;
	data = d;
}

class Tiger: public Cat
{
	int data;
public:
	Tiger(int);	
};

Tiger::Tiger(int d): Cat(d)
{
	std::cout << "Constructor of Tiger is Running " << d << std::endl;
	data = d; 
}

int main()
{
	Cat bc;
	Tiger dc(6);
	Tiger dc1(18);
	
	return 0;
}
