/*  
    Modular exponentiation P29212

    Write a program that, given n, k and m, computes nk modm.

    Input

    Input consists of several cases, each one with three natural numbers n, k and m. 
    Assume 2 ≤ n ≤ 30000 and 2 ≤ m ≤ 30000.

    Output

    For every case, print nk modm.

    Tomas Musius

*/

#include <iostream>
using namespace std;

int calculateExp(int n, int k, int m) {
    if (n > 30000) {
        return 1;
    }
    if (n < 2) {
        return 1;
    }
    if (m > 30000) {
        return 1;
    }
    if (m < 2) {
        return 1;
    }
	if (k == 0) {
        return 1;
    }
	if (k <= 1) {
        return n % m;
    }
	else {
		int x = calculateExp(n, k / 2, m ) % m;
		if (k % 2 == 0) {
            return (x * x) % m;
        }
		else {
            return (((x * x) % m) * n) % m;
        }
	}
}

int main() {
	int n, k, m;
	while (cin >> n >> k >> m) {
		int result;
		result = calculateExp(n, k, m);
		cout << result << endl;
	}
}