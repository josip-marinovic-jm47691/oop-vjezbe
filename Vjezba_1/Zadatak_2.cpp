#include <iostream>
using namespace std;
#include <time.h>
#include <iomanip>


struct Matrica
{

	float **matrica;
	int red,stupac ;

	void alokacija_matrice_mxn(int redak,int stupac){

		this->red = redak;
		this->stupac = stupac;

		matrica = new float* [red];
		for (int i = 0 ;i < redak;i++){
			//alc za stupce
			matrica[i]=new float [stupac];
		}
	}

	void dealokacija_matrice(){
		for(int i = 0; i < red; i++)
			delete [] matrica[i];
		delete [] matrica;
	}

	void gen_matrice_u_raspodnu_a_b(float raspon_min,float raspon_max){
		for (int i = 0; i < red; i++){
			for (int j = 0; j < this->stupac; j++){
				matrica[i][j] = raspon_min + (float)rand() / (float)RAND_MAX*(raspon_max-raspon_min);
			}
		}
	}

	void printanje_matrice(){
		for (int i = 0; i < red; i++){
			for (int j= 0; j < stupac; j++){
				std::cout << right << fixed <<  setprecision(4) << matrica[i][j]<<"\t";
			}
			std::cout<<"\n"<<endl;
		}
	}

	void transponiranje_matrice(Matrica matrica_primljena_argument){

		alokacija_matrice_mxn(matrica_primljena_argument.stupac, matrica_primljena_argument.red);
		for(int i = 0; i < stupac; i++){
			for(int j = 0; j < red; j++){
				matrica[j][i]=matrica_primljena_argument.matrica[i][j];
			}
		}
	}

	void zbrajanje_matrice(Matrica matrica_1,Matrica matrica_2){
		if(matrica_1.red == matrica_2.red and matrica_1.stupac == matrica_2.stupac){
			alokacija_matrice_mxn(matrica_1.red,matrica_1.stupac);

			for (int i = 0; i < red; i++){
				for (int j = 0; j < stupac; j++){
					matrica[i][j] = matrica_1.matrica[i][j] + matrica_2.matrica[i][j];
				}	
			}
		}else{
			std::cout<<"Operacija nije dozvoljena"<<endl;
		}
	};

	void oduzimanje_matrice(Matrica matrica_1,Matrica matrica_2){
		if(matrica_1.red == matrica_2.red and matrica_1.stupac == matrica_2.stupac){
			alokacija_matrice_mxn(matrica_1.red,matrica_1.stupac);

			for (int i = 0; i < red; i++){
				for (int j = 0; j < stupac; j++){
					matrica[i][j] = matrica_1.matrica[i][j] - matrica_2.matrica[i][j];
				}	
			}
		}else{
			std::cout<<"Operacija nije dozvoljena"<<endl;
		}
	};

	void mnozenje_matrice(Matrica matrica_1, Matrica matrica_2){
		if (matrica_1.red == matrica_2.red and matrica_1.stupac==matrica_2.stupac)
		{
			alokacija_matrice_mxn(matrica_1.red,matrica_2.stupac);
			

			for(int i = 0; i < matrica_1.red; ++i){
        		for(int j = 0; j <matrica_2.stupac; ++j)
        		{
            		matrica[i][j]=0;
        		}
			}
			

			for (int i = 0; i < matrica_1.red; i++){
				for (int j = 0; j < matrica_2.stupac; j++){
					for (int k = 0; k < matrica_2.stupac; k++){
						matrica[i][j] += matrica_1.matrica[i][k] * matrica_2.matrica[k][j];
					}
				}
			}
		}else{
			std::cout<<"Operacija nije dozvoljena"<<endl;	
		}
		
	};

};


int main()
{
int redak,stupac,raspon_min,raspon_max;
srand((unsigned)time(NULL));

std::cout << "Redci matrice - m od  (mxn)" << endl;
cin >> redak;
std::cout << "Stupci matrice - n od (mxn)" << endl;
cin >> stupac ;
std::cout << "Raspon A i B za generiranje matrice u rasponu" << endl ;
std::cout << "Prvo MINIMUM zatim MAXIMUM" << endl ;
cin>> raspon_min >> raspon_max ;
std::cout << "\n" << endl ;

Matrica prvamatrica;

std::cout << "Printanje generirane matrice" <<endl;
prvamatrica.alokacija_matrice_mxn(redak,stupac);
prvamatrica.gen_matrice_u_raspodnu_a_b(raspon_min,raspon_max);
prvamatrica.printanje_matrice();
prvamatrica.dealokacija_matrice();


Matrica generirana_za_transponiranje,transponirana_matrica;

std::cout << "Printanje generirane za transponiranje " <<endl;
generirana_za_transponiranje.alokacija_matrice_mxn(redak,stupac);
generirana_za_transponiranje.gen_matrice_u_raspodnu_a_b(raspon_min,raspon_max);
transponirana_matrica.transponiranje_matrice(generirana_za_transponiranje);
generirana_za_transponiranje.printanje_matrice();
std::cout << "Printanje transponirane matrice" <<endl;
transponirana_matrica.printanje_matrice();


Matrica mat_za_racunske_operacije_1,mat_za_racunske_operacije_2,matrica_rezultat;

mat_za_racunske_operacije_1.alokacija_matrice_mxn(redak,stupac);
mat_za_racunske_operacije_2.alokacija_matrice_mxn(redak,stupac);
mat_za_racunske_operacije_1.gen_matrice_u_raspodnu_a_b(raspon_min,raspon_max);
mat_za_racunske_operacije_2.gen_matrice_u_raspodnu_a_b(raspon_min,raspon_max);

std::cout<< "Matrica 1 za zbrajanje" <<  endl;
mat_za_racunske_operacije_1.printanje_matrice();
std::cout<< "Matrica 2 za zbrajanje"<< endl;
mat_za_racunske_operacije_2.printanje_matrice();
matrica_rezultat.zbrajanje_matrice(mat_za_racunske_operacije_1,mat_za_racunske_operacije_2);
std::cout<< "Printanje matrice rezultat" << endl;
matrica_rezultat.printanje_matrice();
matrica_rezultat.dealokacija_matrice();


std::cout<< "Matrica 1 za oduzimanje" <<  endl;
mat_za_racunske_operacije_1.printanje_matrice();
std::cout<< "Matrica 2 za oduzimanje"<< endl;
mat_za_racunske_operacije_2.printanje_matrice();
matrica_rezultat.oduzimanje_matrice(mat_za_racunske_operacije_1,mat_za_racunske_operacije_2);
std::cout<< "Printanje matrice rezultat oduzimanja" << endl;
matrica_rezultat.printanje_matrice();
matrica_rezultat.dealokacija_matrice();


std::cout<<"Množenje matrice"<<endl;
matrica_rezultat.mnozenje_matrice(mat_za_racunske_operacije_1,mat_za_racunske_operacije_2);
matrica_rezultat.printanje_matrice();
matrica_rezultat.dealokacija_matrice();

mat_za_racunske_operacije_1.dealokacija_matrice();
mat_za_racunske_operacije_2.dealokacija_matrice();

}