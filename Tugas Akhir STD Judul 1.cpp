#include <iostream>
#include <limits>   
#include <new>      

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* create_node(int value);
void insert_at_front(Node* node);
void insert_at_end(Node* node);
void display_list();
void delete_front();
void clear_all();
int read_int_with_prompt(const string& prompt);

int main() {
    cout << "=== Single Linked List - Praktikum ===\n";
    cout << "Implementasi: insert depan, insert belakang, tampil, hapus depan\n\n";

    bool running = true;
    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Insert di Depan\n";
        cout << "2. Insert di Belakang\n";
        cout << "3. Tampilkan List\n";
        cout << "4. Hapus Node Pertama (Delete Front)\n";
        cout << "5. Keluar\n";
        int choice = read_int_with_prompt("Pilih menu (1-5): ");

        switch (choice) {
            case 1: {
                int val = read_int_with_prompt("Masukkan nilai untuk node (int): ");
                Node* n = create_node(val);
                if (!n) {
                    cout << "Gagal membuat node (alokasi memori). Program akan keluar.\n";
                    clear_all();
                    return 1;
                }
                insert_at_front(n);
                cout << "Node dengan nilai " << val << " dimasukkan di depan.\n";
                break;
            }
            case 2: {
                int val = read_int_with_prompt("Masukkan nilai untuk node (int): ");
                Node* n = create_node(val);
                if (!n) {
                    cout << "Gagal membuat node (alokasi memori). Program akan keluar.\n";
                    clear_all();
                    return 1;
                }
                insert_at_end(n);
                cout << "Node dengan nilai " << val << " dimasukkan di belakang.\n";
                break;
            }
            case 3:
                cout << "Isi list: ";
                display_list();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                cout << "Keluar. Membersihkan memori...\n";
                clear_all();
                running = false;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1-5.\n";
                break;
        }
    }

    cout << "Program selesai.\n";
    return 0;
}

Node* create_node(int value) {
    Node* p = new (nothrow) Node;
    if (p == nullptr) return nullptr;
    p->data = value;
    p->next = nullptr;
    return p;
}

void insert_at_front(Node* node) {
    if (head == nullptr) {
        head = tail = node;
    } else {
        node->next = head;
        head = node;
    }
}

void insert_at_end(Node* node) {
    if (head == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void display_list() {
    if (head == nullptr) {
        cout << "<kosong>\n";
        return;
    }
    Node* cur = head;
    bool first = true;
    while (cur != nullptr) {
        if (!first) cout << " -> ";
        cout << cur->data;
        first = false;
        cur = cur->next;
    }
    cout << "\n";
}

void delete_front() {
    if (head == nullptr) {
        cout << "List kosong. Tidak ada node yang dihapus.\n";
        return;
    }
    Node* tmp = head;
    head = head->next;
    cout << "Menghapus node pertama dengan nilai " << tmp->data << "\n";
    delete tmp;
    if (head == nullptr) {
        tail = nullptr;
    }
}

void clear_all() {
    while (head != nullptr) {
        delete_front();
    }
}

int read_int_with_prompt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        } else {
            cout << "Input tidak valid. Masukkan bilangan bulat.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

