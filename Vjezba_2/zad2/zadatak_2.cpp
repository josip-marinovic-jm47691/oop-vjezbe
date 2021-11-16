# include <iostream>
# include <iomanip>

int& drugi_zadatak(int* niz, int element)
{
    return niz[element];
}


int main()
{
    int niz_brojeva[5] = {1,2,2,4,5};
     std :: cout << "Brojevi prije poziva funkcije (2. zadatak): ";
     for(int broj : niz_brojeva){
         std :: cout << broj << " ";
     }
    
     drugi_zadatak(niz_brojeva, 2) += 1;
     std :: cout << "\nBrojevi nakon poziva funkcije (2. zadatak): ";
     for(int broj : niz_brojeva){
         std :: cout << broj << " ";
     }
     std :: cout << "\n";
}