/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 06
*/
#include <iostream>
#include <iomanip>
using namespace std;

void Fatirq_sort(int[], int, int);
int main()
{
	int FatirNumList[9]={3,7,8,5,2,1,9,5,4};
	cout << " Data Sebelum Diurutkan: ";
	for (int Fatird=0; Fatird<9;Fatird++)
	{
		cout << setw(3) << FatirNumList[Fatird];
	}
	cout << endl;
	cout << endl;
	Fatirq_sort(FatirNumList,0,9);
	cout << " Data Setelah Diurutkan: ";
	cout << endl;
	for (int Fatiri=0; Fatiri<9; Fatiri++)
	{
		cout << setw(3) << FatirNumList[Fatiri] << endl;
	}
	cin.get();
}

void Fatirq_sort(int FatirNumbers[], int Fatirleft, int Fatirright)
{
	int Fatirpivot,Fatirl_hold,Fatir_hold;
	Fatirl_hold=Fatirleft;
	Fatir_hold=Fatirright;
	Fatirpivot=FatirNumbers[Fatirleft];
	while (Fatirleft<Fatirright)
	{
		while((FatirNumbers[Fatirright]>=Fatirpivot)&&(Fatirleft<Fatirright))
		{
			Fatirright--;
		}
		if(Fatirleft!= Fatirright)
		{
			FatirNumbers[Fatirleft]=FatirNumbers[Fatirright];
			Fatirleft++;
		}
		while((FatirNumbers[Fatirleft] <= Fatirpivot)&&(Fatirleft<Fatirright))
		{
			Fatirleft++;
		}
		if (Fatirleft!=Fatirright)
		{
			FatirNumbers[Fatirright]=FatirNumbers[Fatirleft];
			Fatirright--;
		}
	}
	FatirNumbers[Fatirleft]=Fatirpivot;
	Fatirpivot=Fatirleft;
	Fatirleft=Fatirl_hold;
	Fatirright=Fatir_hold;
	if (Fatirleft<Fatirpivot)
	{
		Fatirq_sort(FatirNumbers,Fatirleft,Fatirpivot-1);
	}
	if (Fatirright>Fatirpivot)
	{
		Fatirq_sort(FatirNumbers, Fatirpivot+1, Fatirright);
	}
}