#pragma once
#include <string>
#include "rederi.h"
class fartoy{
public:
	fartoy();
	void settSign(std::string a);
	void settNavn(std::string a);
	void settRederi(rederi a);
	std::string finnNavn();
	std::string finnSign();
	std::string finnRederi();
	virtual void skrivUt() = 0;

private:
	std::string sign;
	std::string navn;
	rederi reder;
};

class snoggbot : public fartoy{
public:
	snoggbot();
	void settPass(int);
	void skrivUt();

private:
	int passasjerer;

};
