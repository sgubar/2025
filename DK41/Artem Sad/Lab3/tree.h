#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct Vuzol {
    int znachennya;
    struct Vuzol* liviy;
    struct Vuzol* praviy;
} Vuzol;

Vuzol* stvorytyVuzol(int znach);
Vuzol* dodaty(Vuzol* koreni, int znach);
void symetrychnyyObhid(const Vuzol* koreni);
Vuzol* poshuk(Vuzol* koreni, int znach);
Vuzol* znajtyMin(Vuzol* vuzol);
Vuzol* vydalytyVuzol(Vuzol* koreni, int znach);
void vydalytyDerevo(Vuzol* koreni);
int vvestyTsile(const char* zapyt);

#endif
