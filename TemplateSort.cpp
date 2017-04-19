
#include <iostream>
using namespace std;

const int N=5;
template <class A_Type> class diverse
{
	
  public:
    void sorter();
	A_Type tabell[N]; //Definerer public for å sleppe bruke tilgangsfunksjonar
private:
	void Byttom(A_Type &x, A_Type &y);//Berre til bruk i implementeringa, kunne brukt protected
};
template <class A_Type> void diverse<A_Type>::sorter()
{
	for(int i=0;i<N-1;i++)
		for (int j=i+1;j<N;j++)
			if(tabell[j]<tabell[i])
				Byttom(tabell[i],tabell[j]);
}

template <class A_Type> void diverse<A_Type>::Byttom(A_Type &x, A_Type &y)
{
	A_Type hjelp=x;
	x=y;
	y=hjelp;
}
