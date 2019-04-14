/*  
    Dichotomic search P81966

    Write an efficient recursive function that returns the position of x in the subvector v[left..right]. 
    The function must return −1 if x does not belong to v[left..right] or if left > right.

    Precondition

    The vector v is sorted in strictly increasing order. Moreover, 
    we have 0 ≤ left ≤ size of v and −1 ≤ right < size of v.

    Interface

    C++	
     int position(double x, const vector<double>& v, int left, int right);

    Observation You only need to submit the required procedure; 
    your main program will be ignored.

    Tomas Musius

*/

#include <iostream>
#include <vector>
using namespace std;
 
int position(double x, const vector<double>& v, int left, int right) {

	if (left > right) {
        return -1;
    }

	int midlle = (left + right) / 2;

	if (x < v[midlle]) {
        return position(x, v, left, midlle - 1);
    }

	if (x > v[midlle]) {
        return position(x, v, midlle + 1, right);
    }

	return midlle;
}