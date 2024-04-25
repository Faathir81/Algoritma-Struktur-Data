/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 03 (Nomor 16)
*/
#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
	int FatirData;
	Node *FatirLINK;
};

class FatirLLIST
{
	private:
	Node *FatirFIRST, *FatirLAST, *FatirQ;
	public:
	FatirLLIST ();
	int FatirINSERTKIRI(int FatirData);
	void FatirCETAK1();
	void FatirCETAK2();
};
int main()
{
	FatirLLIST FatirXx;
	FatirXx.FatirINSERTKIRI(22);
	FatirXx.FatirINSERTKIRI(66);
	FatirXx.FatirINSERTKIRI(28);
	FatirXx.FatirINSERTKIRI(63);
	FatirXx.FatirINSERTKIRI(10);
	FatirXx.FatirCETAK1();
	cout<<endl;
	cout<<"~~~~~~~~~~~"<<endl;
	cout<<"Nilai	: ";
	FatirXx.FatirCETAK2();
	cin.get();
}
//inisialisasi
FatirLLIST :: FatirLLIST()
{
	FatirFIRST = NULL;	//inisialisasi Linked List
}
//menginsert simpul  disebelah kiri
int FatirLLIST :: FatirINSERTKIRI(int Fatirdt)
{
	Node *FatirP;
	FatirP = new Node;
	FatirP -> FatirLINK = FatirFIRST;
	FatirP -> FatirData = Fatirdt;
	FatirFIRST = FatirP;
	return (1);
}
//menampilkan FatirData berupa string
void FatirLLIST :: FatirCETAK1()
{
	Node *FatirQ;
	FatirQ = FatirFIRST;
	while (FatirQ != NULL)
	{
		cout<<"Nilai : "<< FatirQ -> FatirData<<endl;
		FatirQ = FatirQ -> FatirLINK;
	}
}
//menampilkan FatirData berupa string
void FatirLLIST :: FatirCETAK2()
{
	Node *FatirQ;
	FatirQ = FatirFIRST;
	while (FatirQ != NULL)
	{
		cout<<FatirQ -> FatirData<<"  ";
		FatirQ = FatirQ -> FatirLINK;
	}
}