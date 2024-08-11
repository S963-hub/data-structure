// Yigin.hpp

#ifndef YIGIN_HPP
#define YIGIN_HPP

#include "stackDugum.hpp"
#include<iostream>
#include<exception>

class Yigin {
public:
    Yigin();
    void ekleyigin(int veri);
    int tepesil();
    void goruntuleme();
    int peek();
    bool stackbos();
    void silBosYiginlar(); // Eklenen fonksiyon
	

private:
    stackDugum* tepe;
};

#endif