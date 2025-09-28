#include <iostream>
#include <string>
using namespace std;

struct Card {
    int suit; // 0=Clubs,1=Diamonds,2=Hearts,3=Spades
    int rank; // 2..14 (11=J,12=Q,13=K,14=A)
};

const string SUIT_NAMES[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string RANK_NAMES[15] = {
    "?", "?", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
};

string cardToString(const Card &c) {
    return RANK_NAMES[c.rank] + " of " + SUIT_NAMES[c.suit];
}

bool cardLess(const Card &a, const Card &b) {
    if (a.suit != b.suit) return a.suit < b.suit;
    return a.rank < b.rank;
}

void printArray(const Card arr[], int n, const string &title = "") {
    if (!title.empty()) cout << title << '\n';
    for (int i = 0; i < n; ++i) {
        cout << cardToString(arr[i]);
        if (i + 1 < n) cout << "  |  ";
    }
    cout << "\n\n";
}

int main() {

    Card hand[] = {
        {2, 14}, // Hearts A
        {0, 3},  // Clubs 3
        {3, 13}, // Spades K
        {1, 10}, // Diamonds 10
        {2, 2},  // Hearts 2
        {0, 14}, // Clubs A
        {3, 2},  // Spades 2
        {1, 11}  // Diamonds J
    };
    int n = sizeof(hand) / sizeof(hand[0]);

    cout << "Contoh: Mengurutkan kartu remi (array) dengan Insertion Sort\n\n";
    printArray(hand, n, "Kartu sebelum diurutkan:");

    int totalComparisons = 0;
    int totalShifts = 0;
    for (int i = 1; i < n; ++i) {
        Card key = hand[i];          
        int j = i - 1;               

        while (j >= 0 && ( ++totalComparisons, cardLess(key, hand[j]) )) {
            hand[j + 1] = hand[j];   
            totalShifts++;
            j--;
        }

        hand[j + 1] = key;         
    }

    printArray(hand, n, "Kartu setelah diurutkan (Insertion Sort):");
    cout << "Statistik sederhana: total comparisons (evaluasi kondisi) ~= " << totalComparisons
         << ", total shifts = " << totalShifts << "\n";

    return 0;
}
