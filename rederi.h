//rederi.h
#pragma once
#include <string>
#include <iostream>
using namespace std;
class rederi{
public:
	rederi(); //Konstruktør utan argument
	void settNavn(string);
	void settTlf(string);
	string finnNavn() const;
	string finnTlf() const;
private:
	string navn;
	string tlf;
};
