/* Nama = Faathir Akbar Nugroho
   NPM  = 4522210033
   Tugas Besar
   No.2 SI Pembayaran Listrik dengan menggunakan Inputan
   Materi - Struktur
		  - Pointer
		  - ADT SDL Linear Single Linked List
		  - SDL Stack
		  - Bubble Sort Ascending
		  - Sequential Search */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Struktur
struct data
{
    int token = 0;
    int pulsa = 0;
    int hasil = 0;
};

// Pointer Struktur
typedef struct data *DataPtr;

// ADT SDL Linear Single Linked List
struct Node
{
    DataPtr info;
    Node *next;
};

Node *head = NULL;

void insertNode(data);
void displayList();

// Bubble Sort
void bubbleSortAscending(int[], int);
void tukar(int *, int *);

// Sequential Search
int sequentialSearch(int[], int, int);

// SDL Stack
const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void push(int);
int pop();
bool isEmpty();
bool isFull();
int peek();
void isi();
void pulsa();
void belitoken();
void hargatoken();
void tampil(int[], int);
void bayartagihan();
void exitProgram();

int main()
{
    cout << endl;
    int pilih;
    while (true)
    {
        cout << "----------------------------------" << endl;
        cout << "        Pembayaran Listrik        " << endl;
        cout << "----------------------------------" << endl;
        cout << "               Menu               " << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Isi Pulsa                      " << endl;
        cout << "2. Lihat Pulsa                    " << endl;
        cout << "3. Beli Token                     " << endl;
        cout << "4. Harga Token                    " << endl;
        cout << "5. Bayar Tagihan Listrik          " << endl;
        cout << "6. Keluar                         " << endl;
        cout << "----------------------------------" << endl;
        cout << "Pilihan anda :";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            isi();
            break;
        case 2:
            pulsa();
            break;
        case 3:
            belitoken();
            break;
        case 4:
            hargatoken();
            break;
        case 5:
            bayartagihan();
            break;
        case 6:
            exitProgram();
            return 0;
        default:
            cout << endl;
            cout << "Pilihan menu tidak ditemukan" << endl;
        }
    }
}

// Implementasi ADT SDL Linear Single Linked List
void insertNode(data newData)
{
    Node *newNode = new Node;
    newNode->info = new data;
    newNode->info->token = newData.token;
    newNode->info->pulsa = newData.pulsa;
    newNode->info->hasil = newData.hasil;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Implementasi Bubble Sort
void bubbleSortAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                tukar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void tukar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementasi Sequential Search
int sequentialSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Implementasi SDL Stack
void push(int value)
{
    if (isFull())
    {
        cout << "Stack penuh. Tidak dapat menambahkan elemen lagi." << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong. Tidak ada elemen yang dapat dihapus." << endl;
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX_SIZE - 1;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack kosong. Tidak ada elemen yang dapat dilihat." << endl;
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void isi()
{
    int pulsa;

    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "            Isi Pulsa             " << endl;
    cout << "----------------------------------" << endl;
    cout << "Masukkan nominal pulsa : ";
    cin >> pulsa;

    push(pulsa);

    cout << "Pulsa berhasil diisi." << endl;
}

void pulsa()
{
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "            Lihat Pulsa           " << endl;
    cout << "----------------------------------" << endl;
    cout << "Pulsa Anda saat ini: " << peek() << endl;
}

void belitoken()
{
    int token;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "            Beli Token            " << endl;
    cout << "----------------------------------" << endl;
    cout << "Masukkan jumlah token yang ingin dibeli : ";
    cin >> token;

    push(token);

    cout << "Token berhasil dibeli." << endl;
}

void hargatoken()
{
    int n;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "            Harga Token            " << endl;
    cout << "----------------------------------" << endl;
    cout << "Masukkan jumlah harga token yang ingin dilihat : ";
    cin >> n;

    int *tokenPrices = new int[n];
    cout << "Masukkan harga token:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Token ke-" << i + 1 << ": ";
        cin >> tokenPrices[i];
    }

    bubbleSortAscending(tokenPrices, n);
    tampil(tokenPrices, n);

    delete[] tokenPrices;
}

void tampil(int arr[], int n)
{
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "        Harga Token Terurut        " << endl;
    cout << "----------------------------------" << endl;
    cout << "Token\tHarga" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << arr[i] << endl;
    }
    cout << "----------------------------------" << endl;
}

void bayartagihan()
{
    int n, tagihan, posisi;

    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "        Bayar Tagihan Listrik      " << endl;
    cout << "----------------------------------" << endl;
    cout << "Masukkan jumlah tagihan : ";
    cin >> tagihan;

    cout << "Masukkan jumlah token yang tersedia : ";
    cin >> n;

    int *tokens = new int[n];
    cout << "Masukkan token:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Token ke-" << i + 1 << ": ";
        cin >> tokens[i];
    }

    posisi = sequentialSearch(tokens, n, tagihan);

    if (posisi != -1)
    {
        cout << "Tagihan berhasil dibayar dengan menggunakan token seharga " << tokens[posisi] << endl;

        data newData;
        newData.token = tokens[posisi];
        newData.pulsa = pop();
        newData.hasil = newData.pulsa - newData.token;
        insertNode(newData);
    }
    else
    {
        cout << "Tidak ada token yang cukup untuk membayar tagihan sebesar " << tagihan << endl;
    }

    delete[] tokens;
}

void exitProgram()
{
    cout << endl;
    cout << "Terima kasih telah menggunakan program ini." << endl;
    cout << "Program berakhir." << endl;
}