//
// Created by Елена Любавина on 2019-05-29.
//

#include "move_to_front.h"



void MoveToFront::encode(std::istream &input, std::ostream &output) {
    std::vector<int> chars(alphabet);
    for (int i = 0; i < alphabet; ++i) {
        chars[i] = i;
    }
    std::string s;
    input >> s;
    std::vector<int> result(s.length());
    for (int j = 0; j < s.length(); ++j) {
        char ch = s[j];
        int pos = -1;
        for (int i = 0; i < alphabet; ++i) {
            if (chars[i] == ch) {
                pos = i;
            }
        }
        result[j] = pos;

        for (int i = pos; i > 0; --i) {
            chars[i] = chars[i - 1];
        }
        chars[0] = ch;

    }
    for (int j = 0; j < s.size(); ++j) {
        output << (char) result[j];
    }
    output << std::endl;
}

void MoveToFront::decode(std::istream &input, std::ostream &output) {
    std::vector<int> chars(alphabet);
    for (int i = 0; i < alphabet; ++i) {
        chars[i] = i;
    }
    std::string s;
    input >> s;
    std::vector<int> result(s.length());
    for (int j = 0; j < s.length(); ++j) {
        int pos = s[j];
        char ch = result[j] = chars[pos];
        for (int i = pos; i > 0; --i) {
            chars[i] = chars[i - 1];
        }
        chars[0] = ch;
    }
    for (int j = 0; j < s.size(); ++j) {
        output << (char) result[j];
    }
    output << std::endl;
}


//int main() {
//    // std::string s;
//    //std::cin >> s;
//    std::string s("ABRACADABRA!");
//    CircularSuffixArray circularSuffixArray(s);
//    circularSuffixArray.print();
//    BWT bwt;
//    bwt.transform(std::cin, std::cout);
//    bwt.inverseTransform(std::cin, std::cout);
////    MoveToFront moveToFront;
////    moveToFront.encode(std::cin, std::cout);//CAAABCCCACCF -> CB  C   F
////    moveToFront.decode(std::cin, std::cout);//CB  C   F -> CAAABCCCACCF
//
//}
