    #include <iostream>
    using namespace std;

    int main(){
        string usn = "Rasya";
        string nim = "123";

        string usnInput;
        string nimInput;
        int dicoba = 0;

        while (dicoba < 3)
        {
            cout << "\nLOGIN" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Masukan UserName: ";
            cin >> usnInput;
            cout << "Masukan Password: ";
            cin >> nimInput;
            
            if (usnInput != usn || nimInput != nim)
            {
                dicoba++;
                cout << "\nLogin gagal silahkan coba lagi" << endl;
                cout << "Sisa percobaan: " << 3 - dicoba << endl;
            } else {
                cout << "Login berhasil" << endl;
                break;
            }
            
        }

        if (dicoba == 3)
        {
            cout << "\nPercobaan melebihi 3 kali. Program dihentikan" << endl;
            return 0;
        }
        

        int select;
        double inputNilai;

        do{
            cout << "\nMenu konversi panjang" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "1. Meter → Kilometer dan Centimeter\n2. Kilometer → Meter dan Centimeter\n3. Centimeter → Meter dan Kilometer\n4. EXIT" << endl;
            cout << "Pilih konversi yang di inginkan (1-4): ";
            cin >> select;
            
            switch (select) {
                case 1:
                    cout << "\nMasukkan nilai Meter: ";
                    cin >> inputNilai;
                    cout << inputNilai << " Meter = " << inputNilai / 1000 << " Kilometer" << endl;
                    cout << inputNilai << " Meter = " << inputNilai * 100 << " Centimeter" << endl;
                    break;

                case 2:
                    cout << "\nMasukkan nilai Kilometer: ";
                    cin >> inputNilai;
                    cout << inputNilai << " Kilometer = " << inputNilai * 1000 << " Meter" << endl;
                    cout << inputNilai << " Kilometer = " << inputNilai * 100000 << " Centimeter" << endl;
                    break;

                case 3:
                    cout << "\nMasukkan nilai Centimeter: ";
                    cin >> inputNilai;
                    cout << inputNilai << " Centimeter = " << inputNilai / 100 << " Meter" << endl;
                    cout << inputNilai << " Centimeter = " << inputNilai / 100000 << " Kilometer" << endl;
                    break;

                case 4:
                    cout << "Anda berhasil keluar" << endl;
                    break;

                default:
                    cout << "select tidak valid!" << endl;
            }
        } while (select != 4);
        
        return 0;
    }