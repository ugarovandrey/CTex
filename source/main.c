#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "TEX/tex.h"
#include "MATRIX/matrix.h"
#include "ARRAY/array.h"



//Функции, связанные с реализацией МиниМакса
void algoryth_MinMax(FILE *TEX_document, double **array_matrix, int var_columns, int var_rows);
void func_MiniMax_output (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows, \
						  double var_alpha, double var_beta, int var_alpha_index, int var_beta_index);

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

void algoryth_MinMax (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows){
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
	
	func_MiniMax_output (TEX_document, array_matrix, var_columns, var_rows, \
						 var_alpha, var_beta, var_alpha_index, var_beta_index);

	free (array_min_in_rows);
	free (array_max_in_columns);
}

void func_MiniMax_output (FILE *TEX_document, double **array_matrix, int var_columns, int var_rows, \
						  double var_alpha, double var_beta, int var_alpha_index, int var_beta_index)
{
	/* Вывод в *.tex-файл матрицы	*/

	if (TEX_document != NULL){
		fprintf (TEX_document, "Исходная матрица имеет вид: \n");
		func_TEX_matrix_output (TEX_document, array_matrix, var_columns, var_rows);
		func_TEX_number_output (TEX_document, var_alpha_index);
		fprintf (TEX_document, " строчка  - стратегия максмина \n"); 
		func_TEX_number_output (TEX_document, var_beta_index);
		fprintf (TEX_document, " столбец  - стратегия минимакса \n"); 
		if (var_alpha  == var_beta)
		{
			func_TEX_number_output_int (TEX_document, var_alpha_index);	
			fprintf (TEX_document, " строчка, ");
			func_TEX_number_output_int (TEX_document, var_beta_index);
			fprintf (TEX_document, " столбец  - оптимальное решение игры \n"); 
		}
		
	}
}


	
