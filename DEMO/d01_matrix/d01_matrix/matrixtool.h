//
//  matrixtool.h
//  d01_matrix
//
//  Created by Slava Gubar on 09.02.2024.
//

#ifndef matrixtool_h
#define matrixtool_h

int sum_elements_of_matrix_3(int m[][3]);
int sum_elements_of_matrix(int *matrix, int nrow, int ncol);

// create matrix
int *create_matrix(int nrow, int ncol);
void destroy_matrix(int *matrix);

// print matrix
void print_matrix(int *matrix, int nrow, int ncol);

void fill_matrix(int *matrix, int nrow, int ncol);


int my_strlen(char *str);

#endif /* matrixtool_h */
