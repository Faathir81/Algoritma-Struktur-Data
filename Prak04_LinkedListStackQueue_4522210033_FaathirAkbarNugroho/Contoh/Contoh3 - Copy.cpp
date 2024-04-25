/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 3)
   Prak 04
*/
#include <iostream>
#include <string.h>
using namespace std;
#define FatirMAX 100
#define true 1
#define false 0

struct FatirBiodata
{
	char FatirNama[20];
	int FatirUsia;
};
struct FatirBiodata FatirMhs;
struct FatirBiodata FatirQueue[FatirMAX];
void Fatirinit(void);
int FatirFull (void);
int FatirEmpty(void);
struct FatirBiodata FatirEntriData(void);
void FatirEnqueue(struct FatirBiodata FatirMhs);
struct FatirBiodata FatirDequeue(void);
void FatirDisplay (struct FatirBiodata FatirMhs);
void FatirBaca(void);
int FatirAwal, FatirAkhir;
char FatirNoComment[10];

int main ()
{
	char FatirPilih;
	cout << "== Program Entri Data Mahasiswa =="<<endl;
	Fatirinit();
	do 
	{
		cout << "MENU PILIHAN :\n";
		cout << "1. Input Data\n";
		cout << "2. Hapus Data\n";
		cout << "3. Lihat Daftar Mahasiswa\n";
		cout << "4. Hapus Semua Data\n";
		cout << "5. Selesai\n";
		cout << "Pilih 1 sd 5 : ";
		cin >> FatirPilih;
		switch (FatirPilih)
		{
			case '1' : FatirMhs = FatirEntriData();FatirEnqueue(FatirMhs);break;
			case '2' : cout << "\n data yang dihapus \n";FatirMhs = FatirDequeue (); FatirDisplay(FatirMhs);break;
			case '3' : FatirBaca();break;
			case '4' : Fatirinit(); cout << "\nData telah dikosongkan\n";break;
			case '5' : break;
			default : cout << "Pilih 1 sd 5 ! ";break;
		}
		cout << "\n";
	}
	while (FatirPilih != '5');
	return 0;
}

void Fatirinit(void)	
{
	FatirAwal = -1;
	FatirAkhir = -1;
}

void FatirEnqueue(struct FatirBiodata FatirMhs)	
{
	if(FatirEmpty() == true)	
	{
		FatirAwal = 0;
		FatirAkhir = 0;
		FatirQueue[FatirAwal] = FatirMhs;
	}
	else 
	if(FatirFull() !=true)	
	{
		FatirAkhir++;
		FatirQueue[FatirAkhir] = FatirMhs;
	}
	else cout<< "Queue sudah penuh... \n";
}

struct FatirBiodata FatirDequeue(void)	
	{
		int FatirI;
		if(FatirEmpty() != true)	
		{
			FatirMhs = FatirQueue[FatirAwal];
			for(FatirI=FatirAwal; FatirI<=FatirAkhir; FatirI++)
			{
				FatirQueue[FatirI] = FatirQueue[FatirI+1];
				FatirAkhir--;
				return(FatirMhs);
			}
		}
		else cout<<"Queue kosong...\n";
	}
	
int FatirFull(void)	
	{
		if(FatirAkhir==FatirMAX-1) return(true);
		else return(false);
	}

int FatirEmpty(void)	
	{
		if(FatirAkhir== -1) return(true);
		else return(false);
	}

void FatirBaca(void)	
	{
		int FatirI;
		cout<<"\nIsi Queue : \n";
		if(FatirEmpty() != true)	
		{
			for(FatirI=FatirAwal; FatirI<=FatirAkhir; FatirI++)
			{
				FatirDisplay(FatirQueue[FatirI]);
			}
		}
		else cout<<"Data Kosong, ";
		cout<<"\n";
	}
	
struct FatirBiodata FatirEntriData(void)	
	{
		struct FatirBiodata FatirMhs;
		cout<<"\n";
		cout<<"Masukkan Nama : ";cin>>FatirMhs.FatirNama;
		cout<<"Masukkan Usia : ";cin>>FatirMhs.FatirUsia;
		return(FatirMhs);
	}
	
void FatirDisplay(struct FatirBiodata FatirMhs)	
	{
		cout<<"\n";
		cout<<"Nama : "<<FatirMhs.FatirNama<<"\n";
		cout<<"Usia : "<<FatirMhs.FatirUsia<<"\n";
	}