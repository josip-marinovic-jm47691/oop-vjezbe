# include <iostream>
# include <iomanip>

struct kruznica {
        int promjer;
    }typedef kruznica;
    
struct pravokutnik {
        int a;
        int b;
    }typedef pravokutnik;

int treci_zadatak(const kruznica& k_kruznica,const pravokutnik (&niz_pravokutnika)[4])
{
    int counter = 0;

    for(int i = 0; i < 4; i++)
    {
        if(k_kruznica.promjer < niz_pravokutnika[i].a)
        {
            counter++;
        }
        else if(k_kruznica.promjer < niz_pravokutnika[i].b)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    kruznica k_kruznica;
    k_kruznica.promjer = 50;

    pravokutnik p_prvi, p_drugi, p_treci, p_cetvrti;
    p_prvi.a = 2;
    p_prvi.b = 7;
    p_drugi.a = 13;
    p_drugi.b = 5;
    p_treci.a = 32;
    p_treci.b = 14;
    p_cetvrti.a = 44;
    p_cetvrti.b = 12;

    const pravokutnik niz_pravokutnika[4] = {p_prvi, p_drugi, p_treci, p_cetvrti};
    for(int i = 0; i < 4; i++)
    {
         std :: cout << "\nJedan trokut ima stranicu a: " << niz_pravokutnika[i].a << " i stranicu b: " << niz_pravokutnika[i].b;
    }

    const kruznica& kruznica_ref = k_kruznica;
    int broj_presjecanja = treci_zadatak(kruznica_ref, niz_pravokutnika);
    std :: cout << "\nBroj presijecanja je: " << broj_presjecanja << "\n";
}