#ifndef CUSTOMSTACK_H_INCLUDED
#define CUSTOMSTACK_H_INCLUDED
#include <iostream>
#include <string.h>
#include "node.h"


using namespace std;
const string empty_except="Stos jest pusty.";

//Szablon klasy stosu
template<class T>
class Customstack
{
private:
    class Node<T>* last_node; //Wskaznik na ostatni wezel stosu

    int sizeofstack; //rozmiar stosu

public:

    Customstack() : sizeofstack(0) //konstruktor klasy
    {
        last_node=NULL;
    }

    ~Customstack() //destruktor klasy
    {
        Node<T> *temp=last_node;
        while(last_node!=NULL) //dopoki ostatni wezel nie wskazuje wskaznik zerowy
        {
            temp=temp->prev_ptr();
            delete last_node; //usuwanie wezlow stosu
            last_node=temp;
        }
    }

    void operator+=(T data); //Metoda dodajaca element na stos

    T operator--(); //Metoda usuwajaca element ze stosu

    T last_data() const { return last_node->get_data(); } //funkcja zwracajaca wartosc ostatniego elementu stosu

    bool isempty() const { return sizeofstack==0; } //Metoda sprawdzajaca, czy stos jest pusty

    int what_size() const { return sizeofstack; } //Metoda zwracajaca liczbe elementow stosu

    friend bool operator==(const Customstack<T> &stack1, const Customstack<T> &stack2) //Metoda porownujaca dwa stosy
    {
        if(stack1.what_size()!=stack2.what_size()) return false;
        Node<T> *temp1=stack1.last_node; //tymczasowy wskaznik na wezly stosu 1.
        Node<T> *temp2=stack2.last_node; //tymczasowy wskaznik na wezly stosu 2.
        while(temp1!=NULL)
        {
            if (temp1->get_data()!=temp2->get_data()) return false; //jezeli dane w odpowiednich wezlach w obu stosach sa rozne
            temp1=temp1->prev_ptr(); //przejscie do poprzedniego elementu
            temp2=temp2->prev_ptr(); //przejscie do poprzedniego elementu
        }
        return true;
    }


    friend bool operator!=(const Customstack<T> &stack1, const Customstack<T> &stack2) //Metoda porownujaca, czy stosy sa rozne
    {
        return !(stack1==stack2);
    }

    friend ostream& operator<<(ostream& out, const Customstack<T> &st) //Metoda wypisujaca stos
    {
        if (st.isempty()) throw empty_except;
        Node<T> *temp=st.last_node;
        while(temp!=NULL)
        {
            out << temp->get_data() << "; ";
            temp=temp->prev_ptr();
        }
        out << endl;
        return out;
    }

};

template<class T>
void Customstack<T>::operator+=(T data)
{
    if(!(last_node=new Node<T>(last_node, data))) //jezeli nie uda sie zajac miejsca w pamieci dla nowego wezla
    {
        string error="Nie udalo sie dodac elementu";
        throw error;
    }
    ++sizeofstack; //zwiekszenie rozmiar stosu
}


template<class T>
T Customstack<T>::operator--()
{
    if (isempty()) throw empty_except; //jezeli stos jest pusty, wywolaj wyjatek
    Node<T> *temp_ptr=last_node; //tymczasowy wskaznik na ostatni wezel
    T temp=last_node->get_data(); //dane z ostatniego elementu stosu
    last_node=last_node->prev_ptr(); //ustawienie ostatniego wezla na poprzedni element
    delete temp_ptr; //usuniecie wezla zawierajacego ostatni element
    --sizeofstack;
    return temp;
}

#endif // CUSTOMSTACK_H_INCLUDED
