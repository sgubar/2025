#ifndef LIST_H
#define LIST_H

#include <list>
#include "pentagon.h"

class SquareList {
    std::list<Square> squares;
public:
    void addSquare(const Square& s);
    void drawAll() const;
    void sortBeforeMax();
};

#endif
