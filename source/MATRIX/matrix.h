#include "matrix.c"

//Функции по работе с матрицей

char** func_memory_allocation_char (FILE *file_input_file, int var_columns, int var_rows );
int** func_memory_allocation_int (FILE *file_input_file, int var_columns, int var_rows );
double** func_memory_allocation_double (FILE *file_input_file, int var_columns, int var_rows );

void func_memory_free_char(char** array_matrix, int var_columns);
void func_memory_free_int(int** array_matrix, int var_columns);
void func_memory_free_double(double** array_matrix, int var_columns);

void func_matrix_input (FILE *file_input_file, double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen (double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen_table (double **array_matrix, int var_columns, int var_rows);

#define func_memory_free(param1, param2) \
	_Generic ((param1), \
	int**: func_memory_free_int,\
	double**: func_memory_free_double, \
	char**: func_memory_free_char, \
	default: func_memory_free_char \
)(param1, param2)
