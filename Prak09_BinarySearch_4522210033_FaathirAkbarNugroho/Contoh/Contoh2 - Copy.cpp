/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 09
*/
//Binary Search menggunakan fungsi
#include<iostream>
using namespace std;
#define n 10

void FatirBinSearch(int FatirA[], int FatirN)
{
	int Fatiri, FatirLo, FatirHi, FatirMid, FatirFlag;
	FatirLo=0, FatirHi=n-1; FatirFlag=0;
	while(FatirLo <= FatirHi && FatirFlag==0)
	{
		FatirMid=(FatirLo+FatirHi)/2;
		if(FatirN==FatirA[FatirMid])
			FatirFlag=1;
		else
			if(FatirN<FatirA[FatirMid])
				FatirHi=FatirMid-1;
			else
				FatirLo=FatirMid+1;
	}
	if(FatirFlag==1)
		cout<<"Nilai "<<FatirN<<" ditemukan pada baris ke "<<(FatirMid+1)<<endl;
	else
		cout<<"Nilai tidak ditemukan"<<endl;
}

int main() 
{
	int Fatiri, FatirN;
	int FatirA[n] = {4,7,10,11,16,22,24,28,63,66};
	
	//Menampilkan daftar nilainya
	cout<<"DAFTAR NILAI/ANGKA "<<endl;
	for(Fatiri=0; Fatiri<=n-1; Fatiri++)
	{ 
		cout<<" "<< FatirA[Fatiri] << endl; 
	}
	//Menginput data yang mau dicari
	cout<<"Masukkan Data Yang dicari: "; cin>>FatirN;
	FatirBinSearch(FatirA,FatirN);
}