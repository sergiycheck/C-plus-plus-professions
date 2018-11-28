// Project.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <utility> 
#include <map>
#include <vector>
#include "Profession.h"
#include "AbstractInfoProf.h"
#include "ProfInfo.h";

#include "Myheader.h"
//==============connect mysql================//



using namespace std;
void training();
//we may have out class A and It can be abstract because there are only declared
//functions that are equal to zero. For example virtual void sleep() = 0;
// but in inherited classes function sleep executed. For example void sleep(){cout<<"sleeping"<<endl;}
// in abstract class we declare all the functions that will be in inherited classes
class A
{
public:
	A(){};
	A(int a, string b) { num = a; name = b; };

	A operator+(A p) 
	{
		A q;
		q.name = name +" and "+ p.name;
		return q;
	}
	void getName() 
	{
		cout << name << endl;
	}
	virtual void info() 
	{
		cout << "A" << endl;
		//cout << a << endl;
	}

	friend ostream &operator<<(ostream &output, A &p);
	~A() {};
private:
	int num;
	string name;
	
};
class B :public A
{
public:
	B(int a =0,string b ="") {};
	void info()
	{
		cout << "B" << endl;
		//cout << a << endl;
	}
	void doSomethingFromB() 
	{
		obj.info();
	}
	~B() {};
private:
	int b;
	A obj;
};
class C :public B
{
public:
	C() {};
	void info()
	{
		cout << "C" << endl;
		//cout << a << endl;
	}
	~C() {};
private:
	int c;
};
 
void PrintMenue(vector<string> &status, int &statusindex)
{
	cout << "1] Choose Profession:" << endl;
	cout << "2] See all professions:" << endl;
	cout << "3] See all types of professions :" << endl;
	cout << "4] Delete type and profession :" << endl;
	cout << "5] Delete profession :" << endl;
	cout << "6] Add Profession:" << endl;
	cout << "7] Do test to find profession:" << endl;
	cout << "8] Write all information about you (what do you like, hobbies, occupations, Education, desires and it will find you a profession)" << endl;
	cout << "9] Exit" << endl;
	if (statusindex < 0 || statusindex >= status.size())
		statusindex = 4;
	cout << "Status >> " << status[statusindex] << endl;
	return;
}
void training()
{

	//A a(1,"Class A");
	A objApoint;
	objApoint.info();
	A *objA = new A;
	objA->info();
	A *objB = new B;
	objB->info();
	A *objC = new C;
	objC->info();

	cout << "the same thing but using array of objects \n";
	//polymorphism
	A *arr[3];
	arr[0] = new A;
	arr[1] = new B;
	arr[2] = new C;

	for (int i = 0; i < 3; i++)
	{
		arr[i]->info();
	}

	string a = "hello ";
	string b = "My name is Serihii";
	string c;
	c = sum<string>(a, b);
	cout << c << endl;

	A person1(22, "Mike"), person2(29, "Jack"), persons;

	persons = person1 + person2;
	persons.getName();

	pair<int, string> one;
	pair<int, string> second;

	one = make_pair(1, "Hello");
	second = make_pair(2, "I am Serhii");
	cout << "one " << one.first << ", " << one.second << endl;
	cout << "second " << second.first << ", " << second.second << endl;

	B dfa;
	dfa.doSomethingFromB();
}



int main()
{


	vector<string> status;
	//PrintMenue(vector<string> &status, int &statusindex)
	
	Profession start;
	start.AddTypeAndProf("sport", "Handball");
	start.GetInfoAboutProfFromUser();


	ProfInfo pers;
	pers.StoreFileNames();

	string profField = "HR";
	while (profField.length() != 0) 
	{
		cout << "Enter the profField" << endl;
		getline(cin, profField);
		if (profField.length() == 0) return 0;
		pers.WhatToSet(profField);
		pers.ToStringAllInfo();
	}





    return 0;
}

