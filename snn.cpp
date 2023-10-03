#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
    vector<int> primes(n+1, 1);
    for (int p = 2; p*p <= n; p++) {
        if (primes[p] == 1) {
            for (int i = p*p; i <= n; i += p) {
                primes[i] = 0;
            }
        }
    }
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> primes = sieve_of_eratosthenes(n);
    cout << "Cac so nguyen to nho hon hoac bang " << n << " la:\n";
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
    return 0;
}