#pragma once
#include <string>
#include <iostream>



struct Subscriber
{
	std::string name;
	std::string address;
	std::string telephone;
	Subscriber(std::string name = "", std::string address = "", std::string telephone = "") :
		name(name), address(address), telephone(telephone) {}
};

std::istream& operator >> (std::istream& st, Subscriber& a)
{
	getline(st, a.name);
	getline(st, a.address);
	getline(st, a.telephone);

	return st;
}

std::ostream& operator << (std::ostream& st, Subscriber a)
{
	return st << "���:" << a.name << std::endl << "�����:" << a.address << std::endl << "����� ��������:" << a.telephone << std::endl;

}
