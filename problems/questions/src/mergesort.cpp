#include <set>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> output(left.size() + right.size(), 0);
    int l = 0;
    int r = 0;
    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            output[l+r] = left[l];
            l++;
        } else {
            output[l+r] = right[r];
            r++;
        }
    }

    while (l < left.size()) {
        output[l+r] = left[l];
        l++;
    }
    while (r < right.size()) {
        output[l+r] = right[r];
        r++;
    }
    return output;
}

vector<int> mergesort(vector<int> a) {
    if (a.size() < 2) {
        return a;
    }

    int pivot = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + pivot);
    vector<int> right(a.begin() + pivot, a.end());

    left = mergesort(left);
    right = mergesort(right);

    return merge(left, right);
}

void test_mergesort(vector<int> a) {
    auto b = mergesort(a);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << " => ";
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    test_mergesort({});
    test_mergesort({1});
    test_mergesort({1,2});
    test_mergesort({2,1});
    test_mergesort({1,2,3,4});
    test_mergesort({4,3,2,1});
    test_mergesort({1,2,3,4,5});
    test_mergesort({5,4,3,2,1});
    test_mergesort({3,4,5,2,1,4,7});
    test_mergesort({-1});
    test_mergesort({-1,-2});
    test_mergesort({1,1,1});
    test_mergesort({1,1,1,2,2});
    test_mergesort({1,1,1,2,2,3,3});
    test_mergesort({1,3,3,2,1,1,3});
    return 0;
}
