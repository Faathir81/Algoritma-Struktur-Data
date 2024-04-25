/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 09
*/
#include <iostream>
using namespace std;
#define n 10

int main() 
{
    int Fatirn;
    int Fatira[n] = {4, 7, 10, 11, 16, 22, 24, 28, 63, 66};
    int Fatiri, Fatirlo, Fatirhi, Fatirmid, Fatirflag;
    cout << "DAFTAR NILAI/ANGKA " << endl;
    for (Fatiri = 0; Fatiri <= n - 1; Fatiri++) 
	{
        cout << "  " << Fatira[Fatiri] << endl;
    }
    cout << "Masukkan Data Yang dicari : ";
    cin >> Fatirn;
    Fatirlo = 0;
    Fatirhi = n - 1;
    Fatirflag = 0;
    while (Fatirlo <= Fatirhi && Fatirflag == 0) 
	{
        Fatirmid = (Fatirlo + Fatirhi) / 2;
        if (Fatirn == Fatira[Fatirmid]) 
            Fatirflag = 1;
        else 
			if (Fatirn < Fatira[Fatirmid]) 
               Fatirhi = Fatirmid - 1;
            else 
               Fatirlo = Fatirmid + 1;
    }
    if (Fatirflag == 1) 
        cout << "Nilai " << Fatirn << " ditemukan pada baris ke " << Fatirmid + 1 << endl;
     else 
        cout << "Nilai tidak ditemukan" << endl;
}