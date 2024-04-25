/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 05 (Nomor 09)
*/
#include <iostream>
using namespace std;

int main()
{
    int Fatirn = 5; // Jumlah elemen dalam array
    int FatirA[Fatirn] = {4, 2, 5, 1, 3}; // Isi array yang belum terurut
    int Fatiri, Fatirk, FatirX, FatirFlag;

    Fatirk=0;
    FatirFlag=1;
    while(Fatirk<=Fatirn-2&&FatirFlag==1)
    {
        Fatiri=0;
        FatirFlag=0;
        while(Fatiri<=Fatirn-2-Fatirk)
        {
            if(FatirA[Fatiri]<FatirA[Fatiri+1])
            {
                FatirFlag=1;
                FatirX=FatirA[Fatiri];
                FatirA[Fatiri]=FatirA[Fatiri+1];
                FatirA[Fatiri+1]=FatirX; 
            }
            Fatiri++; 
        }
        Fatirk++; 
    }
	// Cetak hasil pengurutan secara descending
	cout << "============" << endl;
    for(Fatiri = 0; Fatiri < Fatirn; Fatiri++)
    {
        cout << FatirA[Fatiri] << " ";
    }
	cout << endl;
	cout << "============" << endl;

    return 0;
}