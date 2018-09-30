#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

//Функция для tex-форматирования
void func_TEX_new_document (FILE *TEX_output_file);
void func_TEX_matrix_output (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows);
void func_TEX_number_output (FILE *TEX_output_file, double number);
void func_TEX_end_document (FILE *TEX_output_file);

//Функции, связанные с реализацией МиниМакса
void algoryth_MinMax(FILE *TEX_document, double **array_matrix, int var_columns, int var_rows);
void func_MiniMax_output (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows, \
						  double var_alpha, double var_beta, int var_alpha_index, int var_beta_index,\
						  bool var_seddle_point_exist);

//Функции по работе с матрицей
double** func_memory_allocation(FILE *file_input_file, int var_columns, int var_rows );
void func_memory_free(double** array_matrix, int var_columns);
void func_matrix_input (FILE *file_input_file, double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen (double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen_table (double **array_matrix, int var_columns, int var_rows);
 
//Функции по работе с массивами
double func_array_minimal_index (double* array, int n);
double func_array_maximal_index (double* array, int n);


int main(){

	FILE *file_input_file;
	FILE *file_TEX_output;

	char* string_TEX_document_name = "output.tex";
	
	char* string_input_file = "input.mtrx";
	
	double **array_input_matrix;
	int var_columns, var_rows, var_current_column, var_current_row;

	double *array_max_in_columns, *array_min_in_columns;
		
	if ((file_input_file = fopen(string_input_file, "r")) != NULL){
		fscanf (file_input_file, "%d", &var_columns);
		fscanf (file_input_file, "%d", &var_rows);
		array_input_matrix = func_memory_allocation(file_input_file, var_columns, var_rows);	
		func_matrix_input(file_input_file, array_input_matrix, var_columns, var_rows);
		if ((file_TEX_output = fopen(string_TEX_document_name, "a")) != NULL){
			func_TEX_new_document(file_TEX_output);
			algoryth_MinMax(file_TEX_output, array_input_matrix, var_columns, var_rows);
			func_TEX_end_document(file_TEX_output);
			fclose(file_TEX_output);
		}
		else
		{
			printf ("Can't create an output file. \nAborting... \n");	
		}
		func_memory_free (array_input_matrix, var_rows);	
	}
	else
	{
		printf ("No input file in this directory. \nAborting... \n");
	}	
	fclose(file_input_file);
	return 0;
}


double** func_memory_allocation(FILE *file_input_file, int var_columns, int var_rows ){
		double** array_input_matrix;
		array_input_matrix = (double **)malloc(sizeof(double*)*var_rows);
		for (int i = 0; i < var_rows; i++)
		{
			array_input_matrix [i] = (double*)malloc(sizeof(double)*var_columns);
		}
		return array_input_matrix;
}

void func_memory_free(double** array_matrix, int var_rows){
		for (int i = 0; i < var_rows; i++)
			free(array_matrix [i]);
		free(array_matrix);
}

void func_matrix_input (FILE *file_input_file, double **array_matrix, int var_columns, int var_rows){
	if (file_input_file != NULL){
		for (int i = 0; i < var_rows; i++)
			for (int j = 0; j < var_columns; j++)
			{
				fscanf (file_input_file, "%lf", &array_matrix [i] [j]);
				//printf ("[%d][%d] = %lf\n", i, j, array_matrix[i][j]); 	
			}
	}
	else
		printf ("Input file doesn't exist!\n");
	return;
}

void func_matrix_output_screen (double **array_matrix, int var_columns, int var_rows){
	for (int i = 0; i < var_rows; i++){
			for (int j = 0; j < var_columns; j++)
			{
				printf ("%.2lf ",array_matrix[i][j]); 	
			}
			printf ("\n");
	}
}

void func_matrix_output_screen_table (double **array_matrix, int var_columns, int var_rows){
		for (int i = 0; i < var_rows; i++)
			for (int j = 0; j < var_columns; j++)
			{
				printf ("[%d][%d] = %5.2lf\n", i, j, array_matrix[i][j]); 	
			}
}

void algoryth_MinMax (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows){
	/* 
		TODO: необходимо избавиться от вспомогательных массивов (array_min_in_rows, array_max_in_columns).
		Считать максимум(минимум) можно прямо в цикле.
	*/
	bool var_seddle_point_exist = false;
	int var_alpha_index, var_beta_index;
	double var_alpha, var_beta;
	double var_current_alpha, var_current_beta;
	double *array_min_in_rows, *array_max_in_columns;

	array_min_in_rows = (double *)malloc(sizeof(double)*var_rows);
	array_max_in_columns = (double *)malloc(sizeof(double)*var_columns);
	
	// Определение стратегии МаксМина.
	//1. Ищем минимумы в строках.
	for (int i = 0; i < var_rows; i ++){
		var_current_alpha = array_matrix[i][0];
		for (int j = 0; j < var_columns; j++){
			if (var_current_alpha > array_matrix [i] [j])
				var_current_alpha = array_matrix [i] [j];
		}
		array_min_in_rows [i] = var_current_alpha;
	}
	//2. Выбираем максимум из минимума.
	// Запоминаем именно индекс, т.к. благодаря этому мы сможем указать строку.

	var_alpha_index = func_array_maximal_index (array_min_in_rows, var_rows);
	var_alpha = array_min_in_rows [var_alpha_index];

	// Определение стратегии МиниМакса.
	//1. Ищем максимумы в строках.
	for (int j = 0; j < var_columns; j ++){
		var_current_beta = array_matrix[0][j];
		for (int i = 0; i < var_rows; i++){
			if (var_current_beta < array_matrix [i] [j])
				var_current_beta = array_matrix [i] [j];
		}
		array_max_in_columns [j] = var_current_beta;
	}
	//2. Выбираем минимум из максимума.
	var_beta_index = func_array_minimal_index (array_max_in_columns, var_columns);
	var_beta = array_max_in_columns [var_beta_index];
	//Проверяем, не являются ли полученные результаты седловой точкой.

	if (var_alpha == var_beta)
		var_seddle_point_exist = true;
	
	func_MiniMax_output (TEX_document, array_matrix, var_columns, var_rows, \
						 var_alpha, var_beta, var_alpha_index, var_beta_index, \
						 var_seddle_point_exist);

	free (array_min_in_rows);
	free (array_max_in_columns);
}

void func_MiniMax_output (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows, \
						  double var_alpha, double var_beta, int var_alpha_index, int var_beta_index,\
						  bool var_seddle_point_exist)
{
	/* Вывод в *.tex-файл матрицы	*/

	if (TEX_document != NULL){
		if (var_seddle_point_exist == true)
		{
			fprintf (TEX_document, "Исходная матрица имеет вид: \n");
		}
		func_TEX_matrix_output (TEX_document, array_matrix, var_columns, var_rows);
	}
}
	
double func_array_minimal_index (double* array, int n){
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] < array [min_index]){
			min_index = i;
		}
	}
	return min_index;
}

