//
// Created by Елена Любавина on 2019-05-30.
//
#include "circular_suffix_array.h"


CircularSuffixArray::CircularSuffixArray(const std::string &input) :
        n(input.length()), p(n) {
    std::vector<int> cnt(alphabet, 0);
    for (int i = 0; i < n; ++i) {
        cnt[input[i]]++;
    }
    for (int j = 1; j < alphabet; ++j) {
        cnt[j] += cnt[j - 1];
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i)
        p[--cnt[input[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (input[p[i]] != input[p[i - 1]]) ++classes;
        c[p[i]] = classes - 1;
    }
    std::vector<int> pn(n);
    std::vector<int> cn(n);

    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        for (int i = 0; i < classes; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i)
            ++cnt[c[pn[i]]];
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes - 1;
        }
        for (int i = 0; i < n; ++i) {
            c[i] = cn[i];
        }
    }

}


size_t CircularSuffixArray::size() const {
    return n;
}

size_t CircularSuffixArray::operator[](size_t index) const {
    return p[index];
}

void CircularSuffixArray::print() const {
    for (int k: p) {
        std::cout << k << " ";
    }
    std::cout << "\n";
}

