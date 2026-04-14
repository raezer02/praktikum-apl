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

void garis() {
    cout << string(50, '-') << endl;
}

void tampilFilm(Film *film, int jumlah) {
    cout << "No        Judul        Genre        Tahun" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << "        ";
        cout << (film+i)->judul;
        cout << "        ";
        cout << (film+i)->genre << "        " << (film+i)->tahun << endl;
    }
}

void tampilFilm(string isi) {
    cout << "\n" << isi << endl;
}

int inputAngka() {
    int salah;
    while (true) {

        if (cin >> salah) 
        {
            return salah;
        } else {
            cout << "Input harus angka! Masukkan tahun lagi: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int login(User *user, int *jumlahUser, int percobaan) {
    if (percobaan == 3) {
        cout << "\nPercobaan melebihi 3 kali. Program dihentikan\n";
        return 0;
    }

    string usn, nim;
    cout << "\nLogin\n";
    garis();

    cout << "Username : ";
    cin >> usn;
    cout << "Password : ";
    cin >> nim;

    for (int i = 0; i < *jumlahUser; i++) {
        if (usn == (user+i)->username && nim == (user+i)->nim) {
            cout << "\nLogin berhasil\n";
            return 1;
        }
    }

    cout << "Login gagal\n";
    cout << "Sisa percobaan : " << 3 - (percobaan + 1) << endl;

    return login(user, jumlahUser, percobaan + 1);
}

void registerUser(User *user, int *jumlahUser) {
    string usn;
    cout << "\nRegister\n";
    garis();

    cout << "Masukan Username : ";
    cin >> usn;

    for (int i = 0; i < *jumlahUser; i++) {
        if (usn == (user+i)->username) {
            cout << "\nUsername sudah digunakan!\n";
            return;
        }
    }

    (user+(*jumlahUser))->username = usn;

    cout << "Masukan NIM (Password) : ";
    cin >> (user+(*jumlahUser))->nim;

    (*jumlahUser)++;
    cout << "\nRegister berhasil\n";
}


void tambahFilm(Film *film, int *jumlahFilm) {
    tampilFilm("\nTambah Film");
    garis();

    cout << "Judul : ";
    cin >> (film+(*jumlahFilm))->judul;

    cout << "Genre : ";
    cin >> (film+(*jumlahFilm))->genre;

    cout << "Tahun : ";
    (film+(*jumlahFilm))->tahun = inputAngka();

    (*jumlahFilm)++;
    cout << "\nData berhasil ditambah\n";
}

void lihatFilm(Film *film, int *jumlahFilm) {
    tampilFilm("\nDaftar Film");
    garis();

    if (*jumlahFilm == 0) {
        cout << "Belum ada data film\n";
        return;
    }

    tampilFilm(film, *jumlahFilm);
}

void updateFilm(Film *film, int *jumlahFilm) {
    if (*jumlahFilm == 0) {
        cout << "\nData kosong!\n";
        return;
    }

    int pilih;

    lihatFilm(film, jumlahFilm);
    cout << "Pilih yang diubah : ";
    pilih = inputAngka();

    if (pilih < 1 || pilih > *jumlahFilm) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    cout << "Judul baru : ";
    cin >> (film+(pilih-1))->judul;

    cout << "Genre baru : ";
    cin >> (film+(pilih-1))->genre;

    cout << "Tahun baru : ";
    (film+(pilih-1))->tahun = inputAngka();

    cout << "\nData berhasil diubah\n";
}

void hapusFilm(Film *film, int *jumlahFilm) {
    if (*jumlahFilm == 0) {
        cout << "\nData kosong!\n";
        return;
    }

    int pilih;

    lihatFilm(film, jumlahFilm);
    cout << "Pilih yang hapus : ";
    pilih = inputAngka();

    if (pilih < 1 || pilih > *jumlahFilm) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    for (int i = pilih-1; i < (*jumlahFilm)-1; i++) {
        *(film+i) = *(film+i+1);
    }

    (*jumlahFilm)--;
    cout << "\nData berhasil dihapus\n";
}

void bubbleSort(Film *film, int jumlah){
    int pilih_s;
    cout << "\n(1.Ascending/2.Descending): ";
    cin >> pilih_s;
    if (pilih_s == 1)
    {
        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0; j < jumlah - i - 1; j++)
            {
                if ((film+j)->judul > (film+j+1)->judul)
                {
                    swap(*(film+j), *(film+j+1)); 
                }
            }
        }
    }else{
        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0; j < jumlah - i - 1; j++)
            {
                if ((film+j)->judul < (film+j+1)->judul)
                {
                    swap(*(film+j), *(film+j+1)); 
                }
            }
        }
    }
}

