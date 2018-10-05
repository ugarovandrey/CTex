#include "tex.c"
//Функция для tex-форматирования
void func_TEX_new_document (FILE *TEX_output_file);
void func_TEX_matrix_output_int (FILE *TEX_output_file, int **array_matrix, int var_columns, int var_rows);
void func_TEX_matrix_output_double (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows);
void func_TEX_number_output_double (FILE *TEX_output_file, double number);
void func_TEX_number_output_int (FILE *TEX_output_file, int number);
void func_TEX_end_document (FILE *TEX_output_file);

#define func_TEX_number_output(X, Y) \
	_Generic ((Y), \
	int: func_TEX_number_output_int,\
	double: func_TEX_number_output_double, \
	default: func_TEX_number_output_int \
)(X, Y)

#define func_TEX_matrix_output(W, X, Y, Z) \
	_Generic ((Y), \
	int**: func_TEX_matrix_output_int,\
	double**: func_TEX_matrix_output_double, \
	default: func_TEX_matrix_output_double \
)(W, X, Y, Z) 

