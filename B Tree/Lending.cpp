#include "Lending.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
Lending::Lending()
{
}


void Lending::set_date(string Date)
{
	this->date = Date;
}

Lending::~Lending()
{
}

bool Lending::operator!=(const Lending & other) const//Returns false only they are equal on every aspect
{
	return (!((this->code == other.code) && (this->date == other.date) && (this->id == other.id) && (this->name == other.name)));
}

bool Lending::operator==(const Lending & other) const//Returns true only they are equal on every aspect
{
	return ((this->code == other.code) && (this->date == other.date) && (this->id == other.id) && (this->name == other.name));
}

bool Lending::operator>=(const Lending & other) const//If date is equal return true. Else compare according to other fields
{
	if (this->date == other.date)
		return true;
	if (this->date != other.date)
		return this->date >= other.date;
	if (this->code != other.code)
		return this->code >= other.code;
	return this->id >= other.id;
}

bool Lending::operator>(const Lending & other) const
{
	if (this->date != other.date)
		return this->date > other.date;
	if (this->code != other.code)
		return this->code > other.code;
	return this->id > other.id;
}

bool Lending::operator<=(const Lending & other) const//If date is equal return true. Else compare according to other fields
{
	if (this->date == other.date)
		return true;
	if (this->date != other.date)
		return this->date <= other.date;
	if (this->code != other.code)
		return this->code <= other.code;
	return this->id <= other.id;
}

bool Lending::operator<(const Lending & other) const
{
	if (this->date != other.date)
		return (this->date < other.date);
	if (this->code != other.code)
		return (this->code < other.code);
	return (this->id < other.id);
}

istream & operator>>(istream & is, Lending & l)
{
	cout << "enter id name date item ";
	is >> l.id >> l.name >> l.date >> l.code;
	return is;
}

ostream & operator<<(ostream & os, Lending & l)
{

	os << endl << "Lending details: id: " << l.id << " name: " << l.name << " date: " << l.date << " item: " << l.code << endl;
	return os;

}

