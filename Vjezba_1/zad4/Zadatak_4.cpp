#include <iostream>
using namespace std;

int rekurzija (int niz[],int* minimum,int* maximum,int brojac,int duljina_niza){
	if (brojac == duljina_niza)
		return 0;
	else if(*minimum < niz[brojac]){
		*minimum = niz[brojac];
	}
	if(*maximum > niz[brojac]){
		*maximum = niz[brojac];
	}
	rekurzija(niz,minimum,maximum,brojac+1,duljina_niza);
}

int main() {

	int niz []={9999,1,2,3,4,-1,9,111,1221};
	int duljina= sizeof(niz)/sizeof(niz[0]);
	int brojac = 0;

	int min=niz[0];
	int max=niz[0];

	rekurzija(niz,&min,&max,brojac,duljina);
	
	std::cout << "minimum je: " << min <<endl;
	std::cout << "maximum je: " << max <<endl;
}