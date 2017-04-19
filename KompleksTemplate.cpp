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
