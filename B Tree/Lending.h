#pragma once
#include <iostream>
#include <string>
using namespace std;
class Lending
{
public:
	Lending();
	int id;
	string name;
	string date;
	int code;
	void set_date(string Date);
	~Lending();
	bool operator !=(const Lending & other)const;
	bool operator == (const Lending & other)const;
	//Operators preference : date , code , id
	bool operator >=(const Lending & other)const;
	bool operator >(const Lending & other)const;
	bool operator <=(const Lending & other)const;
	bool operator <(const Lending & other)const;
	friend istream& operator>>(istream& is, Lending& l);
	friend ostream& operator<<(ostream& os, Lending& l);
};

