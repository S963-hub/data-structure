#include "Bagliliste.hpp"
#include "treeDugum.hpp"
#include "Dugum.hpp"
#include "AVLAgaci.hpp"
#include "Yigin.hpp"
#include <iostream>
#include<iomanip>
#include<sstream>
Bagliliste::Bagliliste()
{
    ilk=NULL;
}
void Bagliliste::ekleBagliliste(AVLAgaci* veri)
{
    Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }

    Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
    {
    gecici= gecici->sonraki;
    }
    gecici->sonraki = yeni;
    //veri->agacindex = returncount() +1;
}
void Bagliliste::Deleteminmax()
{
    Dugum* gec = ilk;

    while (ilk != nullptr)
    {
        int enkucukVeri = 2147483646;
        Dugum* enkucuk =nullptr;
        Dugum* temp = ilk;
        while (temp != nullptr)
        {
            if (temp->veri->yiginagac->peek() < enkucukVeri)
            {
                enkucukVeri = temp->veri->yiginagac->peek();
                enkucuk = temp;
            }
            temp = temp->sonraki;
        }

        int y = enkucuk->veri->yiginagac->tepesil();
        enkucuk->veri->dondurulenler->ekleyigin(y);

        if (enkucuk->veri->yiginagac->stackbos())
        {
            cikar(enkucuk->veri);
            tekrarver2();
            system("CLS");
            gec = ilk;
            while (gec->sonraki != nullptr)
            {
                char a = gec->veri->toplamYaprakOlmayanDugumler() % (90 - 65 + 1) + 65;
                cout << a;
                gec = gec->sonraki;
            }

            break;
        }

        int enbuyukVeri = -2147483648;
        Dugum* enbuyuk =nullptr;
        temp = ilk;

        while (temp != nullptr)
        {
            if (temp->veri->yiginagac->peek() > enbuyukVeri)
            {
                enbuyukVeri = temp->veri->yiginagac->peek();
                enbuyuk = temp;
            }
            temp = temp->sonraki;
        }
         int x= enbuyuk->veri->yiginagac->tepesil();
          enbuyuk->veri->dondurulenler->ekleyigin(x);
        // enbuyuk->veri->yiginagac->tepesil();
        if (enbuyuk->veri->yiginagac->stackbos())
        {
            cikar(enbuyuk->veri);
            tekrarver2();
            system("CLS");
            gec = ilk;
            while (gec->sonraki != nullptr)
            {
                char a = gec->veri->toplamYaprakOlmayanDugumler() % (90 - 65 + 1) + 65;
                cout << a;
                gec = gec->sonraki;
            }
        break;
        }
    }
}
void Bagliliste::tekrarver2()
{
    if(ilk==0)
        return;
    Dugum* gec = ilk;
    while (gec!=0)
    {
        gec->veri->tekrarver();
        gec = gec->sonraki;
    }


}
void Bagliliste::Yazdir() {
    Dugum* temp = ilk;
  
    cout<<endl;
    // Son karakteri ekrana yazdır
    if (temp != nullptr) {
        char sonKarakter = temp->veri->toplamYaprakOlmayanDugumler() % (90 - 65 + 1) + 65;

        cout<<"==============================="<<endl;
        cout<<"|"<<setw(30)<<"|"<<endl;
        cout<<"|"<<setw(30)<<"|"<<endl;
        cout<<"|"<<setw(7)<< " "<< "SON KARAKTER : "<< sonKarakter<<setw(7)<<"|"<<endl;
        cout<<"|"<<setw(7)<< " "<< "AVL NO : "<<left<<setw(4)<< temp->veri->agacindex << right<<setw(10)<<"|"<<endl;
        cout<<"|"<<setw(30)<<"|"<<endl;
        cout<<"|"<<setw(30)<<"|"<<endl;
        cout<<"==============================="<<endl;


      
    }
}
int Bagliliste::returncount()
{
    Dugum* gecici = ilk;
    int count = 0;
    while (gecici != nullptr)
    {
        count++;
        gecici = gecici->sonraki;
    }
    return count;
}
void Bagliliste::cikar(AVLAgaci* veri)
{
    if (!veri->kok)
        return;

    Dugum* delptr = ilk;
    if (ilk->veri == veri)
        ilk = ilk->sonraki;
    else
    {
        Dugum* prev = nullptr;
        while (delptr != nullptr && delptr->veri != veri)
        {
            prev = delptr;
            delptr = delptr->sonraki;
        }
        if (delptr != nullptr)
            prev->sonraki = delptr->sonraki;
    }
    if(delptr->veri=nullptr)
    {
        delete delptr->veri;
    }
   // 
    delete delptr;
}
AVLAgaci* Bagliliste::ilkdondur()
{
    return ilk->veri;
}
bool Bagliliste::arama(AVLAgaci* veri)
{
    Dugum* gecici = ilk;
    while(gecici!=NULL)
    {
        if (gecici->veri==veri)
        {
            return true;
        }

        gecici= gecici->sonraki;
    }
    return false;
}