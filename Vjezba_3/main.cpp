#include "funcitons.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main()
{
	int n,gg,dg,k=0;

	vector <string> vstring;

	string_reversing_and_sorting(vstring);

	string str1 = "abcdecdecd"; //cd x3
	string substr = "cd";
	int repeated=0;
	repeating_substring(str1,substr,repeated);


	cout << "broj ponavljanja: " << repeated << endl;

	cout << "How much elements do we want in vector" << endl;
	cin >> n;

	cout << "Enter Lower limit"<< endl;
	cin >> dg;

	cout << "Enter Higher limit"<< endl;
	cin >> gg; 

	vector <int> v1;
	vector <int> v2;
	
	//printing_vectors(v2,gg,dg);

	vector <int> new_1,new_2,new_3;
	cout << "Enter new_1 elements " << endl;
	vector_with_size(new_1,n);
	cout << "Enter new_2 elements " << endl;
	vector_with_size(new_2,n);

	for(int i = 0 ; i < new_1.size() ; i++){
		int counter = 0;
		for (int j = 0 ; j < new_2.size() ; j++){
			if(new_1[i] != new_2[j]){
				counter++;
				if(counter == (new_2.size())){
					new_3.push_back(new_1[i]);
					k++;
				}
			}
		}
	}
	vector <int>::iterator it = new_3.begin();

	cout << "Print new_3 vector" << endl;
	
	sort(new_3.begin(),new_3.end());
	int sum = accumulate(new_3.begin(),new_3.end(),0);

	new_3.insert(it,0);
	new_3.push_back(sum);
	vector_with_size(new_3,new_3.size());

	int indeks;
	cout << "Delete: Enter index of element " << endl;
	cin >> indeks;
	delete_element(new_2,indeks);

	vector_with_size(new_2,new_2.size());


}