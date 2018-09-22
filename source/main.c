#include <stdio.h>
#include <string.h>
#include <malloc.h>

void algoryth_MinMax(double **array_matrix);

double** func_memory_allocation(FILE *file_input_file, int var_columns, int var_rows ){
		double** array_input_matrix;
		array_input_matrix = (double **)malloc(sizeof(double*)*var_columns);
		for (int i = 0; i < var_columns; i++)
		{
			array_input_matrix [i] = (double*)malloc(sizeof(double)*var_rows);
		}
		return array_input_matrix;
}

void func_memory_free(double** array_matrix, int var_columns){
		for (int i = 0; i < var_columns; i++)
			free(array_matrix [i]);
		free(array_matrix);
}


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
		func_memory_free (array_input_matrix, var_columns);
	}
	else
	{
		printf ("No input file in this directory. \nAborting... \n");
	}	
	fclose(file_input_file);
	return 0;
}
