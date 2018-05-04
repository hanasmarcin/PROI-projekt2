#ifndef TEST_TYPE_H_INCLUDED
#define TEST_TYPE_H_INCLUDED
#include "Customstack.h"
#include "type.h"

class testing_type{
public:
    bool push_pop (class type data);
    bool isempty (bool agree);
    bool what_size (int howmany);
    bool same (bool agree);
    bool different (bool agree);
};


using namespace std;

bool testing_type::push_pop(type data)
{
    Customstack<type> c;
    type result;

    cout << "TEST DODAWANIA I USUWANIA ELEMENTOW" << endl;
    cout << "Dodawane dane: ";
    cout << data << endl;
    try
    {
        c+=data;
        cout << "Poprawnie dodano element, nowy stos: ";
        cout << c;
        result=--c;
        if (result==data) cout << "Poprawnie usunieto element" << endl << endl;
    }
    catch(string w)
    {
        cout<<"Wyjatek: "<<w << endl;
        return false;
    }
    return true;

}


bool testing_type::isempty (bool agree)
{
    cout << "TEST METODY isempty()" << endl;

    Customstack<type> c;
    type data(5, 'g', 5.44);
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
    if(c.isempty()==agree) return true;
    else return false;
}

bool testing_type::what_size (int howmany)
{
    cout << "TEST METODY what_size()" << endl;

    Customstack<type> c;
    type data(4, 'h', 2.54);
    for (int i=0; i<howmany; i++)
    {
        c+=data;
    }
    cout << "Na stos dodano " << howmany << " elementow." << endl;
    cout << "Metoda zwrocila: " << c.what_size() << endl << endl;
    if (c.what_size()==howmany) return true;
    else return false;

}


bool testing_type::same (bool agree)
{
    cout << "TEST POROWNANIA, czy takie same" << endl;

    Customstack<type> c, d;
    type data1(2, 'a', 4.3);
    type data2(2, 'b', 5.3);
    type data3(4, 'e', 2.65);

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

bool testing_type::different (bool agree)
{
    cout << "TEST POROWNANIA, czy rozne" << endl;

    Customstack<type> c, d;
    type data1(2, 'a', 4.3);
    type data2(2, 'b', 5.3);
    type data3(4, 'e', 2.65);

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


#endif // TEST_TYPE_H_INCLUDED
