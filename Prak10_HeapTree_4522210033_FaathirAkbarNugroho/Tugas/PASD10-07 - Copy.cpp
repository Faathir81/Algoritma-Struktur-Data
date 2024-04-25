/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Soal 07)
   Prak 10
*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct FatirNode
{
    struct FatirNode *FatirLeft;
    char FatirINFO;
    struct FatirNode *FatirRight;
};

typedef struct FatirNode FatirSimpul;
FatirSimpul *FatirRoot, *FatirP, *FatirCurrent;
FatirSimpul *FatirQ[129];

void FatirInisialisasi()
{
    FatirRoot = NULL;
    FatirP = NULL;
}

void FatirBuatSimpul(char FatirX)
{
    FatirP = (FatirSimpul*)malloc(sizeof(FatirSimpul));
    if (FatirP != NULL)
    {
        FatirP->FatirINFO = FatirX;
        FatirP->FatirLeft = NULL;
        FatirP->FatirRight = NULL;
    }
    else
    {
        cout << "Memory Heap Full" << endl;
        exit(1);
    }
}

void FatirBuatSimpulAkar()
{
    if (FatirRoot == NULL)
    {
        if (FatirP != NULL)
        {
            FatirRoot = FatirP;
            FatirRoot->FatirLeft = NULL;
            FatirRoot->FatirRight = NULL;
        }
        else
        {
            cout << "FatirSimpul Belum Dibuat" << endl;
        }
    }
    else
    {
        cout << "Pohon Sudah Ada!!!!" << endl;
    }
}

void FatirInsertUrutNomor()
{
    int Fatiri, Fatirj, FatirFlag;
    char FatirX;
    FatirFlag = 0;
    Fatiri = 1;
    Fatirj = 1;
    FatirQ[Fatiri] = FatirRoot;
    while (FatirFlag == 0 && Fatirj < 127)
    {
        cin >> FatirX;
        if (FatirX != '0')
        {
            FatirBuatSimpul(FatirX);
            FatirCurrent = FatirQ[Fatiri];
            FatirCurrent->FatirLeft = FatirP;
            Fatirj++;
            FatirQ[Fatirj] = FatirP;
        }
        else
        {
            FatirFlag = 1;
            Fatirj++;
            FatirQ[Fatirj] = NULL;
        }
        if (FatirFlag == 0)
        {
            if (FatirX != '0')
            {
                FatirBuatSimpul(FatirX);
                FatirCurrent->FatirRight = FatirP;
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
        Fatiri++;
    }
}

void FatirBacaUrutNomor()
{
    int Fatiri, Fatirj, Fatirn, FatirCounter;
    char FatirX;
    Fatiri = 1;
    Fatirj = 1;
    Fatirn = 1;
    FatirCounter = 0;
    cout << endl;
    while (FatirQ[Fatiri] != NULL)
    {
        FatirCurrent = FatirQ[Fatiri];
        cout << FatirCurrent->FatirINFO << endl;
        FatirCounter++;
        if (FatirCounter == Fatirn)
        {
            cout << endl;
            FatirCounter = 0;
            Fatirn = Fatirn * 2;
        }
        if (FatirCurrent->FatirLeft != NULL)
        {
            Fatirj++;
            FatirQ[Fatirj] = FatirCurrent->FatirLeft;
        }
        if (FatirCurrent->FatirRight != NULL)
        {
            Fatirj++;
            FatirQ[Fatirj] = FatirCurrent->FatirRight;
        }
        Fatiri++;
    }
}

int main()
{
    char FatirX;
    FatirInisialisasi();
    cout << "Masukkan info simpul akar: ";
    cin >> FatirX;
    FatirBuatSimpul(FatirX);
    FatirBuatSimpulAkar();
    cout << "Masukkan info simpul-simpul (0 untuk mengakhiri): " << endl;
    FatirInsertUrutNomor();
    cout << "Output simpul-simpul: " << endl;
    FatirBacaUrutNomor();
	return 0;
}