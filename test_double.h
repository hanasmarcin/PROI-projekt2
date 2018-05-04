#ifndef TEST_DOUBLE_H_INCLUDED
#define TEST_DOUBLE_H_INCLUDED
#include "Customstack.h"

class testing_double{
public:
    bool push_pop (double data);
    bool isempty (bool agree);
    bool what_size (int howmany);
    bool same (bool agree);
    bool different (bool agree);
};

#endif // TEST_DOUBLE_H_INCLUDED
