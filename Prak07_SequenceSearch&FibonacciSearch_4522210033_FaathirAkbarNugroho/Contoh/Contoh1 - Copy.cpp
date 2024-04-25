/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 07
*/
#include <iostream>
using namespace std;

int FatirSearch01(int Fatirtika[], int, int);
int main()
{
    const int FatirJmlElemenArray = 11;
    int Fatirtika[FatirJmlElemenArray] = { 22, 61, 15, 66, 18, 25, 34, 87, 55, 45, 10 };
    cout << "***************************************************" << endl;
    cout << "********S E Q U E N T I A L  S E A R C H*********" << endl;
    cout << "***************************************************" << endl;
    //gotocy(1,5)
    cout << "Isi datanya adalah " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    for (int Fatircount = 0; Fatircount < FatirJmlElemenArray; Fatircount++)
    {
        cout << "\t" << "Data [" << Fatircount+1 << "]" << "-->" << Fatirtika[Fatircount] << endl;
    }
    int FatirSearchElemen = 0;
    int Fatirflag = 0;
    cout << "***************************************************" << endl;
    cout << endl;
    cout << "Masukkan data yang anda cari ";
    cin >> FatirSearchElemen;
    Fatirflag = FatirSearch01(Fatirtika, FatirJmlElemenArray, FatirSearchElemen);
    if (Fatirflag != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data[" << Fatirflag+1 << "]" << endl;
    else
        cout << "Data yang anda cari tidak ditemukan" << endl;
    cin.get();
    return 0;
}

int FatirSearch01(int Fatirtika[], int FatirJmlElemenArray, int FatirElemen)
{
    int Fatirflag = -1;
    for (int Fatircount = 0; Fatircount < FatirJmlElemenArray; Fatircount++)
    {
        if (FatirElemen == Fatirtika[Fatircount])
        {
            Fatirflag = Fatircount;
        }
    }
	return Fatirflag;
}