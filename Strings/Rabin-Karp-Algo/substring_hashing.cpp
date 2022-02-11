#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long hash_value[1000001];
long long inv[1000001];

long long power(long long a, long long n) {
    long long result = 1;
    while (n) {
        if (n & 1)
            result = (result * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return result; 
}

void hash_val(string s) {
    long long p = 31;
    long long power_of_p = 1;
    inv[0] = 1;
    hash_value[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < s.length(); ++i) {
        power_of_p = (power_of_p * p) % mod;
        inv[i] = power(power_of_p, mod - 2);
        hash_value[i] = (hash_value[i - 1] + (s[i] - 'a' + 1) * power_of_p) % mod;
    }
}

long long substringHash(long long l, long long r) {
    int result = hash_value[r];
    if (l > 0)
        result -= hash_value[l - 1];
    result = (result * inv[l]) % mod;
    return result;
}

int main() {
    string s;
    cin >> s;
    hash_val(s);
    long long l, r;
    cin >> l >> r;
    cout << substringHash(l, r) << '\n';
    return 0;
}