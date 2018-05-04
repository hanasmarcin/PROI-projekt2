#ifndef CUSTOMSTACK_H_INCLUDED
#define CUSTOMSTACK_H_INCLUDED
#include <iostream>
#include <string.h>
#include "node.h"


using namespace std;
const string empty_except="Stos jest pusty.";


template<class T> class Customstack;
template<class T> ostream& operator<<(ostream& out, const Customstack<T> &st);

template<class T>
class Customstack
{
private:
    class Node<T>* last_node;

    int sizeofstack;

    T last_data() const { return last_node->get_data(); }
public:

    Customstack() : sizeofstack(0)
    {
        last_node=NULL;
    }

    ~Customstack()
    {
        Node<T> *temp=last_node;
        while(last_node!=NULL)
        {
            temp=temp->prev_ptr();
            delete last_node;
            last_node=temp;
        }
    }

    void operator+=(T data);

    T& operator--();

    bool isempty() const { return sizeofstack==0; }

    int what_size() const { return sizeofstack; }

    friend bool operator==(const Customstack<T> &stack1, const Customstack<T> &stack2)
    {
        if(stack1.what_size()!=stack2.what_size()) return false;
        Node<T> *temp1=stack1.last_node;
        Node<T> *temp2=stack2.last_node;
        while(temp1!=NULL)
        {
            if (temp1->get_data()!=temp2->get_data()) return false;
            temp1=temp1->prev_ptr();
            temp2=temp2->prev_ptr();
        }
        return true;
    }


    friend bool operator!=(const Customstack<T> &stack1, const Customstack<T> &stack2)
    {
        return !(stack1==stack2);
    }

    friend ostream& operator<<(ostream& out, const Customstack<T> &st)
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
    if(!(last_node=new Node<T>(last_node, data)))
    {
        string error="Nie udalo sie dodac elementu";
        throw error;
    }
    ++sizeofstack;
}


template<class T>
T& Customstack<T>::operator--()
{
    if (isempty()) throw empty_except;
    Node<T> *temp_ptr=last_node;
    T temp=last_node->get_data();
    last_node=last_node->prev_ptr();
    delete temp_ptr;
    --sizeofstack;
    return temp;
}

#endif // CUSTOMSTACK_H_INCLUDED
