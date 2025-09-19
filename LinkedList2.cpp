#include <iostream>
#include <cstdlib> // for exit
#include <new>     // for nothrow

using namespace std;

struct node {
    int data;
    node *prev;
    // Modul Praktikum Struktur Data 2025 12 (komentar)
    node *next;
} *start, *newptr, *ptr, *rear;

node *create_new_node(int);
void insert_node(node *);
void traverseForward(node *);
void traverseBackward(node *);

int main() {
    start = rear = nullptr;
    int c;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "Nilai baru = ";
        if (!(cin >> c)) {
            cout << "Input tidak valid. Program dihentikan." << endl;
            return 1;
        }
        cout << "Membuat node baru" << endl;

        newptr = create_new_node(c);
        if (newptr != nullptr) {
            cout << "Berhasil membuat node baru" << endl;
        } else {
            cout << "Node baru tidak dapat dibuat" << endl;
            exit(1);
        }

        insert_node(newptr);
        cout << "Node dimasukkan ke list" << endl;
        cout << "Mau membuat node baru? (y/n)";
        cin >> choice;
    }

    int direction;
    cout << "1. Maju" << endl;
    cout << "2. Mundur" << endl;
    cout << "Arah traversal yang mana?";
    cin >> direction;

    switch (direction) {
        case 1:
            cout << "Traversal maju: ";
            traverseForward(start);
            break;
        case 2:
            cout << "Traversal mundur: ";
            traverseBackward(rear);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}

node *create_new_node(int n) {
    ptr = new (nothrow) node;
    if (ptr == nullptr) return nullptr;
    ptr->data = n;
    ptr->prev = nullptr;
    ptr->next = nullptr;
    return ptr;
}

void insert_node(node *np) {
    if (start == nullptr) {
        start = rear = np;
        np->prev = nullptr;
        np->next = nullptr;
    } else {
        np->prev = rear;
        np->next = nullptr;
        rear->next = np;
        rear = np;
    }
}

void traverseForward(node *head) {
    node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void traverseBackward(node *tail) {
    node *current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
