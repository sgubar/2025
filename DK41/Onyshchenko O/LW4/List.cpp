#include "List.h"
#include <algorithm>
#include <vector>

void SquareList::addSquare(const Square& s) {
    squares.push_back(s);
}

void SquareList::drawAll() const {
    for (const auto& s : squares) {
        s.draw();
    }
}

void SquareList::sortBeforeMax() {
    if (squares.empty()) return;

    // Знаходимо максимальний елемент
    auto maxIt = squares.begin();
    for (auto it = squares.begin(); it != squares.end(); ++it) {
        if (it->size > maxIt->size) {
            maxIt = it;
        }
    }

    // Сортуємо елементи перед максимальним
    std::vector<Square> temp;
    for (auto it = squares.begin(); it != maxIt; ++it) {
        temp.push_back(*it);
    }

    std::sort(temp.begin(), temp.end(), [](const Square& a, const Square& b) {
        return a.size < b.size;
    });

    auto it = squares.begin();
    for (const auto& s : temp) {
        *it = s;
        ++it;
    }
}
