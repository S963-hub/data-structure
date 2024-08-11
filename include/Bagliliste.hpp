#ifndef Bagliliste_hpp
#define Bagliliste_hpp
#include "AVLAgaci.hpp"
#include "Dugum.hpp"
class Bagliliste
{
public:
    Dugum* ilk;
  void YazdirSonKalan();
    Bagliliste();
    void ekleBagliliste(AVLAgaci* veri);
    void cikar(AVLAgaci* veri);
    void Deleteminmax();
    int returncount();
    void Yazdir();
    void tekrarver2();
    int sonKalanAgacNumarasiSil();
    int sonKalanAgacNumarasi();


    AVLAgaci* ilkdondur();
    bool arama(AVLAgaci* veri);
  //  void returnchar();

};

#endif