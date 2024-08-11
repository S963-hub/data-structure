#include "AVLAgaci.hpp"
#include "Yigin.hpp"
#include <cmath>
#include <iomanip>
#include "treeDugum.hpp"
#include<iostream>
#include<queue>
#include<string>
using namespace std;
AVLAgaci::AVLAgaci()
{ 
    dondurulenler = new Yigin();
    yiginagac = new Yigin();
   
    kok= nullptr;
    toplam=0;
    agacindex =0;
    
}
AVLAgaci::~AVLAgaci()
{
    delete dondurulenler;
    delete yiginagac;
}
bool AVLAgaci::varmi(int veri) 
{
    varmi(veri,kok);
}
void AVLAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}
void AVLAgaci::sil(int veri) 
{
	kok = sil(veri,kok);
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}
void AVLAgaci::postOrder() 
{
	postOrder(kok);
}
void AVLAgaci::postOrder(treeDugum *aktif)
{
    if (aktif == nullptr)
        return;
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        if (aktif->sag==nullptr && aktif->sol==nullptr)
        {
            yiginagac->ekleyigin(aktif->veri);
        }
       
        
    }	
     
}
int AVLAgaci::yukseklik(treeDugum* aktiftreeDugum) 
{
	if(aktiftreeDugum)
    {
        return 1+max(   yukseklik(aktiftreeDugum->sol),
                        yukseklik(aktiftreeDugum->sag));
    }
    return -1;
}
treeDugum* AVLAgaci::ekle(int veri,treeDugum* aktiftreeDugum) 
{
    if(aktiftreeDugum==0)
        return new treeDugum(veri);

	else if(aktiftreeDugum->veri<veri)
    {
        aktiftreeDugum->sag=ekle(veri,aktiftreeDugum->sag);
        if(yukseklik(aktiftreeDugum->sag)-yukseklik(aktiftreeDugum->sol)>1)
        {   
            if(veri>aktiftreeDugum->sag->veri)
                aktiftreeDugum = solaDondur(aktiftreeDugum);
                
            else
            {
                aktiftreeDugum->sag = sagaDondur(aktiftreeDugum->sag);
                aktiftreeDugum =solaDondur(aktiftreeDugum);
            }
        }
    }
    else if(aktiftreeDugum->veri>veri)
    {
        aktiftreeDugum->sol = ekle(veri,aktiftreeDugum->sol);
        if(yukseklik(aktiftreeDugum->sol)-yukseklik(aktiftreeDugum->sag)>1)
        {

            if(veri<aktiftreeDugum->sol->veri)
                aktiftreeDugum = sagaDondur(aktiftreeDugum);
            else
            {
                aktiftreeDugum->sol = solaDondur(aktiftreeDugum->sol);
                aktiftreeDugum =sagaDondur(aktiftreeDugum);
            }
        }

    }
    return aktiftreeDugum;
}
treeDugum* AVLAgaci::solaDondur(treeDugum* buyukEbeveyn) 
{
	treeDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
treeDugum* AVLAgaci::sagaDondur(treeDugum* buyukEbeveyn) 
{
	treeDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int AVLAgaci::maxDeger(treeDugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
bool AVLAgaci::varmi(int aranan, treeDugum *aktif)
{
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}
treeDugum* AVLAgaci::sil(int veri,treeDugum* aktif) 
{
	if(aktif==0)
        return 0;
    
    if(veri<aktif->veri)
    {
        aktif->sol = sil(veri,aktif->sol);
    }
    else if(veri>aktif->veri)
    {
        aktif->sag = sil(veri,aktif->sag);
    }
    else//aradığımız düğümü bulduk
    {
        if(aktif->sol==0&&aktif->sag==0)
        {
            delete aktif;
            aktif= 0;
        }
        else if(aktif->sol==0)
        {
            treeDugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if(aktif->sag==0)
        {
            treeDugum* sil  = aktif->sol;
            *aktif=*aktif->sol;
            delete sil;
        }
        else 
        {
            aktif->veri = minDeger(aktif->sag);
            sil(aktif->veri,aktif->sag);
        }

        
    }
    
int denge = dengesizlikYonu(aktif);

if(denge>1) //sol tarafta dengesizlik
    {
        //sol sol dengesizliği
        if(dengesizlikYonu(aktif->sol)>=0)
        {
            return sagaDondur(aktif);
        }
        //sol sag durumu
        if(dengesizlikYonu(aktif->sol)<0)
        {
            aktif->sol=solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }
    else if(denge<-1)
    {
        //sağ sağ durumu
        if(dengesizlikYonu(aktif->sag)<=0)
        {
            return solaDondur(aktif);
        }
        //sağ sol durumu
        if(dengesizlikYonu(aktif->sag)>0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }    
    return aktif;
}
int AVLAgaci::minDeger(treeDugum* aktif) 
{
    if(aktif->sol)
        return maxDeger(aktif->sol);
    
    return aktif->veri;
}
int AVLAgaci::dengesizlikYonu(treeDugum* aktif)
{
    if(aktif==0)
        return 0;
    return yukseklik(aktif->sol)- yukseklik(aktif->sag);
}
int AVLAgaci::toplamYaprakOlmayanDugumler(treeDugum* aktif) {
    if (aktif == nullptr || (aktif->sol == nullptr && aktif->sag == nullptr))
        return 0;

    int toplam = aktif->veri;
    toplam += toplamYaprakOlmayanDugumler(aktif->sol);
    toplam += toplamYaprakOlmayanDugumler(aktif->sag);
    return toplam;
}
int AVLAgaci::toplamYaprakOlmayanDugumler() {
    return toplamYaprakOlmayanDugumler(kok);
}
void AVLAgaci::tekrarver()
{
    while (!dondurulenler->stackbos())
    {
        int x = dondurulenler->tepesil();
        yiginagac->ekleyigin(x);
    }
      
}





















//int AVLAgaci::toplamYaprakOlmayanDugumler(treeDugum* aktif) {
//    if (aktif == nullptr) {
//        return false;
//    }
//
//    bool yaprakOlmayanDugum = ((aktif->sol != nullptr || aktif->sag != nullptr)  ) ? true : false;
//    yaprakOlmayanDugum += toplamYaprakOlmayanDugumler(aktif->sol);
//    yaprakOlmayanDugum += toplamYaprakOlmayanDugumler(aktif->sag);
//
//    toplam += yaprakOlmayanDugum ? aktif->veri : 0;
//
//    return toplam;
//}
//    bool Isleaf(treeDugum* node) {
//         return (node == nullptr || (node->sol == nullptr && node->sag == nullptr));
//     }

//     bool Isempty(treeDugum* node) {
//         return (node == nullptr);
//     }













