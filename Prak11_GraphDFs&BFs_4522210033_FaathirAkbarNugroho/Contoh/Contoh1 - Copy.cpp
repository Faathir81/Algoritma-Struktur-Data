/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 11
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int Fatircost[10][10], Fatiri, Fatirj, Fatirk, Fatirn, Fatirstk[10], Fatirtop, Fatirv, Fatirvisit[10], Fatirvisited[10];

int main()
{
    int Fatirm;
    cout << "Masukkan Jumlah Vertex: ";
    cin >> Fatirn;
    cout << "Masukkan Jumlah Busur: ";
    cin >> Fatirm;
    cout << "Busur" << endl;
    for (Fatirk = 1; Fatirk <= Fatirm; Fatirk++)
    {
        cin >> Fatiri >> Fatirj;
        Fatircost[Fatiri][Fatirj] = 1;
    }
    cout << "Inisialisasi Vertex: ";
    cin >> Fatirv;
    cout << "DFS Order Vertex: " << Fatirv << " ";
    Fatirvisited[Fatirv] = 1;
    Fatirk = 1;
    while (Fatirk < Fatirn)
    {
        for (Fatirj = Fatirn; Fatirj >= 1; Fatirj--)
        {
            if (Fatircost[Fatirv][Fatirj] != 0 && Fatirvisited[Fatirj] != 1 && Fatirvisit[Fatirj] != 1)
            {
                Fatirvisit[Fatirj] = 1;
                Fatirstk[Fatirtop] = Fatirj;
                Fatirtop++;
            }
        }
        Fatirv = Fatirstk[--Fatirtop];
        cout << Fatirv << " ";
        Fatirk++;
        Fatirvisit[Fatirv] = 0;
        Fatirvisited[Fatirv] = 1;
    }
    cin.ignore();
    cin.get();
    return 0;
}