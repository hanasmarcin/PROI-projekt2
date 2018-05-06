#include "test_double.h"

using namespace std;

//Definicje metod klasy testujacej dla typu double

//Test dodawania i usuwania elementow
bool testing_double::push_pop(double data)
{
    Customstack<double> c;
    double result;

    cout << "TEST DODAWANIA I USUWANIA ELEMENTOW" << endl;
    cout << "Dodawane dane: ";
    cout << data << endl;
    try
    {
        c+=data; //dodawanie elementu do stosu
        cout << "Poprawnie dodano element, nowy stos: ";
        cout << c; //wypisywanie stosu
        result=--c; //usuwanie elementu ze stosu
        if (result==data) cout << "Poprawnie usunieto element" << endl << endl;
    }
    catch(string w) //gdy pojawil sie wyjatek w funkcji usuwania elementu (gdy stos byl pusty)
    {
        cout<<"Wyjatek: "<<w << endl;
        return false;
    }
    return true;

}

//Test metody isempty()
bool testing_double::isempty (bool agree)
{
    cout << "TEST METODY isempty()" << endl;

    Customstack<double> c;
    double data=3.4543;
    if (agree)
    {
        cout << "Stos powinien byc pusty" << endl;
        cout << "Czy stos jest pusty: " << boolalpha << c.isempty() << endl << endl;
    }
    else
    {
        c+=data;
        cout << "Stos powinien nie byc pusty" << endl;
        cout << "Czy stos jest pusty: " << c.isempty() << endl << endl;
    }
    if(c.isempty()==agree) return true; //jezeli funkcja zwrocila wartosc zgodna z oczekiwana
    else return false;
}

//Test metody what_size()
bool testing_double::what_size (int howmany)
{
    cout << "TEST METODY what_size()" << endl;

    Customstack<double> c;
    double data=5.235;
    for (int i=0; i<howmany; i++) //dodawanie tylu elementow, ile okreslono w argumencie
    {
        c+=data;
    }
    cout << "Na stos dodano " << howmany << " elementow." << endl;
    cout << "Metoda zwrocila: " << c.what_size() << endl << endl;
    if (c.what_size()==howmany) return true;
    else return false;

}

//Test metody porownania
bool testing_double::same (bool agree)
{
    cout << "TEST POROWNANIA, czy takie same" << endl;

    Customstack<double> c, d;
    double data1=5.235;
    double data2=3.34;
    double data3=434.2;

    c+=data1;
    d+=data1;

    if(agree)
    {
        cout << "Stosy powinny byc takie same" << endl;
        cout << "Czy stosy sa takie same: " << boolalpha << (c==d) << endl << endl;
    }
    else
    {
        c+=data2;
        d+=data3;
        cout << "Stosy nie powinny byc takie same" << endl;
        cout << "Czy stosy sa takie same: " << boolalpha << (c==d) << endl << endl;
    }

    if (agree==(c==d)) return true;
    else return false;

}

//Test sprawdzania, czy rozne
bool testing_double::different (bool agree)
{
    cout << "TEST POROWNANIA, czy rozne" << endl;

    Customstack<double> c, d;
    double data1=6.3456;
    double data2=6.344;
    double data3=498422.2;

    c+=data1;
    d+=data1;

    if(!agree)
    {
        cout << "Stosy nie powinny byc rozne" << endl;
        cout << "Czy stosy sa rozne: " << boolalpha << (c!=d) << endl << endl;
    }
    else
    {
        c+=data2;
        d+=data3;
        cout << "Stosy powinne byc rozne" << endl;
        cout << "Czy stosy sa rozne: " << boolalpha << (c!=d) << endl << endl;
    }

    if (agree==(c!=d)) return true;
    else return false;

}
