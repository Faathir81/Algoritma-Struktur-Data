/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 05
*/
// Program Pengurutan Gelembung - Bubble Sort
#include <string.h>
#include <iostream>
using namespace std;

int FatirData[10], FatirData2[10];
int Fatirn;
void FatirTukar(int Fatira, int Fatirb)
{
	int Fatirt;
	Fatirt = FatirData[Fatirb];
	FatirData[Fatirb] = FatirData[Fatira];
	FatirData[Fatira] = Fatirt;
}
void Fatirinput()
{
	cout << "Masukkan Jumlah Data = " ; cin >> Fatirn;
	cout << "---------------------- " << endl;
	for(int Fatiri=0; Fatiri<Fatirn; Fatiri++)
	{
		cout << "Masukkan Data ke-" << (Fatiri+1) << " = "; cin >> FatirData[Fatiri];
		FatirData2[Fatiri] = FatirData[Fatiri];
	}
	cout << endl;
}
void Fatirtampil()
{
	for(int Fatiri = 0; Fatiri<Fatirn; Fatiri++)
	{
		cout << FatirData[Fatiri] << " ";
	}
	cout << endl;
}
void Fatirbubble_sort()
{
	for(int Fatiri=1; Fatiri<Fatirn; Fatiri++)
	{
		for(int j = Fatirn-1; j>=Fatiri; j--)
		{
			if(FatirData[j] < FatirData[j-1]) FatirTukar(j,j-1);
		}
		Fatirtampil();
	}
	cout << endl;
}

int main()
{
	cout << "*-----------------------------------*" << endl;
	cout << "*     Selamat datang di aplikasi    *" << endl;
	cout << "*            Bubble Sort            *" << endl;
	cout << "*-----------------------------------*" << endl;
	Fatirinput();
	cout << "         Proses Bubble Sort........  " << endl;
	cout << "-------------------------------------" << endl;
	Fatirtampil();
	Fatirbubble_sort();
	cout << "-------------------------------------" << endl;
	cout << "             TERIMA KASIH            " << endl;
	cout << "-------------------------------------" << endl;
	cin.get();
}