#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long getHash(string s) {
    long long hash_value = 0;
    long long p = 31;
    long long power_of_p = 1;
    for (int i = 0; i < s.length(); ++i) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * power_of_p) % mod;
        power_of_p = (power_of_p * p) % mod;
    }
    return hash_value;
}

int main() {
    string s;
    cin >> s;
    cout << getHash(s) << '\n';
    return 0;
}