#include <iostream>
using namespace std;

int prepravljeno_2u1(int niz[],int duljina_niza,int* pointer_na_min,int* pointer_na_max){

	for (int i = 0; i < duljina_niza; i++)
		{
			if (*pointer_na_max < niz[i]){
				*pointer_na_max=niz[i];
			}
		};

	for (int i = 0; i < duljina_niza; i++)
		{
			if (*pointer_na_min > niz[i]){
			*pointer_na_min=niz[i];
			}
		};
}


int main()
{
	int niz[] = {7,1133,22,2222,11,55,2021,-2012};
	int duljina_niza = sizeof(niz) / sizeof(niz[0]);

	int minimum = niz[0];
	int maximum = niz[0];

	prepravljeno_2u1(niz,duljina_niza,&minimum,&maximum);

	std::cout<<maximum<<endl;
	std::cout<<minimum<<endl;

	
}