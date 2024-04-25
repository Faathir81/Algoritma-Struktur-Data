/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Soal 14)
   Prak 07
*/
#include <iostream>
#include <cstring>
using namespace std;
#define FatirMAXSIZE 30

class FatirFibonacciSearch 
{
public:
    static void Fatirfibonacci(int *FatirF);
    static int Fatirfibonacci_search(int *Fatira, int Fatirkey, int Fatirn);
};

void FatirFibonacciSearch::Fatirfibonacci(int *FatirF)
{
    FatirF[0] = 1;
    FatirF[1] = 1;
    for (int Fatiri = 2; Fatiri < FatirMAXSIZE; Fatiri++)
        FatirF[Fatiri] = FatirF[Fatiri - 2] + FatirF[Fatiri - 1];
}

int FatirFibonacciSearch::Fatirfibonacci_search(int *Fatira, int Fatirkey, int Fatirn)
{
    int FatirRendah = 0, FatirTinggi = Fatirn - 1;
    int Fatirmid = 0;
    int Fatirk = 0;
    int FatirF[FatirMAXSIZE];
    Fatirfibonacci(FatirF);
    while (Fatirn > FatirF[Fatirk] - 1)
        ++Fatirk;
    for (int Fatiri = Fatirn; Fatiri < FatirF[Fatirk] - 1; ++Fatiri)
        Fatira[Fatiri] = Fatira[FatirTinggi];
    while (FatirRendah <= FatirTinggi)
    {
        Fatirmid = FatirRendah + FatirF[Fatirk - 1] - 1;
        if (Fatira[Fatirmid] > Fatirkey)
        {
            FatirTinggi = Fatirmid - 1;
            Fatirk = Fatirk - 1;
        }
        else if (Fatira[Fatirmid] < Fatirkey)
        {
            FatirRendah = Fatirmid + 1;
            Fatirk = Fatirk - 2;
        }
        else
        {
            if (Fatirmid <= FatirTinggi)
                return Fatirmid;
            else
                return -1;
        }
    }
    return -1;
}

int main()
{
    int Fatira[FatirMAXSIZE] = {1, 4, 6, 8, 9, 11, 23, 35, 47, 51, 55, 63, 64, 78, 88, 95, 99};
    int Fatirk = 35;
    cout << "Masukkan angka yang dicari : " << Fatirk << endl;
    int Fatirpos = FatirFibonacciSearch::Fatirfibonacci_search(Fatira, Fatirk, 17);
    if (Fatirpos != -1)
        cout << "Data yang ditentukan pada posisi : " << Fatirpos + 1 << " Isi Elemennya = " << Fatirk << endl;
    else
        cout << "Data tidak ditemukan" << endl;
    cin.get();
    return 0;
}
