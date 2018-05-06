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

#endif // TEST_TYPE_H_INCLUDED
