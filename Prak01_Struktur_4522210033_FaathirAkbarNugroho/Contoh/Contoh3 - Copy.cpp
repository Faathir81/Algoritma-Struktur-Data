/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 3)
   Prak 01
*/

#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

//nama struct
struct fatirpelanggan_toko
{
	string fatirnama[20],fatiralamat[20],fatirkelamin[2],fatirtelp[20];
	int fatirumur[3];
};
fatirpelanggan_toko fatirdata;
int main()
{
	int fatirjumlah, fatiri;
	cout<<endl;
	cout<<"INPUT DATA PELANGGAN\n";
	cout<<"Jumlah pelanggan : ";cin>>fatirjumlah;
//Input Data
	for(fatiri=1;fatiri<=fatirjumlah;fatiri++)
	{
		cout<<endl;
		cout<<"Nama Pelanggan Toko               : ";cin>>fatirdata.fatirnama[fatiri];
		cout<<"Alamat Pelanggan Toko             : ";cin>>fatirdata.fatiralamat[fatiri];
		cout<<"Umur Pelanggan Toko               : ";cin>>fatirdata.fatirumur[fatiri];
		cout<<"Jenis Kelamin Pelanggan[L/P]      : ";cin>>fatirdata.fatirkelamin[fatiri];
		cout<<"No telp Pelanggan                 : ";cin>>fatirdata.fatirtelp[fatiri];
		cout<<endl;
	}
	cout<<endl; //Menampilkan Data
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"                        Data Pelanggan Toko                       "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"|Nama    |Alamat       |Umur      |Kelamin|No.Telp            |"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(fatiri=1;fatiri<fatirjumlah+1;fatiri++)
	{
		cout<<setw(6)<<fatirdata.fatirnama[fatiri]<<setw(10)<<fatirdata.fatiralamat[fatiri]<<setw(10)<<fatirdata.fatirumur[fatiri];
		cout<<setw(10)<<fatirdata.fatirkelamin[fatiri]<<setw(10)<<fatirdata.fatirtelp[fatiri]<<setw(10);
		cout<<endl;
	}
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<endl;
	cin.get();
}