
#include "Yigin.hpp"

Yigin::Yigin() {
    tepe = nullptr;
}

void Yigin::ekleyigin(int veri) {
    stackDugum* yeni = new stackDugum(veri);
    if (tepe != nullptr)
        yeni->sonraki = tepe;
    tepe = yeni;
}

int Yigin::tepesil() 
{
    if (tepe != nullptr)
    {
        stackDugum* silinecek = tepe;
        tepe = tepe->sonraki;
        int x = silinecek->veri;
        delete silinecek;
        silinecek = nullptr;
        return x;
    }
    return -1;
}



int Yigin::peek() {
    return tepe->veri;
}

bool Yigin::stackbos() {
    return (tepe == nullptr);
}

void Yigin::silBosYiginlar() {
    while (!stackbos()) {
        tepesil();
    }
}