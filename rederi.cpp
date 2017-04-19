//rederi.cpp

#include "rederi.h"
using namespace std;


rederi::rederi(){
	navn = "";
	tlf = "";
}

void rederi::settNavn(string a){
	navn = a;
}

void rederi::settTlf(string a){
	tlf = a;
}

string rederi::finnNavn() const{
	return navn;
}

string rederi::finnTlf() const{
	return tlf;
}
