#include <stdio.h>
#include <string.h>
#include <malloc.h>

void algoryth_MinMax(double **array_matrix, int var_columns, int var_rows);

void TEX_matrix_output (double **array_matrix, int var_columns, int var_rows);

double** func_memory_allocation(FILE *file_input_file, int var_columns, int var_rows );
void func_memory_free(double** array_matrix, int var_columns);
void func_matrix_input (FILE *file_input_file, double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen (double **array_matrix, int var_columns, int var_rows);
void func_matrix_output_screen_column (double **array_matrix, int var_columns, int var_rows);
double func_array_minimal (double* array, int n);
double func_array_maximal (double* array, int n);

int main(){

	FILE *file_input_file;
	
	char* string_input_file = "input.mtrx";
	
	double **array_input_matrix;
	int var_columns, var_rows, var_current_column, var_current_row;

	//double *array_max_in_rows, *array_min_in_rows;
	double *array_max_in_columns, *array_min_in_columns;
		
	if ((file_input_file = fopen(string_input_file, "r")) != NULL){
		fscanf (file_input_file, "%d", &var_columns);
		fscanf (file_input_file, "%d", &var_rows);
		array_input_matrix = func_memory_allocation(file_input_file, var_columns, var_rows);	
		func_matrix_input(file_input_file, array_input_matrix, var_columns, var_rows);	
		//func_matrix_output_screen (array_input_matrix, var_columns, var_rows);
		algoryth_MinMax(array_input_matrix, var_columns, var_rows);
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
				printf ("%0.2lf ",array_matrix[i][j]); 	
			}
			printf ("\n");
	}
}

void func_matrix_output_screen_table (double **array_matrix, int var_columns, int var_rows){
		for (int i = 0; i < var_rows; i++)
			for (int j = 0; j < var_columns; j++)
			{
				printf ("[%d][%d] = %0.2lf\n", i, j, array_matrix[i][j]); 	
			}
}

void algoryth_MinMax (double **array_matrix, int var_columns, int var_rows){
	double var_alpha, var_beta;
	double var_current_alpha;

	double *array_min_in_rows, *array_max_in_columns;

	array_min_in_rows = (double *)malloc(sizeof(double)*var_rows);
	array_max_in_columns = (double *)malloc(sizeof(double)*var_rows);

	int var_alpha_row, var_alpha_column;
	int var_beta_row, var_beta_column;
	
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
	var_alpha = func_array_maximal (array_min_in_rows, var_rows);
	printf ("%lf", var_alpha);
	free (array_min_in_rows);
	free (array_max_in_columns);
}

double func_array_minimal (double* array, int n){
	double min = array [0];
	for (int i = 0; i < n; i++)
	{
		if (array [i] < min)
			min = array [i];
	}
	return min;
}

double func_array_maximal (double* array, int n){
	double min = array [0];
	for (int i = 0; i < n; i++)
	{
		if (array [i] >	 min)
			min = array [i];
	}
	return min;
}

	