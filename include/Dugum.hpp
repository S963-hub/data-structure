#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
#include "AVLAgaci.hpp"


class Dugum
{
public:
    Dugum(AVLAgaci *veri);

    AVLAgaci* veri;          

    /*
    stack
    toplam
    ASCII
    */
    Dugum* sonraki;
   
   // Dugum* Yigin;
};

#endif