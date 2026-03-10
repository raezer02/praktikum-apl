#include <iostream>
using namespace std;

struct User {
    string username;
    string nim;
};

struct Film {
    string judul;
    string genre;
    int tahun;
};

int main() {
    User user[15];
    int jumlahUser = 1;

    user[0].username = "Rasya";
    user[0].nim = "123";

    Film film[20];
    int jumlahFilm = 0;

    int pilihanAwal;

    cout << "PROGRAM PENAMBAHAN FILM BIOSKOP" << endl;
    cout << string(50, '-') << endl;
    cout << "1. Login";
    cout << "\n2. Register";
    cout << "\n3. EXIT";
    cout << "\nPilih :";
    cin >> pilihanAwal;

    if (pilihanAwal == 2)
    {
        string usnbaru;

        cout << "\nRegister" << endl;
        cout << string(50, '-') << endl;
        cout << "Masukan Username : ";
        cin >> usnbaru;

        if (usnbaru == user[0].username)
        {
            cout << "\nUsername sudah digunakan!" << endl;
        }else{
            cin >> user[jumlahUser].username;
            
            cout << "Masukan NIM (Password) : ";
            cin >> user[jumlahUser].nim;
            
            jumlahUser++;
            cout << "Register berhasil\n";
        }
        
    }
    if (pilihanAwal == 3)
    {
        cout << "\nAnda berhasil keluar";
        return 0;
    }
    
    

    string usnInput,nimInput;
    int dicoba = 0;
    bool login = false;

    while (dicoba < 3)
    {
        cout << "\nLogin" << endl;
        cout << string(50, '-') << endl;

        cout << "Username : ";
        cin >> usnInput;

        cout << "Password : ";
        cin >> nimInput;
        
        for (int i = 0; i < jumlahUser; i++)
        {
            if (usnInput == user[i].username && nimInput == user[i].nim)
            {
                login = true;
                break;
            }
            
        }
        if (login)
        {
            cout << "\nLogin berhasil" << endl;
            break;
        }else{
            dicoba++;
            cout << "Login gagal" << endl;
            cout << "Sisa percobaan : " << 3 - dicoba << endl;

            if (dicoba == 3)
            {
                cout << "nPercobaan melebihi 3 kali. Program dihentikan" << endl;
                return 0;
            }
            
        }
        


    }

    int select;

    do
    {
        cout << "\nMenu Utama" << endl;
        cout << string(50, '-') << endl;
        cout << "1. Tambah Film\n2. Lihat Film\n3. Update Film\n4. Hapus Film\n5. EXIT" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> select;

        switch (select) {
            case 1:
                cout << "\nTambah Film" << endl;
                cout << string(50, '-') << endl;
                cout << "Judul : ";
                cin >> film[jumlahFilm].judul;

                cout << "Genre : ";
                cin >> film[jumlahFilm].genre;

                cout << "Tahun : ";
                while (!(cin >> film[jumlahFilm].tahun))
                {
                    cout << "Input harus angka! Masukkan tahun lagi: ";
                    cin.clear(); 
                    cin.ignore(1000, '\n');
                }

                jumlahFilm++;

                cout << "\nData berhasil ditambah" << endl;
                break;

            case 2:
                cout << "\nDaftar Film" << endl;
                cout << string(50, '-') << endl;
                cout << "No        Judul        Genre        Tahun" << endl;

                for (int i = 0; i < jumlahFilm; i++)
                {
                    cout << i+1 << "        ";
                    cout << film[i].judul << "        ";
                    cout << film[i].genre << "        ";
                    cout << film[i].tahun << endl;
                }
                break;

            case 3:
                int ubah;

                cout << "\nUpdate Film" << endl;
                cout << string(50, '-') << endl;
                cout << "No        Judul        Genre        Tahun" << endl;

                for (int i = 0; i < jumlahFilm; i++)
                {
                    cout << i+1 << "        ";
                    cout << film[i].judul << "        ";
                    cout << film[i].genre << "        ";
                    cout << film[i].tahun << endl;
                }
                cout << "Pilih yang diubah : ";
                cin >> ubah;

                cout << "Judul baru : ";
                cin >> film[ubah-1].judul;

                cout << "Genre baru : ";
                cin >> film[ubah-1].genre;

                cout << "Tahun baru : ";
                cin >> film[ubah-1].tahun;
                cout << "\nData berhasil diubah" << endl;
                break;

            case 4:
            int hapus;
                cout << "\nHapus Film" << endl;
                cout << string(50, '-') << endl;
                cout << "No        Judul        Genre        Tahun" << endl;

                for (int i = 0; i < jumlahFilm; i++)
                    {
                        cout << i+1 << "        ";
                        cout << film[i].judul << "        ";
                        cout << film[i].genre << "        ";
                        cout << film[i].tahun << endl;
                    }
                cout << "Pilih yang hapus : ";
                cin >> hapus;

                for(int i=hapus-1;i<jumlahFilm-1;i++){
                    film[i] = film[i+1];
                }
                jumlahFilm--;
                cout << "\nData berhasil hapus" << endl;
                break;
            
            case 5:
                cout << "Anda berhasil keluar" << endl;
                break;
            default:
                cout << "select tidak valid!" << endl;
        }

    } while (select != 5);
    
    
}