/*  
    Resistant dichotomic search P33412

    Write an efficient function

     bool resistant_search(double x, const vector<double>& v);
    that tells if x belongs to the vector v or not.

    Precondition

    The vector v is “almost sorted” in nondecreasing order, 
    in the sense that there may be at most a pair of indices i and j 
    such that 0 ≤ i < j < n and V[i] > V[j].

    Observation You only need to submit the required procedure; 
    your main program will be ignored.

    Tomas Musius

*/

#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v) {
    
    if (v.size() == 0) {
        return false;
    }
    int left = 0, right = v.size() - 1, middle;
    
    
    while (left + 1 < right) {
        middle = (right + left)/2;
        if (v[middle] == x or v[middle + 1] == x or v[middle - 1] == x) {
            return true; 
        }
        else if (v[middle] > x) {
            right = middle;
        }
        else {
            left = middle;
        }
    }
    
    if (v[right] == x) {
        return true;
    }
    else if (v[left] == x) {
        return true;
    }
    else {
        return false;
    }
}