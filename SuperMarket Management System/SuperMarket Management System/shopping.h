#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <iomanip>

using namespace std;


class shopping {
private:
	string pname;
	double price, dis;
	int pcode;
	bool loop = 1;

public:
	shopping() : pname(" "), price(0.f), dis(0.f), pcode(0) {}
	void menu();
	void administrator();
	void edit();
	void add();
	void rem();
	void buyer();
	void list();
	void reciept();
};