double func_array_maximal_index (double* array, int n){
	int max_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] > array[max_index]){
			max_index = i;
		}
	}
	return max_index;
}

void func_TEX_new_document (FILE *TEX_output_file){
	fprintf (TEX_output_file, "\\documentclass{article}\n");
	fprintf (TEX_output_file, "\\usepackage[utf8]{inputenc}\n");
	fprintf (TEX_output_file, "\\usepackage[russian]{babel}\n");
	fprintf (TEX_output_file, "\\usepackage{amsmath}\n");
	fprintf (TEX_output_file, "\\begin{document}\n");

}
void func_TEX_end_document (FILE *TEX_output_file){
		fprintf (TEX_output_file, "\\end{document}\n");
}

void func_TEX_matrix_output (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows){
	// Любая функция, связанная в печатью в ТЕХ начинается с отбития пустой строки.array_matrix
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++){
			for (int j = 0; j < var_columns; j++)
			{
				fprintf (TEX_output_file, "%0.2lf",array_matrix[i][j]); 
				if (j == var_columns - 1)
					fprintf (TEX_output_file, "\\\\"); 
				else
					fprintf (TEX_output_file, "&"); 
			}
			fprintf (TEX_output_file, "\n");
	}
	fprintf (TEX_output_file, "\\end{pmatrix}$$\n");
}
