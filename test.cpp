#include "fartoy.h"

using namespace std;

int main(){
	rederi f;
	f.settNavn("Fjord1");
	f.settTlf("57505050");

	snoggbot s;
	snoggbot s1;
	s.settRederi(f);
	s.settNavn("Varg");
	s.settSign("WM072");
	s.settPass(450);
	s.skrivUt();
	s1.skrivUt();
	return 0;
}
