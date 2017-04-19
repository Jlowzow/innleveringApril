#include "kompleks.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

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

	int x;
	cout << "skriv tall: ";
	cin >> x;
	cout << endl;

	vector<Kompleks> v;


	for(int i = 0; i < x; i++){
	v.push_back(lag());
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < x; i++){
	SkrivUt(v[i]);
	}


	return 0;
}
