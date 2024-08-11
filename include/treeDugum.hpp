#ifndef treeDugum_hpp
#define treeDugum_hpp
#include "treeDugum.hpp"
class treeDugum
{
public:
    treeDugum(int veri);
    int veri;
    treeDugum* sol;
    treeDugum* sag;
    treeDugum* sonraki;
};

#endif