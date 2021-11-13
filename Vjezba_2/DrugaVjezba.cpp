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


int& drugi_zadatak(int* niz, int element)
{
    return niz[element];
}


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


struct vektor {
        int counter = 0;
        int velicina_niza = 0; // logicka velicina
        int* elementi;         // fizicka

        vektor vector_new(int n);
        void vector_delete(vektor& vektor_brisat);
        void vector_push_back(vektor& vektor_poslani, int element);
        void vector_pop_back(vektor vektor_poslani);
        int& vector_front(vektor vektor_poslani);
        int& vector_back(vektor vektor_poslani);
        int vector_size(vektor vektor_poslani);

    }typedef vektor;

vektor vector_new(int n)
{
    vektor novi_vektor;
    novi_vektor.elementi = new int[n];
    novi_vektor.velicina_niza = n;
    return novi_vektor;
}

void vector_delete(vektor& vektor_brisat)
{
    delete [] vektor_brisat.elementi; 
}

void vector_push_back(vektor& vektor_poslani, int element)
{
    if(vektor_poslani.counter == vektor_poslani.velicina_niza)
    {
        int* novi_elementi = new int[2 * vektor_poslani.velicina_niza];
        for(int i = 0; i < vektor_poslani.velicina_niza; i++)
        {
            novi_elementi[i] = vektor_poslani.elementi[i];
        }
        delete [] vektor_poslani.elementi;
        vektor_poslani.elementi = novi_elementi;
    }
    vektor_poslani.elementi[vektor_poslani.counter] = element;
    vektor_poslani.counter += 1;
}

void vector_pop_back(vektor vektor_poslani)
{
    if(vektor_poslani.counter > 0)
    {
        // vektor_poslani.elementi[vektor_poslani.counter] = 0;
        vektor_poslani.counter -= 1;
    }
}

int& vector_front(vektor vektor_poslani)
{
    if(vektor_poslani.counter > 0)
    {
        int& prvi = vektor_poslani.elementi[0];
        return prvi;
    }
}

int& vector_back(vektor vektor_poslani)
{
    if(vektor_poslani.counter > 0)
    {
        int& zadnji = vektor_poslani.elementi[vektor_poslani.counter - 1];
        return zadnji;
    }
}

int vector_size(vektor vektor_poslani)
{
    return vektor_poslani.counter;
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


     vektor neki_vektor;
     neki_vektor.vector_new(3);

    
}