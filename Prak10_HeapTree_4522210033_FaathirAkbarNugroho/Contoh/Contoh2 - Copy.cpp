/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 10
*/
#include<iostream>
using namespace std;

void FatirHEAP(int FatirCanArray[], int Fatirn, int Fatiri) 
{
    int Fatirtemp;
    int FatirCanBesar = Fatiri;
    int Fatirkiri = 2 * Fatiri + 1;
    int Fatirkanan = 2 * Fatiri + 2;
    if (Fatirkiri < Fatirn && FatirCanArray[Fatirkiri] > FatirCanArray[FatirCanBesar])
        FatirCanBesar = Fatirkiri;
    if (Fatirkanan < Fatirn && FatirCanArray[Fatirkanan] > FatirCanArray[FatirCanBesar])
        FatirCanBesar = Fatirkanan;
    if (FatirCanBesar != Fatiri) 
	{
        Fatirtemp = FatirCanArray[Fatiri];
        FatirCanArray[Fatiri] = FatirCanArray[FatirCanBesar];
        FatirCanArray[FatirCanBesar] = Fatirtemp;
        FatirHEAP(FatirCanArray, Fatirn, FatirCanBesar);
    }
}

void FatirsortHEAP(int FatirCanArray[], int Fatirn) 
{
    int Fatirtemp;
    for (int Fatiri = Fatirn / 2 - 1; Fatiri >= 0; Fatiri--)
        FatirHEAP(FatirCanArray, Fatirn, Fatiri);
    for (int Fatiri = Fatirn - 1; Fatiri >= 0; Fatiri--) 
	{
        Fatirtemp = FatirCanArray[0];
        FatirCanArray[0] = FatirCanArray[Fatiri];
        FatirCanArray[Fatiri] = Fatirtemp;
        FatirHEAP(FatirCanArray, Fatiri, 0);
    }
}

int main() 
{
	int FatirCanArray[]={22, 7, 66, 28, 11, 63, 24, 12, 77, 99};
	int Fatirn = 10;
	int Fatiri;
	
	cout<<"Menampilkan Data Sebelum Diurutkan "<<endl;
	cout<<"-----------------------------------"<<endl;
	for (Fatiri=0; Fatiri < Fatirn; Fatiri++)
	{
		cout<<FatirCanArray[Fatiri]<< " ";
	}
	cout<<endl;
	FatirsortHEAP(FatirCanArray,Fatirn);
	cout<<endl;
	cout<<"Menampilkan Data Setelah Ditkan - HEAP SORI "<<endl;
	cout<<"------------------------------------------"<<endl;
	for (Fatiri=0; Fatiri<Fatirn; ++Fatiri)
	{
		cout<<FatirCanArray[Fatiri]<< " ";
	}
	cin.get();
}