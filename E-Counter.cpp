#include <iostream>
#include <vector>
using namespace std;

// Struct untuk merepresentasikan item
struct Item {
    string name;
    int price;
};

// Class List untuk menyimpan dan mengelola item-item yang tersedia
class List {
private:
    vector<Item> items; // Vektor untuk menyimpan item-item
public:
    // Method untuk menambahkan item baru
    void add(string name, int price) {
        Item newItem;
        newItem.name = name;
        newItem.price = price;
        items.push_back(newItem); // Menambahkan item baru ke vektor
    }

    // Method untuk menampilkan semua item
    void displayItems() {
        int count = 1;
        for (const auto& item : items) {
            cout << count << ". " << item.name << " - Rp" << item.price << endl; // Menampilkan nama dan harga item
            count++;
        }
    }

    // Method untuk menghitung total harga item
    int calculateTotal() {
        int total = 0;
        for (const auto& item : items) {
            total += item.price; // Menambahkan harga item ke total
        }
        return total;
    }

    // Method untuk mendapatkan jumlah item dalam list
    int getNumItems() {
        return items.size(); // Mengembalikan jumlah item dalam vektor
    }

    // Method untuk mendapatkan item dari list berdasarkan indeks
    Item getItem(int index) {
        // Pastikan indeks valid
        if (index >= 0 && index < items.size()) {
            return items[index]; // Mengembalikan item dengan indeks tertentu
        } else {
            // Jika indeks tidak valid, kembalikan item default
            return Item{"", 0};
        }
    }
};

