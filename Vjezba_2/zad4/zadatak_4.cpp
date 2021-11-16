# include <iostream>
# include <iomanip>

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
    vektor neki_vektor;
    neki_vektor.vector_new(3);
}