#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

using namespace std;

template<class T>
class Node
{
    const T data;
    Node *prev;

public:
    Node(Node<T> *last, T new_data) : data(new_data), prev(last) {}

    Node* prev_ptr() { return prev; }

    T get_data()
    {
        return data;
    }

};



#endif // NODE_H_INCLUDED
