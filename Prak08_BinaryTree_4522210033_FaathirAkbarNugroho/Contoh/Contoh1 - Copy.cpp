/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 08
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//struktur yg dpt dibuat
struct FatirNode
{
	char FatirINFO;
	struct FatirNode* FatirLEFT;
	struct FatirNode* FatirRIGHT;
};

typedef struct FatirNode FatirSimpul;
FatirSimpul *FatirRoot, *FatirP, *FatirQ[30], *FatirR, *FatirCurrent;
char FatirX;

void FatirInisialisasi()
{
	FatirRoot = NULL;
	FatirP = NULL;
}

void FatirBuatSimpul(char FatirX)
{
	FatirP=(FatirSimpul*) malloc(sizeof(FatirSimpul));
	if(FatirP != NULL){
		FatirP->FatirINFO = FatirX;
		FatirP->FatirLEFT = NULL;
		FatirP->FatirRIGHT = NULL;
	}
	else
	{
		cout << "Pembuatan Simpul Gagal \n";
		exit(1);
	}
}

void FatirBuatSimpulAkar()
{
	if(FatirRoot == NULL)
	{
		if(FatirP !=NULL)
		{
			FatirRoot = FatirP;
			FatirP->FatirLEFT = NULL;
			FatirP->FatirRIGHT = NULL;
		}
		else
		{
			cout << "Simpul Belum dibuat \n";
		}
	}
	else
	{
		cout << "Pohon Sudah Ada !!!! \n";
	}
}

void FatirInsertUrutNomer(char FatirInput[6])
{
	int Fatiri,Fatirj,FatirFlag;
	char FatirX;
	FatirFlag = 0;
	Fatiri=1;
	Fatirj=1;
	FatirQ[Fatiri] = FatirRoot;
	while(FatirFlag == 0 && Fatirj < 6)
	{
		FatirX = FatirInput[Fatirj-1];
		if(FatirX != '0')
		{
			FatirBuatSimpul(FatirX);
			FatirCurrent = FatirQ[Fatiri];
			FatirCurrent -> FatirLEFT = FatirP;
			Fatirj++;
			FatirQ[Fatirj] = FatirP;
		}
		else
		{
			FatirFlag = 1;
			Fatirj++;
			FatirQ[Fatirj] = NULL;
		}
		if(FatirFlag == 0)
		{
			FatirX = FatirInput[Fatirj-1];
			if(FatirX !='0')
			{
				FatirBuatSimpul(FatirX);
				FatirCurrent->FatirRIGHT =FatirP;
				Fatirj++;
				FatirQ[Fatirj] = FatirP;
			}
			else
			{
				FatirFlag = 1;
				Fatirj++;
				FatirQ[Fatirj] = NULL;
			}
		}
	}
}

void FatirBacaUrutNomer()
{
	int Fatiri,Fatirj,Fatirn, FatirCounter;
	Fatiri=1;Fatirj=1;Fatirn=1;FatirCounter=0;
	int Fatirlevel=0;
	while(FatirQ[Fatiri] != NULL)
	{
		FatirCurrent = FatirQ[Fatiri];
		if(Fatiri == 1)
		{
			cout << "Level "<<Fatirlevel<<"\n";
		}
		cout <<FatirCurrent->FatirINFO<<" - ";
		FatirCounter++;
		if(FatirCounter == Fatirn) 
		{
			Fatirlevel++;
			cout << "\nLevel "<<Fatirlevel<<""; 
		}
		if(FatirCounter == Fatirn)
		{
			cout << endl;
			FatirCounter = 0;
			Fatirn = Fatirn*2;
		}
		if(FatirCurrent->FatirLEFT !=NULL) 
		{
			Fatirj++;
			FatirQ[Fatiri] = FatirCurrent->FatirLEFT;
		}
		if(FatirCurrent->FatirRIGHT !=NULL)
		{
			Fatirj++;
			FatirQ[Fatiri]=FatirCurrent->FatirRIGHT;
		}
		Fatiri++;
	}
}	
int main()
{
	char Fatirroot = 'C';
	char FatirDaun[6] = {'A', 'B', 'D', 'E', 'F', 'G'};
	FatirInisialisasi();
	FatirBuatSimpul(Fatirroot);
	FatirBuatSimpulAkar();
	FatirInsertUrutNomer(FatirDaun);
	FatirBacaUrutNomer();
	return 0;
	cin.get();
}