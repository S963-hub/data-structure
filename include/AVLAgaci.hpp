#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "treeDugum.hpp"
#include "Yigin.hpp"
using namespace std;

class AVLAgaci{
public:
	treeDugum* kok;
	int toplam;
	Yigin* yiginagac;
	int agacindex;
	Yigin* dondurulenler;

	AVLAgaci();
	~AVLAgaci();
	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
	int yukseklik();
	void postOrder();
	int toplamYaprakOlmayanDugumler(treeDugum* aktif);
	int toplamYaprakOlmayanDugumler();
	void tekrarver();
	// bool Isleaf(treeDugum* node);
	// bool Isempty(treeDugum* node);
	//int toplamYaprakOlmayanDugumleriEkranaYazdir();
	//string YaprakDondur();
private:
    
	int dengesizlikYonu(treeDugum* aktif);
	treeDugum* solaDondur(treeDugum* dugum);
	treeDugum* sagaDondur(treeDugum* dugum);
	int minDeger(treeDugum* aktif);	
	void postOrder(treeDugum* index);
	int yukseklik(treeDugum* aktifDugum);
	treeDugum* ekle(int veri,treeDugum* aktifDugum);
	bool varmi(int aranan,treeDugum* aktif);
	treeDugum* sil(int veri,treeDugum* aktif);
	int maxDeger(treeDugum* aktif);
	//string YaprakDondur(treeDugum* aktif);
};

#endif