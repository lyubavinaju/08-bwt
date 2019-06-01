//
// Created by Елена Любавина on 2019-05-30.
//

#ifndef UNTITLED7_MOVE_TO_FRONT_H
#define UNTITLED7_MOVE_TO_FRONT_H


#include "bwt.h"


struct MoveToFront {
    // Этап кодирования
    void encode(std::istream &input, std::ostream &output);

    // Этап декодирования
    void decode(std::istream &input, std::ostream &output);
};

#endif //UNTITLED7_MOVE_TO_FRONT_H
