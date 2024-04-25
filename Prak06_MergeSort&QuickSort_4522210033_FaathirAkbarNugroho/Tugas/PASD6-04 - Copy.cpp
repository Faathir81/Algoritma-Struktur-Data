/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Soal 04)
   Prak 06
*/
#include <iostream>
using namespace std;

int Fatira[] = {5, 3, 1, 2, 4}; // variabel array yang ingin diurutkan

void Fatirmerge(int Fatirlow, int Fatirmid, int Fatirhigh)
{
    int Fatirh, Fatiri, Fatirj, Fatirb[50], Fatirk;
    Fatirh = Fatirlow;
    Fatiri = Fatirlow;
    Fatirj = Fatirmid + 1;
    while ((Fatirh <= Fatirmid) && (Fatirj <= Fatirhigh))
    {
        if (Fatira[Fatirh] <= Fatira[Fatirj])
        {
            Fatirb[Fatiri] = Fatira[Fatirh];
            Fatirh++;
        }
        else
        {
            Fatirb[Fatiri] = Fatira[Fatirj];
            Fatirj++;
        }
        Fatiri++;
    }
    if (Fatirh > Fatirmid)
    {
        for (Fatirk = Fatirj; Fatirk <= Fatirhigh; Fatirk++)
        {
            Fatirb[Fatiri] = Fatira[Fatirk];
            Fatiri++;
        }
    }
    else
    {
        for (Fatirk = Fatirh; Fatirk <= Fatirmid; Fatirk++)
        {
            Fatirb[Fatiri] = Fatira[Fatirk];
            Fatiri++;
        }
    }
    for (Fatirk = Fatirlow; Fatirk <= Fatirhigh; Fatirk++)
	{
        Fatira[Fatirk] = Fatirb[Fatirk];
	}
}

void Fatirmerge_sort(int Fatirlow, int Fatirhigh)
{
    int Fatirmid;
    if (Fatirlow < Fatirhigh)
    {
        Fatirmid = (Fatirlow + Fatirhigh) / 2;
        Fatirmerge_sort(Fatirlow, Fatirmid);
        Fatirmerge_sort(Fatirmid + 1, Fatirhigh);
        Fatirmerge(Fatirlow, Fatirmid, Fatirhigh);
    }
}

int main()
{
    int Fatirnum = 5, Fatiri;
    cout << "Array sebelum diurutkan: ";
    for (Fatiri = 0; Fatiri < Fatirnum; Fatiri++)
    {
        cout << Fatira[Fatiri] << " ";
    }
    Fatirmerge_sort(0, Fatirnum - 1);
    cout << "\nArray setelah diurutkan: ";
    for (Fatiri = 0; Fatiri < Fatirnum; Fatiri++)
    {
        cout << Fatira[Fatiri] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}