#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> sieve (int n)
{
    vector<bool> prime(n+1, true);
    prime[0] = false;
    prime[1] = false;

    for (auto i = 0; i < sqrt(n); ++i) {
        if (prime[i]) {
            for (auto j = i * 2; j < n; j+=i) {
                prime[j] = false;
            }
        }
    }

    return prime;
}

int main() {
    auto prime = sieve(5);

    cout << prime[2] << endl;

    cout << prime[4] << endl;

    return 0;
}
