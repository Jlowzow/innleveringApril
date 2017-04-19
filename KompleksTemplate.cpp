#include "kompleks.h"
#include "TemplateSort.cpp"
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

	diverse<Kompleks> d;

	for(int i = 0; i < 5; i++){
		d.tabell[i]=lag();
	}

	d.sorter();

	for(int i = 0; i < 5; i++){
		cout << d.tabell[i] << endl;
	}

	return 0;
}
