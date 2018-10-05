#include "matrix.c"

//Функции по работе с матрицей
double** func_memory_allocation(FILE *file_input_file, int var_columns, int var_rows );
void func_memory_free(double** array_matrix, int var_columns);
void func_matrix_input (FILE *file_input_file, double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen (double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen_table (double **array_matrix, int var_columns, int var_rows);

