#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Vuzol* stvorytyVuzol(int znach) {
    Vuzol* noviyVuzol = (Vuzol*)malloc(sizeof(Vuzol));
    if (noviyVuzol == NULL) {
        printf("Помилка виділення пам'яті.\n");
        exit(1);
    }
    noviyVuzol->znachennya = znach;
    noviyVuzol->liviy = NULL;
    noviyVuzol->praviy = NULL;
    return noviyVuzol;
}

Vuzol* dodaty(Vuzol* koreni, int znach) {
    if (koreni == NULL) {
        return stvorytyVuzol(znach);
    }
    
    if (znach < koreni->znachennya) {
        koreni->liviy = dodaty(koreni->liviy, znach);
    } else if (znach > koreni->znachennya) {
        koreni->praviy = dodaty(koreni->praviy, znach);
    }
    
    return koreni;
}

void symetrychnyyObhid(const Vuzol* koreni) {
    if (koreni != NULL) {
        symetrychnyyObhid(koreni->liviy);
        printf("%d ", koreni->znachennya);
        symetrychnyyObhid(koreni->praviy);
    }
}

Vuzol* poshuk(Vuzol* koreni, int znach) {
    if (koreni == NULL || koreni->znachennya == znach) {
        return koreni;
    }
    
    if (znach < koreni->znachennya) {
        return poshuk(koreni->liviy, znach);
    }
    
    return poshuk(koreni->praviy, znach);
}

Vuzol* znajtyMin(Vuzol* vuzol) {
    Vuzol* potochniy = vuzol;
    while (potochniy && potochniy->liviy != NULL) {
        potochniy = potochniy->liviy;
    }
    return potochniy;
}

Vuzol* vydalytyVuzol(Vuzol* koreni, int znach) {
    if (koreni == NULL) return koreni;
    
    if (znach < koreni->znachennya) {
        koreni->liviy = vydalytyVuzol(koreni->liviy, znach);
    } else if (znach > koreni->znachennya) {
        koreni->praviy = vydalytyVuzol(koreni->praviy, znach);
    } else {
        if (koreni->liviy == NULL) {
            Vuzol* tymchasovyy = koreni->praviy;
            free(koreni);
            return tymchasovyy;
        } else if (koreni->praviy == NULL) {
            Vuzol* tymchasovyy = koreni->liviy;
            free(koreni);
            return tymchasovyy;
        }
        
        Vuzol* tymchasovyy = znajtyMin(koreni->praviy);
        koreni->znachennya = tymchasovyy->znachennya;
        koreni->praviy = vydalytyVuzol(koreni->praviy, tymchasovyy->znachennya);
    }
    return koreni;
}

void vydalytyDerevo(Vuzol* koreni) {
    if (koreni == NULL) return;
    
    vydalytyDerevo(koreni->liviy);
    vydalytyDerevo(koreni->praviy);
    free(koreni);
}

int vvestyTsile(const char* zapyt) {
    int znach;
    char bufer[100];
    
    while (1) {
        printf("%s", zapyt);
        if (fgets(bufer, sizeof(bufer), stdin) == NULL) {
            printf("Помилка читання вводу.\n");
            continue;
        }
        
        if (sscanf(bufer, "%d", &znach) == 1) {
            return znach;
        }
        
        printf("Невірний формат. Будь ласка, введіть ціле число.\n");
    }
}
