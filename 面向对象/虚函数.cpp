#include <iostream>

using namespace std;

class Object
{
public:
    virtual string instance()
    {
        string str = "Object";
        return str;
    }
};

class Animal: public Object
{
public:
    string instance()
    {
        string str = "Animal";
        return str;
    }
};

class Dog: public Animal
{
public:
    string instance()
    {
        string str = "Dog";
        return str;
    }
};

class Cat: public Animal
{
public:
    string instance()
    {
        string str = "Cat";
        return str;
    }
};

class Vehicle:public Object
{
    public:
    string instance()
    {
        string str = "Vehicle";
        return str;
    }
};

class Bus:public Vehicle
{
    public:
    string instance()
    {
        string str = "Bus";
        return str;
    }
};

class Car:public Vehicle
{
    public:
    string instance()
    {
        string str = "Car";
        return str;
    }
};

class Person:public Object
{
    public:
    string instance()
    {
        string str = "Person";
        return str;
    }
};

class Student:public Person
{
    public:
    string instance()
    {
        string str = "Student";
        return str;
    }
};

class Teacher:public Person
{
    public:
    string instance()
    {
        string str = "Teacher";
        return str;
    }
};

string instanceof(Object& obj)
{
    string str = obj.instance();
    return str;
}


