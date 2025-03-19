#include "func.h"

int main() {
    int A, B, C;
    get_input(&A, &B, &C);
    double result = Q(A, B, C);
    printf("Q: %lf\n", result);

    clear_variables(&A, &B, &C);
    return 0;
}
