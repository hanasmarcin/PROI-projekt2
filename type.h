#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED
#include <iostream>

using namespace std;

//Wlasny typ skladajacy sie z identyfikatora - liczby calkowitej, literowego oznaczenia grupy i sredniej typu double
class type
{
private:
    int id;
    char group_id;
    double average;
public:

    type(int t_id, char t_group_id, double t_average)
    : id(t_id), group_id(t_group_id), average(t_average) {}

    type()
    : id(0), group_id('#'), average(0) {}

    friend bool operator==(const class type &t1, const class type &t2)
    {
        if ((t1.id==t2.id && t1.group_id==t2.group_id) && t1.average==t2.average) return true;
        else return false;
    }

    friend bool operator!=(const class type &t1, const class type &t2)
    {
        if ((t1.id!=t2.id || t1.group_id!=t2.group_id) || t1.average!=t2.average) return true;
        else return false;
    }


    friend ostream& operator<<(ostream& out, const class type &t)
    {
        out << t.id << ". group " << t.group_id << " - " << t.average;
        return out;
    }


};

#endif // TYPE_H_INCLUDED
