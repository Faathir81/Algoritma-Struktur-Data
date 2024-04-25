/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 05 (Nomor 14)
*/
#include <iostream>
using namespace std;

class FatirShellSort 
{
	public:
	void FatirSort(int FatirA[], int Fatirn) 
	{
		int FatirI, FatirJ, FatirK, FatirTemp, FatirFlag, FatirX;
		FatirK=0;
		FatirFlag=1;
		while(FatirK<=Fatirn-2&&FatirFlag==1)
		{
			FatirI=0;
			FatirFlag=0;
			while(FatirI<=Fatirn-2-FatirK)
			{
				if(FatirA[FatirI]>FatirA[FatirI+1])
				{
					FatirFlag=1;
					FatirX=FatirA[FatirI];
					FatirA[FatirI]=FatirA[FatirI+1];
					FatirA[FatirI+1]=FatirX; 
				}
				FatirI++; 
			}
			FatirK++; 
		}
	}
};

int main() {
    int Fatirn;
	cout << "====================================" << endl;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> Fatirn;
    int FatirA[Fatirn];
    cout << "Masukkan elemen-elemen dalam array:\n";
    for(int FatirI = 0; FatirI < Fatirn; FatirI++)
        cin >> FatirA[FatirI];
    
    FatirShellSort obj;
    obj.FatirSort(FatirA, Fatirn);
    cout << "====================================" << endl;
    cout << "Hasil pengurutan secara ascending:\n";
    for(int FatirI = 0; FatirI < Fatirn; FatirI++)
        cout << FatirA[FatirI] << " ";
    cout << endl;
	cout << "====================================" << endl;
    
    return 0;
}