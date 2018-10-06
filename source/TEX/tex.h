#include "tex.c"
//Функция для tex-форматирования

//Начало и конце документ
void func_TEX_new_document (FILE *TEX_output_file);
void func_TEX_end_document (FILE *TEX_output_file);

/*  --- --- --- --- --- --- --- --- --- ------ --- --- ---
    --- --- --- --- --- = Печать матрицы = --- --- --- ---  
    --- --- --- --- --- --- --- --- --- ------ --- --- ---  */
void func_TEX_matrix_output_int (FILE *TEX_output_file, int **array_matrix, int var_columns, int var_rows);
void func_TEX_matrix_output_double (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows);
void func_TEX_matrix_output_char (FILE *TEX_output_file, char **array_matrix, int var_columns, int var_rows);
#define func_TEX_matrix_output(param1, param2, param3, param4) \
	_Generic ((param2), \
	int**: func_TEX_matrix_output_int,\
	double**: func_TEX_matrix_output_double, \
	char**: func_TEX_matrix_output_char,\
	default: func_TEX_matrix_output_double \
)(param1, param2, param3, param4)

/*  --- --- --- --- --- --- --- --- --- ------ --- --- ---
    --- --- --- --- --- = Печать столбца = --- --- --- ---  
    --- --- --- --- --- --- --- --- --- ------ --- --- ---  */
void func_TEX_row_output_int (FILE *TEX_output_file, int **array_matrix, \
							  int var_columns, int var_rows, int output_row);
void func_TEX_row_output_double (FILE *TEX_output_file, double **array_matrix, \
							  int var_columns, int var_rows, int outputed_row);
void func_TEX_row_output_char (FILE *TEX_output_file, char **array_matrix, \
							  int var_columns, int var_rows, int outputed_row);

#define func_TEX_row_output(FILE, matrix, columns, rows, row) \
	_Generic((matrix),\
	int**: func_TEX_row_output_int,\
	double**: func_TEX_row_output_double,\
	char**: func_TEX_row_output_char,\
	default: func_TEX_row_output_char \
)(FILE, matrix, columns, rows, row)

/*  --- --- --- --- --- --- --- --- --- ------ --- --- ---
    --- --- --- --- --- = Печать  строки = --- --- --- ---  
    --- --- --- --- --- --- --- --- --- ------ --- --- ---  */
void func_TEX_column_output_int (FILE *TEX_output_file, int **array_matrix, \
							  int var_columns, int var_rows, int output_column);
void func_TEX_column_output_double (FILE *TEX_output_file, double **array_matrix, \
							  int var_columns, int var_rows, int output_column);
void func_TEX_column_output_char (FILE *TEX_output_file, char **array_matrix, \
							  int var_columns, int var_rows, int output_column);

#define func_TEX_column_output(FILE, matrix, columns, rows, column) \
	_Generic((matrix), \
	int**: func_TEX_column_output_int,\
	double**: func_TEX_column_output_double,\
	char**: func_TEX_column_output_char,\
	default: func_TEX_column_output_char \
)(FILE, matrix, columns, rows, column)

/*  --- --- --- --- --- --- --- --- --- ------ --- --- ---
    --- --- --- --- --- =  Печать числа  = --- --- --- ---  
    --- --- --- --- --- --- --- --- --- ------ --- --- ---  */
void func_TEX_number_output_double (FILE *TEX_output_file, double number);
void func_TEX_number_output_int (FILE *TEX_output_file, int number);

#define func_TEX_number_output(X, Y) \
	_Generic ((Y), \
	int: func_TEX_number_output_int,\
	double: func_TEX_number_output_double, \
	default: func_TEX_number_output_double \
)(X, Y)


