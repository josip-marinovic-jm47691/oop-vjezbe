# include <iostream>
# include <iomanip>

void prvi_zadatak(int* niz, int& manji, int&veci, int n)
{

    manji = niz[0];
    veci = niz[0];

    for(int i = 0; i < n; i++)
    {
        if(niz[i] < manji)
        {
            manji = niz[i];
        }
        if(niz[i] > veci)
        {
            veci = niz[i];
        }
    }
}

int main()
{
    int brojevi[] = {1,2,3,4,5};
    int n;
    int manji;
    int veci;

    n = sizeof(brojevi) / sizeof(brojevi[0]);

    int& manji_ref = manji;
    int& veci_ref = veci;
    prvi_zadatak(brojevi, manji_ref, veci_ref, n);

    std :: cout << "Manji je " << manji << " a veci je " << veci;
}