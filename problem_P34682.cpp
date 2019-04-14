/*  
    Fixed points P34682

    Let S = x1, …, xn be a sequence of integer numbers such that x1 < … < xn. 
    For every integer number a and every index 1 ≤ i ≤ n, define fa(i) = xi + a. 
    Write a program that, given S and a, tells whether there is some i such that fa(i) = i.

    Input

    Input consists of several cases. Every case begins with n, followed by S, 
    followed by a number m, followed by m different integer numbers a1, …, am. 
    Assume 1 ≤ n ≤ 106.

    Output

    For every case, print its number starting at 1. Afterwards, for every aj print 
    the position of its fixed point. If no fixed point exists, state so. 
    If there is more than one fixed point, print the smallest one. 
    Print a blank line after the output for every case.

    Tomas Musius

*/

#include <iostream>
#include <vector>
using namespace std;
 
 
int fixed_point(int a, const vector<int>& v, int left, int right) {
	if (left > right) {
        return -1;
    }
	int middle = (left + right) / 2;
	if (v[middle] + a > middle + 1) {
        return fixed_point(a, v, left, middle - 1);
    }
	else if (v[middle] + a < middle + 1) {
        return fixed_point(a, v, middle + 1, right);
    }
    else if (v[middle] + a == middle + 1 and middle != 0 and v[middle-1] + a == middle) {
        return fixed_point(a, v, left, middle - 1);
    }
	return middle + 1;
}

int main() {
	int n, sequence;
	sequence = 1;
	while (cin >> n) {
		cout << "Sequence #" 
             << sequence 
             << endl;
		vector<int> v(n);
		int m;
		for (int i = 0; i < n; ++i) cin >> v[i];
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, fixed;
			cin >> a;
			fixed = fixed_point(a, v, 0, n-1);
			if (fixed == -1) cout << "no fixed point for " << a;
			else cout << "fixed point for " 
                      << a 
                      << ": " 
                      << fixed;
			cout << endl;
		}
		++sequence;
		cout << endl;
	}
}