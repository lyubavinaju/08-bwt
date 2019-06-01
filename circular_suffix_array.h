//
// Created by Елена Любавина on 2019-05-30.
//

#ifndef UNTITLED7_CIRCULAR_SUFFIX_ARRAY_H
#define UNTITLED7_CIRCULAR_SUFFIX_ARRAY_H

#include <iostream>
#include <vector>
#include <fstream>
const int alphabet = 256;

struct CircularSuffixArray {
    private:
    size_t n;
    std::vector<size_t> p;
public:
    // Ctor
    CircularSuffixArray(const std::string &input);

    // Returns size of the input string
    size_t size() const;

    // Returns index of suffix from original array
    size_t operator[](size_t index) const;

    void print() const;
};

#endif //UNTITLED7_CIRCULAR_SUFFIX_ARRAY_H
