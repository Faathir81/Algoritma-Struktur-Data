/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 04
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
void FatirBUAT_SIMPUL(int FatirX);
void FatirAWAL();
void FatirCETAK();
void FatirINSERTKANAN();
struct Node  //Deklarasi struktur FatirSimpul   
{
	int FatirINFO;
	struct Node *FatirLINK; 
};
typedef struct Node FatirSimpul;
FatirSimpul *FatirP, *FatirFIRST, *FatirLAST, *FatirQ; //menyiapkan pointer2 yg dpt menunjuk ke FatirSimpul
int main() 
{
	int FatirX, FatirI;
	int FatirA[7] = {22,28,7,11,66,63,10}; //Data yang disimpan kedlm FatirINFO
	FatirFIRST = NULL; //inisialisasi linked list
	FatirI=0;
	FatirX=FatirA[FatirI];
	FatirBUAT_SIMPUL(FatirX);
	FatirAWAL(); //Menyiapkan FatirSimpul awal
	for(FatirI=1; FatirI<=6; FatirI++) // menambahkan 8 FatirSimpul baru dan insert kanan agar terbentuk linked list
	{
		FatirX=FatirA[FatirI];
		FatirBUAT_SIMPUL(FatirX);
		FatirINSERTKANAN(); 
	}
	cout << "Nilai sebelum dilakukan insert kanan : ";
	FatirCETAK();
	FatirX=100;
	FatirBUAT_SIMPUL(FatirX);
	FatirINSERTKANAN(); //menginsert FatirSimpul baru disbelah kanan dgn FatirINFO=999
	cout << endl;
	cout << "Nilai setelah dilakukan insert kanan : ";
	FatirCETAK();
	cout << endl;
	cin.get(); 
}

void FatirBUAT_SIMPUL(int FatirX) //fungsi membuat sebuah FatirSimpul baru
{
	FatirP=(FatirSimpul*) malloc(sizeof(FatirSimpul));
	if(FatirP != NULL) 
	{
		FatirP -> FatirINFO = FatirX; 
	}
	else 
	{
		cout << "Pembuatan FatirSimpul tidak berhasil" << endl;
		cin.get();
		exit(1);
	}
}

void FatirAWAL() //fungsi membuat FatirSimpul awal
{
	FatirFIRST = FatirP;
	FatirLAST = FatirP;
	FatirP -> FatirLINK = NULL; 
}

void FatirINSERTKANAN() //fungsi menginsert FatirSimpul disebelah kanan
{
	FatirLAST -> FatirLINK = FatirP;
	FatirLAST = FatirP;
	FatirP -> FatirLINK = NULL; 
}

void FatirCETAK() //fungsi mencetak isi seluruh FatirSimpul
{
	int FatirX;
	FatirQ = FatirFIRST;
	while(FatirQ != NULL) 
	{
		FatirX = FatirQ -> FatirINFO;
		cout << " " << FatirX;
		FatirQ = FatirQ -> FatirLINK; 
	} 
}