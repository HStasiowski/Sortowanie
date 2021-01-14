#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sortowanieGnoma(int* lista, int n)
{
    int start = 0;
    int koniec = 0;
    while (start < n)
    {
        if (start == 0 || lista[start] >= lista[start - 1])
        {
            start = koniec + 1;
            koniec = start;
        }
        else
        {
            swap(lista[start], lista[start - 1]);
            start = start - 1;
        }
    }
}
void kopcowanie(int* tab, int n, int i)
{
    int najwiekszy = i; // najwiekszy korzen
    int l = 2 * i + 1; // l=lewe dziecko
    int p = 2 * i + 2; // p=prawe dziecko


    if (l < n && tab[l] > tab[najwiekszy])
        najwiekszy = l;


    if (p < n && tab[p] > tab[najwiekszy])
        najwiekszy = p;


    if (najwiekszy != i)
    {
        swap(tab[i], tab[najwiekszy]); //jezeli najwieksze nie jest korzeniem

        kopcowanie(tab, n, najwiekszy);
    }

}
void sortowanieKopcowe(int* tab, int n)
{
    // zmiana tablicy
    for (int i = n / 2 - 1; i >= 0; i--)
        kopcowanie(tab, n, i);


    for (int i = n - 1; i > 0; i--)
    {

        swap(tab[0], tab[i]); //przesuniecie najwiekszego korzenia na koniec

        kopcowanie(tab, i, 0); //usuniecie najwiekszego korzenia
    }
}
void wyswietlTablice(int* tab, int n)
{
    for (int i = 0; i < n; ++i)
        cout << tab[i] << " ";
    cout << "\n";
}
void losowanie_tablicy(int* lista, int n)
{
     n=10000;
     lista = new int[n];
    srand((unsigned)time(NULL));
    for ( int i = 0; i < n; i++)
        lista[i]=(rand()%100+1);
}

int main()
{
    // Problem jest tutaj, wyzej zrobilem osobną funckje na losowanie tablicy
    // tylko teraz gdy chce ja wywolac to lista nie jest zadeklarowana w mainie i
    // nie wiem czy mam ja jeszcze raz deklarowac, czy jest inne rozwiazanie?


    losowanie_tablicy(lista,n)
    int* kopialisty = new int[n];
     for (int i = 0; i < n; i++)
    {
     kopialisty[i]=lista[i];
     }

    //copy
    sortowanieGnoma(lista, n);
    cout << "Posortowana lista to:\n";
    for (int i = 0; i < n; i++)
        cout << lista[i] << " ";
    delete lista;
    system("pause");

// int tab[] = { 12, 11, 13, 5, 6, 7, };
    // int n = sizeof(tab) / sizeof(tab[0]);

    // sortowanieKopcowe(tab, n);

    // cout << "Posortowana tablica to: \n";
    // wyswietlTablice(tab, n);



    return 0;
}
