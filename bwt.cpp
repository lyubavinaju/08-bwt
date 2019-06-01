//
// Created by Елена Любавина on 2019-05-29.
//
#include "bwt.h"


void BWT::transform(std::istream &input, std::ostream &output) {
    std::string s;
    input >> s;
    CircularSuffixArray suffArray(s);
    int zeroIndex = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (suffArray[i] == 0) {
            zeroIndex = i;
        }
    }
    output << zeroIndex << "\n";
    for (int i = 0; i < s.length(); ++i) {
        int start_Index = suffArray[i];
        int end_Index = (start_Index + s.length() - 1) % s.length();
        output << s[end_Index];
    }
    output << std::endl;
}

void BWT::inverseTransform(std::istream &input, std::ostream &output) {
    int first;
    input >> first;
    std::string t;
    input >> t;
    std::vector<char> sorted_t(t.length()); //first column
    for (int i = 0; i < t.length(); ++i) {
        sorted_t[i] = t[i];
    }
    std::sort(sorted_t.begin(), sorted_t.end());
    std::vector<int> cur(alphabet, -1);
    for (int j = 0; j < sorted_t.size(); ++j) {
        char ch = sorted_t[j];
        if (cur[ch] == -1)cur[ch] = j;
    }
    std::vector<int> next(t.length());
    for (int i = 0; i < t.length(); ++i) {
        char ch = t[i];
        int sorted_index = cur[ch];
        next[sorted_index] = i;
        cur[ch]++;
    }
    for (int i = first; next[i] != first; i = next[i]) {
        output << sorted_t[i];
    }
    output << t[first] << std::endl;
}

