/*  
    First occurrence P84219

    Write an efficient function
     int first_occurrence(double x, const vector<double>& v);
    that returns the position of the first occurrence of x in the vector v. 
    If x does not belong to v, return a -1.

    Precondition

    The vector v is sorted in nondecreasing order.

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

    if (midlle - 1 >= 0) {
        int repeating = position(x, v, left, midlle - 1);
        if (repeating != -1) {
            return repeating;
        }
    }

	return midlle;
}

int first_occurrence(double x, const vector<double>& v) {
    int left = 0;
    int right = v.size();
    right -= 1;
 
    return position(x, v, left, right);
}