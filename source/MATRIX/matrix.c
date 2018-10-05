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