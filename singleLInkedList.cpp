#include <iostream>
using namespace std;

struct Node
{
    string nrp;
    string nama;
    int nilai;
    Node *next;
};

struct LinkedList
{
private:
    Node *head;
    Node *tail;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(string nrp, string nama, int nilai)
    {
        Node* tmp = new Node();
        tmp->nrp = nrp;
        tmp->nama = nama;
        tmp->nilai = nilai;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void addfirst(string nrp, string nama, int nilai)
    {
        Node* tmp = new Node();
        tmp->nrp = nrp;
        tmp->nama = nama;
        tmp->nilai = nilai;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }

    void remove(string nrp)
    {
        Node *cur = head;
        Node *prev = NULL;

        while(cur != NULL)
        {
            if(cur->nrp == nrp)
            {
                if(prev == NULL)
                {
                    head = cur->next;
                }
                else
                {
                    prev->next = cur->next;
                }
                delete cur;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    void insert(string nrp, string nama, int nilai, string posisi)
    {
        Node* tmp = new Node();
        tmp->nrp = nrp;
        tmp->nama = nama;
        tmp->nilai = nilai;
        tmp->next = NULL;

        Node *cur = head;
        Node *prev = NULL;

        while(cur != NULL)
        {
            if(cur->nrp == posisi)
            {
                if(prev == NULL)
                {
                    tmp->next = head;
                    head = tmp;
                }
                else
                {
                    tmp->next = cur;
                    prev->next = tmp;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    void printList()
    {
        Node *cur = head;
        while(cur != NULL)
        {
            cout << cur->nrp << "\t" << " ";
            cout << cur->nama << "\t" << " ";
            cout << cur->nilai << "\t" << " ";
            cout << endl;

            cur = cur->next;
        }
        cout << "----------------------------" << endl;
    }
};

LinkedList myList;
    void tambahdata()
    {
        string nrp;
        string nama;
        int nilai;

        cout << "\n-------Masukkan Data--------" << endl;
        cout << "Masukkan NRP : ";
        cin >> nrp;
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan Nilai : ";
        cin >> nilai;
        cout << "----------------------------" << endl;

        myList.add(nrp, nama, nilai);
    }

    void tambahdatadepan()
    {
        string nrp;
        string nama;
        int nilai;

        cout << "\n-------Masukkan Data--------" << endl;
        cout << "Masukkan NRP : ";
        cin >> nrp;
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan Nilai : ";
        cin >> nilai;
        cout << "----------------------------" << endl;

        myList.addfirst(nrp, nama, nilai);
    }

    void remove()
    {
        string nrp;
        cout << "\n-------Masukkan Data--------" << endl;
        cout << "Masukkan NRP yang ingin dihapus : ";
        cin >> nrp;
        cout << "----------------------------" << endl;

        myList.remove(nrp);
    }

    void sisipkandata()
    {
        string nrp;
        string nama;
        int nilai;
        string posisi;

        cout << "\n-------Masukkan Data--------" << endl;
        cout << "Masukkan NRP : ";
        cin >> nrp;
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan Nilai : ";
        cin >> nilai;
        cout << "Masukkan Posisi : ";
        cin >> posisi;
        cout << "----------------------------" << endl;

        myList.insert(nrp, nama, nilai, posisi);

    }

    void printList()
    {
        myList.printList();
    }

    void menu()
    {
        int pilihan;
        do
        {
            cout << "\n-*******-Daftar Menu-******-" << endl;
            cout << "1. Tambah Data" << endl;
            cout << "2. Tampilkan Data" << endl;
            cout << "3. Tambah Data Depan" << endl;
            cout << "4. Hapus Data" << endl;
            cout << "5. Sisipkan Data" << endl;
            cout << "6. Keluar" << endl;
            cout << "****************************" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilihan;

            switch(pilihan)
            {
                case 1:
                    tambahdata();
                    break;
                case 2:
                    cout << "\n--*----Data Mahasiswa----*--" << endl;
                    cout << "NRP\t" << "Nama\t" << "Nilai" << endl;
                    printList();
                    break;
                case 3:
                    tambahdatadepan();
                    break;
                case 4:
                    remove();
                    break;
                case 5:
                    sisipkandata();
                    break;
                default:
                    cout << "*****--******--******--*****" << endl;
                    break;
            }
        } while(pilihan != 6);
    }

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
