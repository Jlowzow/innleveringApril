#include "kompleks.h"
#include <string>
#include <iostream>

Kompleks lag(){
	Kompleks k;
	cout << "Skriv real-del og img-del separert med mellomrom:" << endl;
	cout << ": ";
	cin >> k;
	return k;
}

void SkrivUt(Kompleks k){
	cout << k.finnRealdel() << " + i" << k.finnImagdel() << endl;
}

void byttom(Kompleks &a, Kompleks &b){
	Kompleks tmp = a;
	a = b;
	b = tmp;
}

void sorter(Kompleks * a, int n){
	for( int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(a[i] < a[j]) byttom(a[i], a[j]);
		}
	}
}

int main(){

	cout << "skriv inn hvor mange komplese tall: ";

	int * z = new int;
	cin >> *z;

	Kompleks * a = new Kompleks[*z];


	for(int i = 0; i < *z; i++){
	a[i] = lag();
	}

	for(int i = 0; i < *z; i++){
	SkrivUt(a[i]);
	}

	sorter(a, *z);

	for(int i = 0; i < *z; i++){
	SkrivUt(a[i]);
	}

	return 0;
}
