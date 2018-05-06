#include <iostream>
#include "Customstack.h"
#include "test_double.h"
#include "test_type.h"

int main()
{
    testing_double t_double;
    testing_type t_type;
    type a(2, 'c', 3.45);

    //Wywolywanie metod klasy testujacej dla typu double
    t_double.push_pop(3.456);
    t_double.isempty(true);
    t_double.isempty(false);
    t_double.what_size(5);
    t_double.same(true);
    t_double.same(false);
    t_double.different(true);
    t_double.different(false);

    //Wywolywanie metod klasy testujacej dla typu type
    t_type.push_pop(a);
    t_type.isempty(true);
    t_type.isempty(false);
    t_type.what_size(5);
    t_type.same(true);
    t_type.same(false);
    t_type.different(true);
    t_type.different(false);

    return 0;
}


