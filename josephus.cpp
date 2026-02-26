#include <iostream>
using namespace std;

// Recursive Josephus function
int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n = 7; // number of people
    int k = 3; // step count
    int survivor = josephus(n, k);
    cout << "The survivor is at position: " << survivor + 1 << endl;
    return 0;
}