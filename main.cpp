#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Ürün yapısı
struct Product {
    string name;
    string barcode;

    Product(string n, string b) : name(n), barcode(b) {}
};

// Müsteri yapısı
class Customer {
private:
    string name;

public:
    Customer(string n) : name(n) {}

    string getName() const {
        return name;
    }
};

// Market sınıfı
class Market {
private:
    map<string, string> products;

public:
    // Yeni bir ürün eklemek için fonksiyon
    void addProduct(const string& barcode, const string& name) {
        products[barcode] = name;
    }

    // Bir ürünü listeden silmek için fonksiyon
    void removeProduct(const string& barcode) {
        products.erase(barcode);
    }

    // Ürünleri listelemek için fonksiyon
    void listProducts() {
        cout << "Barkod No\tUrun Adi" << endl;
        for (const auto& pair : products) {
            cout << pair.first << "\t\t" << pair.second << endl;
        }
    }
};

// Kasa sınıfı
class Cashier {
private:
    queue<Customer> queueCustomers; // Müsteri kuyruğu

public:
    void addCustomer(const Customer& customer) {
        queueCustomers.push(customer);
    }
    void serveCustomer() {
        if (!queueCustomers.empty()) {
            cout << "Kasiyer " << queueCustomers.front().getName() << " adli musteriye hizmet veriyor." << endl;
            queueCustomers.pop();
        } else {
            cout << "Kuyrukta hic musteri yok!" << endl;
        }
    }
};

int main() {
    Market market;
    Cashier cashier;

    // Örnek ürünler ekleniyor
    market.addProduct("1", "Ekmek");
    market.addProduct("2", "Su");
    market.addProduct("3", "Pirinc");
    market.addProduct("4", "Domates");
    market.addProduct("5", "Sabun");
    market.addProduct("6", "Sampuan");
    market.addProduct("7", "Camasir Suyu");
    market.addProduct("8", "Pil");
    market.addProduct("9", "Ampul");
    market.addProduct("10", "Usb");

    // Ürünler listeleniyor
    market.listProducts();

    // Örnek bir ürün siliniyor
    market.removeProduct("5");

    // Ürünler tekrar listeleniyor
    cout << "\nBir urun silindikten sonra:" << endl;
    market.listProducts();

    // Örnek müsteriler olusturuluyor ve kuyruğa ekleniyor
    Customer customer1("Ahmet");
    Customer customer2("Ayse");
    Customer customer3("Mehmet");

    cashier.addCustomer(customer1);
    cashier.addCustomer(customer2);
    cashier.addCustomer(customer3);

    // Müsterilere sırasıyla hizmet veriliyor
    cashier.serveCustomer();
    cashier.serveCustomer();
    cashier.serveCustomer();
    cashier.serveCustomer();

    return 0;
}
