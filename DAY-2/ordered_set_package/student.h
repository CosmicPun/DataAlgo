#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v.reserve(A.size() + B.size());
    unordered_set<T> seen;
    seen.reserve(A.size() + B.size());

    for (size_t i = 0; i < A.size(); ++i) {
        v.push_back(A[i]);
        seen.insert(A[i]);
    }
    for (size_t j = 0; j < B.size(); ++j) {
        if (seen.find(B[j]) == seen.end()) {
            v.push_back(B[j]);
            seen.insert(B[j]);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> inB;
    inB.reserve(B.size());
    for (size_t j = 0; j < B.size(); ++j) inB.insert(B[j]);
    for (size_t i = 0; i < A.size(); ++i) {
        if (inB.find(A[i]) != inB.end()) v.push_back(A[i]);
    }
    return v;
}
