#include "funcitons.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void vector_with_size(vector <int> &v1,int n){
    int input,choice;

    cout << "For Input Press 1." << endl << "For Print press 0" << endl ;
    cin >> choice;
    
    if(choice == 1){
        cout << "Please enter your element of vector" << endl;
        for (int  i = 0; i < n; i++){
            cin >> input;
            v1.push_back(input);
        }
    }
    
    if(choice == 0){
        for (auto i : v1){
            cout << "Element Vektora : " << i << endl;
        }
    }
}


void printing_vectors(vector <int> &v2, int gg ,int dg){
    int inputa;
    for (int i = 0;; i++)
    {
        cin >> inputa ;

        if (inputa < dg)
            break;
        else if(inputa > gg)
            break;
        else{
            v2.push_back(inputa);
        }
    }
    for (auto i : v2){
        cout << "Element Vektora : " << i << endl;
    }
}

void delete_element (vector <int> &v2, int indeks){
    swap(v2[indeks],v2[v2.size()-1]);
    v2.pop_back();
}

void repeating_substring(string &str1,string &str2,int &n){
    int position = 0;

    while ( (position = str1.find(str2,position)) != std::string::npos)
    {
        ++n;
        position += str2.length();
    }
}

void string_reversing_and_sorting(vector <string> &vstring){
    cout << "Please enter your strings.Type 'exit' for finish" << endl;
    bool x = true;
    string str1;

    while(x == true){

        cin >> str1;
        if (str1 == "exit"){
            x = false;
        }
        reverse(str1.begin(),str1.end());
        vstring.push_back(str1);

    }
    vstring.pop_back();
    sort(vstring.begin(),vstring.end());

    cout << "printing vector: " << endl;

    for (auto i : vstring){
        cout << "Element of vector: " << i << endl;
    }
    
}