void selectionSort(Film *film, int jumlah){
    int pilih_s;
    cout << "\n(1.Ascending/2.Descending): ";
    cin >> pilih_s;
    if (pilih_s == 1)
    {
        for (int i = 0; i < jumlah - 1; i++)
        {
            int idxMax = i;
    
            for (int j = i + 1; j < jumlah; j++)
            {
                if ((film+j)->tahun < (film+idxMax)->tahun)
                {
                    idxMax =  j;
                }
            }
            if (idxMax != i)
            {
                swap(*(film+i), *(film+idxMax));
            }
        }
    }else{
        for (int i = 0; i < jumlah - 1; i++)
        {
            int idxMax = i;
    
            for (int j = i + 1; j < jumlah; j++)
            {
                if ((film+j)->tahun > (film+idxMax)->tahun)
                {
                    idxMax =  j;
                }
            }
            if (idxMax != i)
            {
                swap(*(film+i), *(film+idxMax));
            }
        }
    }
}

void mergeUser(User *user, int left, int mid, int right, int mode){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    User L[15], R[15];

    for (int i = 0; i < n1; i++)
    {
        *(L+i) = *(user+left+i);
    }
    for (int j = 0; j < n2; j++)
    {
        *(R+j) = *(user+mid+1+j);
    }
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (
            (mode == 1 && (L+i)->username <= (R+j)->username) ||
            (mode == 2 && (L+i)->username >= (R+j)->username)
        )
        {
            *(user+k) = *(L+i);
            i++;
        }else{
            *(user+k) = *(R + j);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        *(user+k) = *(L+i);
        i++; k++;
    }
    while (j < n2)
    {
        *(user+k) = *(R+j);
        j++; k++;
    }
}

void mergeSort(User *user, int left, int right, int mode){
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(user, left, mid, mode);
        mergeSort(user, mid + 1, right, mode);
        mergeUser(user, left, mid, right, mode);
    }
}

void lihatUser(User *User, int jumlahUser){
    cout << "\nDaftar User\n";
    garis();
    cout << "No        Username" << endl;
    for (int i = 0; i < jumlahUser; i++)
    {
        cout << i+1 << "        ";
        cout << (User+i)->username;
        cout << "        " << endl;
    }
}

int main() {
    User user[15];
    int jumlahUser = 1;
    
    user[0].username = "Rasya";
    user[0].nim = "123";
    
    Film film[20];
    int jumlahFilm = 0;
    
    int pilih;
    
    while (true)
    {
        cout << "\nPROGRAM PENAMBAHAN FILM BIOSKOP\n";
        garis();
        
        cout << "1. Login\n2. Register\n3. EXIT\nPilih : ";
        pilih = inputAngka();
        
        if (pilih == 1) {
            if (login(user, &jumlahUser, 0)) break;
        }
    
       else if (pilih == 2) {
            registerUser(user, &jumlahUser);
        }
    
        else if (pilih == 3) {
            cout << "\nAnda berhasil keluar\n";
            return 0;
        }
    }
    
    do {
        cout << "\nMenu Utama\n";
        garis();
        cout << "1. Tambah Film\n2. Lihat Film\n3. Update Film\n4. Hapus Film\n5. Sorting Judul\n6. Sorting Tahun\n7. Lihat User\n8. Sorting User\n9. EXIT\n";
        cout << "Pilih menu (1-9): ";
        pilih = inputAngka();

        switch (pilih) {
            case 1: tambahFilm(film, &jumlahFilm); break;
            case 2: lihatFilm(film, &jumlahFilm); break;
            case 3: updateFilm(film, &jumlahFilm); break;
            case 4: hapusFilm(film, &jumlahFilm); break;
            case 5: bubbleSort(film, jumlahFilm); lihatFilm(film, &jumlahFilm); break;
            case 6: selectionSort(film, jumlahFilm); lihatFilm(film, &jumlahFilm); break;
            case 7: lihatUser(user, jumlahUser); break;
            case 8: {
                int pilih_s;
                cout << "\n(1.Ascending/2.Descending): ";
                cin>> pilih_s;
                mergeSort(user, 0, jumlahUser - 1, pilih_s);
                lihatUser(user, jumlahUser); break;}
            case 9: cout << "Anda berhasil keluar\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 9);
}