int main() {
    List pulsaList;
    // Menambahkan item-item pulsa ke dalam pulsaList
    pulsaList.add("Pulsa 25.000", 27000);
    pulsaList.add("Pulsa 50.000", 52000);
    pulsaList.add("Pulsa 100.000", 102000);

    List kuotaList;
    // Menambahkan item-item kuota ke dalam kuotaList
    kuotaList.add("1GB Kuota, 7 Hari Masa Aktif", 10000);
    kuotaList.add("5GB Kuota, 1 Bulan Masa Aktif", 35000);
    kuotaList.add("50GB Kuota, 1 Bulan Masa Aktif", 100000);

    List paketList;
    // Menambahkan item-item paket ke dalam paketList
    paketList.add("10GB Kuota (7 Hari) + Pulsa 25", 50000);
    paketList.add("25GB Kuota (30 Hari) + Pulsa 50k", 100000);
    paketList.add("75GB Kuota (30 Hari) + Pulsa 100k", 200000);

    // Array untuk menyimpan item-item yang tersedia
    vector<List> availableItems = {pulsaList, kuotaList, paketList};

    // Array untuk menyimpan item-item yang telah dipilih
    vector<Item> shoppingCart;

    int choice;
    int total = 0;
    do {
        menu:
        // Menampilkan menu utama
        cout << "\n\n>>>>> E-COUNTER ARRZ <<<<<" << endl;
        cout << "Apa Yang Ingin Anda Beli?" << endl;
        cout << "1. Pulsa" << endl;
        cout << "2. Kuota" << endl;
        cout << "3. Paket (Pulsa + Kuota)" << endl;
        cout << "4. Lihat Keranjang" << endl;
        cout << "5. Bayar" << endl;
        cout << "Harap Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Memilih kategori pulsa dan menambahkan item ke keranjang belanja
                cout << "\n>>>>> Harga Pulsa <<<<<" << endl;
                pulsaList.displayItems();
                cout << "0. Kembali" << endl;
                int pulsaChoice;
                cout << "Harap Pilih: ";
                cin >> pulsaChoice;
                // Pastikan pilihan pulsa valid
                if (pulsaChoice >= 1 && pulsaChoice <= pulsaList.getNumItems()) {
                    shoppingCart.push_back(pulsaList.getItem(pulsaChoice - 1));
                    total += pulsaList.getItem(pulsaChoice - 1).price;
                    cout << "Berhasil ditambah ke keranjang." << endl;
                } else if (pulsaChoice == 0) {
                    goto menu;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            }
            case 2: {
                // Memilih kategori kuota dan menambahkan item ke keranjang belanja
                cout << "\n>>>>> Harga Kuota <<<<<" << endl;
                kuotaList.displayItems();
                cout << "0. Kembali" << endl;
                int kuotaChoice;
                cout << "Harap Pilih: ";
                cin >> kuotaChoice;
                // Pastikan pilihan kuota valid
                if (kuotaChoice >= 1 && kuotaChoice <= kuotaList.getNumItems()) {
                    shoppingCart.push_back(kuotaList.getItem(kuotaChoice - 1));
                    total += kuotaList.getItem(kuotaChoice - 1).price;
                    cout << "Berhasil ditambah ke keranjang." << endl;
                } else if (kuotaChoice == 0) {
                    goto menu;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            }
            case 3: {
                // Memilih kategori paket dan menambahkan item ke keranjang belanja
                cout << "\n>>>>> Harga Paket <<<<<" << endl;
                paketList.displayItems();
                cout << "0. Kembali" << endl;
                int paketChoice;
                cout << "Harap Pilih: ";
                cin >> paketChoice;
                // Pastikan pilihan paket valid
                if (paketChoice >= 1 && paketChoice <= paketList.getNumItems()) {
                    shoppingCart.push_back(paketList.getItem(paketChoice - 1));
                    total += paketList.getItem(paketChoice - 1).price;
                    cout << "Berhasil ditambah ke keranjang." << endl;
                } else if (paketChoice == 0) {
                    goto menu;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            }
            case 4: {
                carr:
                // Menampilkan keranjang belanja
                cout << "\n===== Keranjang Belanja Anda =====" << endl;
                if (shoppingCart.empty()) {
                    cout << "Keranjang anda masih kosong :(" << endl;
                } else {
                    cout << "Item yang ada di keranjang:" << endl;
                    int count = 1;
                    for (const auto& item : shoppingCart) {
                        cout << count << ". " << item.name << " - Rp" << item.price << endl;
                        count++;
                    }
                    cout << "\nHarga Total: Rp" << total << endl;
                }

                cout << "\n1. Hapus Item" << endl;
                cout << "2. Ganti Item" << endl;
                cout << "0. Kembali" << endl;
                int cart;
                cout << "Harap Pilih: ";
                cin >> cart;

                if (cart == 1) {
                    // Menghapus item dari keranjang belanja
                    int removeChoice;
                    cout << "Pilih item yang ingin dihapus (masukkan nomor item): ";
                    cin >> removeChoice;
                    if (removeChoice >= 1 && removeChoice <= shoppingCart.size()) {
                        total -= shoppingCart[removeChoice - 1].price;
                        shoppingCart.erase(shoppingCart.begin() + removeChoice - 1);
                        cout << "Item berhasil dihapus dari keranjang" << endl;
                        goto carr;
                    } else {
                        cout << "Pilihan tidak valid." << endl;
                    }
                } else if (cart == 2) {
                    // Mengganti item di keranjang belanja
                    int updateIndex;
                    cout << "Pilih item yang hendak diubah (masukkan nomor item): ";
                    cin >> updateIndex;

                    if (updateIndex >= 1 && updateIndex <= shoppingCart.size()) {
                        cout << "\n===== Item Yang Tersedia =====" << endl;
                        cout << "1. Pulsa" << endl;
                        pulsaList.displayItems();
                        cout << "\n2. Kuota" << endl;
                        kuotaList.displayItems();
                        cout << "\n3. Paket" << endl;
                        paketList.displayItems();
                        cout << "\n0. Kembali" << endl;

                        int newItemIndex;
                        cout << "\nPilih Kategori Item (masukkan nomor): ";
                        cin >> newItemIndex;

                        if (newItemIndex >= 1 && newItemIndex <= availableItems.size()) {
                            // Mendapatkan item baru
                            Item newItem;
                            if (newItemIndex == 1) {
                                // Pilihan item adalah dari pulsaList
                                int pulsaChoice;
                                cout << "Ingin yang mana?: ";
                                cin >> pulsaChoice;
                                if (pulsaChoice >= 1 && pulsaChoice <= pulsaList.getNumItems()) {
                                    newItem = pulsaList.getItem(pulsaChoice - 1);
                                } else {
                                    cout << "Pilihan tidak valid." << endl;
                                    break;
                                }
                            } else if (newItemIndex == 2) {
                                // Pilihan item adalah dari kuotaList
                                int kuotaChoice;
                                cout << "Ingin yang mana?: ";
                                cin >> kuotaChoice;
                                if (kuotaChoice >= 1 && kuotaChoice <= kuotaList.getNumItems()) {
                                    newItem = kuotaList.getItem(kuotaChoice - 1);
                                } else {
                                    cout << "Pilihan tidak valid." << endl;
                                    break;
                                }
                            } else if (newItemIndex == 3) {
                                // Pilihan item adalah dari paketList
                                int paketChoice;
                                cout << "Ingin yang mana?: ";
                                cin >> paketChoice;
                                if (paketChoice >= 1 && paketChoice <= paketList.getNumItems()) {
                                    newItem = paketList.getItem(paketChoice - 1);
                                } else {
                                    cout << "Pilihan tidak valid." << endl;
                                    break;
                                }
                            } else {
                                cout << "Pilihan tidak valid." << endl;
                                break;
                            }

                            // Menghitung kembali total harga setelah mengganti item di keranjang belanja
                            total -= shoppingCart[updateIndex - 1].price;
                            total += newItem.price;
                            shoppingCart[updateIndex - 1] = newItem;
                            cout << "Item berhasil diubah." << endl;
                        } else if (newItemIndex == 0) {
                            goto menu;
                        } else {
                            cout << "Pilihan tidak valid." << endl;
                        }
                    } else {
                        cout << "Pilihan tidak valid." << endl;
                    }
                } else if (cart == 0) {
                    goto menu;
                } else {
                    cout << "Harap pilih angka yang tersedia." << endl;
                    goto carr;
                }
                break;
            }
            case 5: {
                // Memilih metode pembayaran
                cout << "\n>>>>> Harap Pilih Metode Pembayaran <<<<<" << endl;
                cout << "1. BCA" << endl;
                cout << "2. Dana" << endl;
                cout << "3. Gopay" << endl;
                cout << "0. Kembali" << endl;
                int paymentChoice;
                pay:
                cout << "Harap Pilih: ";
                cin >> paymentChoice;
                
                switch (paymentChoice) {
                    case 1: {
                        // Menampilkan informasi rekening BCA
                        cout << "\n===== BANK PAYMENT =====" << endl;
                        cout << "\nBCA: AN: Rifky Dwi Mahardika: 09124812734" << endl;
                        cout << "BNI: AN: Rifky Dwi Mahardika: 091274102" << endl;
                        cout << "Jago: AN: Rifky Dwi Mahardika: 19027409123" << endl;
                        break;
                    }
                    case 2: {
                        // Menampilkan informasi rekening Dana
                        cout << "\n===== Dana PAYMENT =====" << endl;
                        cout << "\n AN: Rifky Dwi Mahardika: 0912841092" << endl;
                        cout << "AN: Muhammad Aulia Muzzaki: 091274102" << endl;
                        cout << "AN: Falah Asbi: 19027409123" << endl;
                        break;
                    }
                    case 3: {
                        // Menampilkan informasi rekening Gopay
                        cout << "\n===== Gopay PAYMENT =====" << endl;
                        cout << "\n AN: Rifky Dwi Mahardika: 0912841092" << endl;
                        cout << "AN: Muhammad Aulia Muzzaki: 091274102" << endl;
                        cout << "AN: Falah Asbi: 19027409123" << endl;
                        cout << "AN: Raka Andriy Shevchenko: 082138353355" << endl;
                        break;
                    }
                    case 0: {
                        goto menu; // Kembali ke menu utama
                        break;
                    }
                    default:
                        cout << "Harap masukkan angka yang sesuai." << endl;
                        break;
                        goto pay; // Kembali ke pemilihan metode pembayaran
                }

                cout << "\nTransfer cukup 1(satu) kali, ke salah satu tujuan yang tertera." << endl;

                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 5); // Ulangi hingga pilihan adalah untuk keluar

    // Pesan akhir setelah pembelian
    cout << "\nPesanan anda akan kami kirim setelah melakukan verifikasi pembayaran." << endl;
    cout << "Terima kasih telah berbelanja di E-Counter ARRZ." << endl;
    cout << "Gacor kang!" << endl;

    return 0;
}
