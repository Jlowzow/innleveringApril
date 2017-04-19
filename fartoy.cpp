#include "fartoy.h"
#include <string>
#include <iostream>
using namespace std;
fartoy::fartoy(){
	sign = "signal";
	navn = "fartøynavn";
	reder = rederi();	
}

void fartoy::settSign(string a){
	sign = a;
}

void fartoy::settNavn(string a){
	navn = a;
}
void fartoy::settRederi(rederi a){
	reder = a;
}

string fartoy::finnNavn(){
	return navn;
}
string fartoy::finnSign(){
	return sign;
}
string fartoy::finnRederi(){
	return reder.finnNavn();
}

void snoggbot::skrivUt(){
	cout << "Snøggbåten " << finnNavn() << " med kallesignal " << finnSign() << " tar " <<
		passasjerer << " passasjerer." << endl;
}

void snoggbot::settPass(int i){
	passasjerer = i;
}

snoggbot::snoggbot():fartoy(){
	passasjerer = 2;
}
