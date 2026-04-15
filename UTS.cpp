#include <iostream>
#include <vector>
using namespace std;

// Struct untuk data tugas
struct Tugas {
    int id;
    string nama;
    string matkul;
    string deadline;
};

// Class utama
class ManajemenTugas {
private:
    vector<Tugas> data; // dynamic array

public:
    // Tambah data
    void tambahTugas() {
        Tugas t;
        cout << "ID Tugas: ";
        cin >> t.id;
        cin.ignore();

        cout << "Nama Tugas: ";
        getline(cin, t.nama);

        cout << "Mata Kuliah: ";
        getline(cin, t.matkul);

        cout << "Deadline: ";
        getline(cin, t.deadline);

        data.push_back(t);
        cout << "Tugas berhasil ditambahkan!\n";
    }

    // Tampilkan data
    void tampilkanTugas() {
        if (data.empty()) {
            cout << "Data kosong!\n";
            return;
        }

        for (int i = 0; i < data.size(); i++) {
            cout << "\nID: " << data[i].id;
            cout << "\nNama: " << data[i].nama;
            cout << "\nMatkul: " << data[i].matkul;
            cout << "\nDeadline: " << data[i].deadline << endl;
        }
    }

    // Hapus data
    void hapusTugas() {
        int id;
        cout << "Masukkan ID yang ingin dihapus: ";
        cin >> id;

        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                data.erase(data.begin() + i);
                cout << "Data berhasil dihapus!\n";
                return;
            }
        }
        cout << "Data tidak ditemukan!\n";
    }

    // Update data
    void updateTugas() {
        int id;
        cout << "Masukkan ID yang ingin diupdate: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                cout << "Nama baru: ";
                getline(cin, data[i].nama);

                cout << "Matkul baru: ";
                getline(cin, data[i].matkul);

                cout << "Deadline baru: ";
                getline(cin, data[i].deadline);

                cout << "Data berhasil diupdate!\n";
                return;
            }
        }
        cout << "Data tidak ditemukan!\n";
    }

    // Sorting manual (Bubble Sort berdasarkan ID)
    void sortingTugas() {
        int n = data.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j].id > data[j + 1].id) {
                    // tukar data
                    Tugas temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }

        cout << "Data berhasil diurutkan secara manual (Bubble Sort)!\n";
    }
};

// Main program (menu CLI)
int main() {
    ManajemenTugas mt;
    int pilihan;

    do {
        cout << "\n=== SISTEM MANAJEMEN TUGAS MAHASISWA ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Tampilkan Tugas\n";
        cout << "3. Update Tugas\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Sorting Tugas\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: mt.tambahTugas(); break;
            case 2: mt.tampilkanTugas(); break;
            case 3: mt.updateTugas(); break;
            case 4: mt.hapusTugas(); break;
            case 5: mt.sortingTugas(); break;
            case 0: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}