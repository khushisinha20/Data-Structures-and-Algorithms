#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 1) {
        cout << "Disk " << 1 << " moved from " << source << " to " << destination << '\n';
        return;
    }
    towerOfHanoi(n - 1, source, destination, helper);
    cout << "Disk " << n << " moved from " << source << " to " << destination << '\n';
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
	int n;
	cin >> n;
	char source = 'A';
	char helper = 'B';
	char destination = 'C';
	towerOfHanoi(n, source, helper, destination);
}
