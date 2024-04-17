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
    vector<Item> items;
public:
    // Method untuk menambahkan item baru
    void add(string name, int price) {
        Item newItem;
        newItem.name = name;
        newItem.price = price;
        items.push_back(newItem);
    }

    // Method untuk menampilkan semua item
    void displayItems() {
        int count = 1;
        for (const auto& item : items) {
            cout << count << ". " << item.name << " - Rp" << item.price << endl;
            count++;
        }
    }

    // Method untuk menghitung total harga item
    int calculateTotal() {
        int total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }

        // Method untuk mendapatkan jumlah item dalam list
    int getNumItems() {
        return items.size();
    }

    // Method untuk mendapatkan item dari list berdasarkan indeks
    Item getItem(int index) {
        // Pastikan indeks valid
        if (index >= 0 && index < items.size()) {
            return items[index];
        } else {
            // Jika indeks tidak valid, kembalikan item default
            return Item{"", 0};
        }
    }
};

int main() {
    List pulsaList;
    pulsaList.add("Pulsa 5k", 5000);
    // Tambahkan item-item pulsa lainnya jika ada

    List kuotaList;
    kuotaList.add("500MB Kuota", 10000);
    // Tambahkan item-item kuota lainnya jika ada

    List paketList;
    paketList.add("500MB Kuota + Pulsa 5k", 15000);
    // Tambahkan item-item paket lainnya jika ada

    // Array untuk menyimpan item-item yang telah dipilih
    vector<Item> shoppingCart;

    int choice;
    int total = 0;
    do {
        menu:
        cout << "\n\n>>>>> E-COUNTER <<<<<" << endl;
        cout << "What you want to buy?" << endl;
        cout << "1. Pulsa" << endl;
        cout << "2. Kuota" << endl;
        cout << "3. Paket (Pulsa + Kuota)" << endl;
        cout << "4. See your cart" << endl;
        cout << "5. Pay" << endl;
        cout << "Please select: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n>>>>> Harga Pulsa <<<<<" << endl;
                pulsaList.displayItems();
                cout << "0. Kembali" << endl;
                int pulsaChoice;
                cout << "Please select: ";
                cin >> pulsaChoice;
                // Pastikan pilihan pulsa valid
                if (pulsaChoice >= 1 && pulsaChoice <= pulsaList.getNumItems()) {
                    // Tambahkan item pulsa ke dalam cart
                    shoppingCart.push_back(pulsaList.getItem(pulsaChoice - 1));
                    // Memperbarui total harga pembelian
                    total += pulsaList.getItem(pulsaChoice - 1).price;
                    cout << "Pulsa added to cart." << endl;
                } else if (pulsaChoice == 0) {
                    goto menu;
                } else {
                    cout << "Invalid pulsa choice." << endl;
                }
                break;
            }
            case 2: {
                cout << "\n>>>>> Harga Kuota <<<<<" << endl;
                kuotaList.displayItems();
                cout << "0. Kembali" << endl;
                int kuotaChoice;
                cout << "Please select: ";
                cin >> kuotaChoice;
                // Pastikan pilihan kuota valid
                if (kuotaChoice >= 1 && kuotaChoice <= kuotaList.getNumItems()) {
                    // Tambahkan item kuota ke dalam cart
                    shoppingCart.push_back(kuotaList.getItem(kuotaChoice - 1));
                    // Memperbarui total harga pembelian
                    total += kuotaList.getItem(kuotaChoice - 1).price;
                    cout << "Kuota added to cart." << endl;
                } else if (kuotaChoice == 0) {
                    goto menu;
                } else {
                    cout << "Invalid kuota choice." << endl;
                }
                break;
            }
            case 3: {
                cout << "\n>>>>> Harga Paket <<<<<" << endl;
                paketList.displayItems();
                cout << "0. Kembali" << endl;
                int paketChoice;
                cout << "Please select: ";
                cin >> paketChoice;
                // Pastikan pilihan paket valid
                if (paketChoice >= 1 && paketChoice <= paketList.getNumItems()) {
                    // Tambahkan item paket ke dalam cart
                    shoppingCart.push_back(paketList.getItem(paketChoice - 1));
                    // Memperbarui total harga pembelian
                    total += paketList.getItem(paketChoice - 1).price;
                    cout << "Paket added to cart." << endl;
                } else if (paketChoice == 0) {
                    goto menu;
                } else {
                    cout << "Invalid paket choice." << endl;
                }
                break;
            }
            case 4: {
                carr:
                cout << "\n===== Your Shopping Cart Item =====" << endl;
                // Tampilkan item-item yang telah dipilih beserta total harga
                if (shoppingCart.empty()) {
                    cout << "Your cart is empty." << endl;
                } else {
                    cout << "Items in your cart:" << endl;
                    int count = 1;
                    for (const auto& item : shoppingCart) {
                        cout << count << ". " << item.name << " - Rp" << item.price << endl;
                        count++;
                    }
                    cout << "Total price: Rp" << total << endl;
                }

                cout << "\n1. Hapus Item" << endl;
                cout << "0. Kembali" << endl;
                int cart;
                cout << "Please select: ";
                cin >> cart;

                if (cart == 1) {
                    int removeChoice;
                    cout << "Please select the item to remove (enter item number): ";
                    cin >> removeChoice;
                    if (removeChoice >= 1 && removeChoice <= shoppingCart.size()) {
                        // Hapus item dari shopping cart
                        total -= shoppingCart[removeChoice - 1].price;
                        shoppingCart.erase(shoppingCart.begin() + removeChoice - 1);
                        cout << "Item removed from cart." << endl;
                        goto carr;
                    } else {
                        cout << "Invalid item number." << endl;
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
                cout << "\n>>>>> Select Payment Method <<<<<" << endl;
                cout << "1. BCA" << endl;
                cout << "2. Dana" << endl;
                cout << "3. Gopay" << endl;
                cout << "0. Kembali" << endl;
                int paymentChoice;
                pay:
                cout << "Please select: ";
                cin >> paymentChoice;
                
                switch (paymentChoice)
                {
                case 1: {
                    cout << "\n===== BANK PAYMENT =====" << endl;
                    cout << "\nBCA : 09124812734" << endl;
                    cout << "BNI: 091274102" << endl;
                    cout << "Jago: 19027409123" << endl;
                    break;
                }
                case 2: {
                    cout << "\n===== Dana PAYMENT =====" << endl;
                    cout << "\n AN: Rifky Dwi Mahardika: 0912841092" << endl;
                    cout << "AN: Muhammad Aulia Muzzaki: 091274102" << endl;
                    cout << "AN: Falah Asbi: 19027409123" << endl;
                    break;
                }
                case 3: {
                    cout << "\n===== Gopay PAYMENT =====" << endl;
                    cout << "\n AN: Rifky Dwi Mahardika: 0912841092" << endl;
                    cout << "AN: Muhammad Aulia Muzzaki: 091274102" << endl;
                    cout << "AN: Falah Asbi: 19027409123" << endl;
                    cout << "AN: Raka Andriy Shevchenko: 082138353355" << endl;
                    break;
                }

                case 0: {
                    goto menu;
                    break;
                }

                default:
                    cout << "Harap masukkan angka yang sesuai." << endl;
                    break;
                    goto pay;
                }

                cout << "\nTransfer cukup 1(satu) kali, ke salah satu tujuan yang tertera." << endl;

                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    cout << "\nYour item will be delivered after we confirmed your payment." << endl;
    cout << "Thank you for shopping at our E-Counter!" << endl;

    return 0;
}
