/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Soal 11)
   Prak 06
*/
#include <iostream>
#include <iomanip>
using namespace std;

class FatirSort 
{
	private:
		int* FatirNumbers;
		int Fatirleft;
		int Fatirright;

	public:
		FatirSort(int arr[], int left, int right) 
		{
			FatirNumbers = arr;
			Fatirleft = left;
			Fatirright = right;
		}

    void Fatirsort() 
	{
        int Fatirpivot, Fatirl_hold, Fatir_hold;
        Fatirl_hold = Fatirleft;
        Fatir_hold = Fatirright;
        Fatirpivot = FatirNumbers[Fatirleft];
        while (Fatirleft < Fatirright) 
		{
            while ((FatirNumbers[Fatirright] >= Fatirpivot) && (Fatirleft < Fatirright))
                Fatirright--;
            if (Fatirleft != Fatirright) 
			{
                FatirNumbers[Fatirleft] = FatirNumbers[Fatirright];
                Fatirleft++;
            }
            while ((FatirNumbers[Fatirleft] <= Fatirpivot) && (Fatirleft < Fatirright)) 
			{
                Fatirleft++;
            }
            if (Fatirleft != Fatirright) 
			{
                FatirNumbers[Fatirright] = FatirNumbers[Fatirleft];
                Fatirright--;
            }
        }
        FatirNumbers[Fatirleft] = Fatirpivot;
        Fatirpivot = Fatirleft;
        Fatirleft = Fatirl_hold;
        Fatirright = Fatir_hold;
        if (Fatirleft < Fatirpivot)
            FatirSort(FatirNumbers, Fatirleft, Fatirpivot - 1).Fatirsort();
        if (Fatirright > Fatirpivot)
            FatirSort(FatirNumbers, Fatirpivot + 1, Fatirright).Fatirsort();
    }
};

int main()
{
    int FatirNumList[9] = {65,2,44,26,19,22,5,3,12};
    cout << " Data Sebelum Diurutkan: ";
    for (int Fatird = 0; Fatird < 9; Fatird++)
    {
        cout << setw(3) << FatirNumList[Fatird];
    }
    cout << endl;
    cout << endl;
    FatirSort(FatirNumList, 0, 9).Fatirsort();
    cout << " Data Setelah Diurutkan: ";
    cout << endl;
    for (int Fatiri = 0; Fatiri < 9; Fatiri++)
        cout << setw(3) << FatirNumList[Fatiri] << endl;
    cin.get();
}
