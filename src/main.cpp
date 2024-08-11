#include "AVLAgaci.hpp"
#include "Yigin.hpp"
#include "Dugum.hpp"
#include "treeDugum.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>
#include "Bagliliste.hpp"

using namespace std;

int main()
{
    int count = 0;
    string str;
    ifstream dosya("benioku.txt");
while (getline(dosya, str))
	{
        count++;
    }
    dosya.close();

Bagliliste agaclar;
AVLAgaci* AGACLAR = new AVLAgaci[count];
string satir;
int index = 0;

dosya.open("benioku.txt",ios::in);
if (dosya.is_open())
{

     while (getline(dosya, satir))
    	{

            stringstream ss(satir);
            int sayi;
            while (ss >> sayi)
    		{
                AGACLAR[index].ekle(sayi);
            }
            AGACLAR[index].postOrder();
            AGACLAR[index].agacindex = index +1;
            agaclar.ekleBagliliste(AGACLAR+index);
        index++;
        agaclar.ilk->veri->agacindex = index;
        }
}


 


 for (int i = 0; i < index; i++) {
        if (i + 1 != index) {
            agaclar.Deleteminmax();
        }
        else
        {
            agaclar.Yazdir();
        }
}
    delete[] AGACLAR;
    dosya.close();
    return 0;

}