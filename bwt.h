//
// Created by Елена Любавина on 2019-05-30.
//

#ifndef UNTITLED7_BWT_H
#define UNTITLED7_BWT_H

#include "circular_suffix_array.h"
#include "iostream"
#include "fstream"
struct BWT {
    // Преобразование Барроуза-Уилера, этап кодирования
    void transform(std::istream &input, std::ostream &output);

    // Обратное преобразование Барроуза-Уилера, этап декодирования
    void inverseTransform(std::istream &input, std::ostream &output);
};

#endif //UNTITLED7_BWT_H
