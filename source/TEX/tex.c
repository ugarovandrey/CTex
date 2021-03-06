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

void func_TEX_matrix_output_int (FILE *TEX_output_file, int **array_matrix, int var_columns, int var_rows){
	// Почти любая функция, связанная в печатью в ТЕХ начинается с отбития пустой строки. 
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++){
			for (int j = 0; j < var_columns; j++)
			{
				fprintf (TEX_output_file, "%d",array_matrix[i][j]); 
				if (j == var_columns - 1)
					fprintf (TEX_output_file, "\\\\"); 
				else
					fprintf (TEX_output_file, "&"); 
			}
			fprintf (TEX_output_file, "\n");
	}
	fprintf (TEX_output_file, "\\end{pmatrix}$$\n");
}
void func_TEX_matrix_output_double (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows){
	// Почти любая функция, связанная в печатью в ТЕХ начинается с отбития пустой строки. 
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
void func_TEX_matrix_output_char (FILE *TEX_output_file, char **array_matrix, int var_columns, int var_rows){
	// Почти любая функция, связанная в печатью в ТЕХ начинается с отбития пустой строки. 
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++){
			for (int j = 0; j < var_columns; j++)
			{
				fprintf (TEX_output_file, "%c",array_matrix[i][j]); 
				if (j == var_columns - 1)
					fprintf (TEX_output_file, "\\\\"); 
				else
					fprintf (TEX_output_file, "&"); 
			}
			fprintf (TEX_output_file, "\n");
	}
	fprintf (TEX_output_file, "\\end{pmatrix}$$\n");
}

void func_TEX_number_output_int (FILE *TEX_output_file, int number){
	fprintf (TEX_output_file, "\n$ %d $", number);
}
void func_TEX_number_output_double (FILE *TEX_output_file, double number){
	fprintf (TEX_output_file, "\n$ %0.2lf $", number);
}

void func_TEX_row_output_int (FILE *TEX_output_file, int **array_matrix, int var_columns, int var_rows, int output_row){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int j = 0; j < var_columns; j++)
	{
		fprintf (TEX_output_file, "%d & ",array_matrix[output_row][j]); 
	}
	fprintf (TEX_output_file, "\\\\ \n \\end{pmatrix}$$ \n");
}
void func_TEX_row_output_double (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows, int output_row){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int j = 0; j < var_columns; j++)
	{
		fprintf (TEX_output_file, "%0.2lf & ",array_matrix[output_row][j]); 
	}
	fprintf (TEX_output_file, "\\\\ \n \\end{pmatrix}$$ \n");
}
void func_TEX_row_output_char(FILE *TEX_output_file, char **array_matrix, int var_columns, int var_rows, int output_row){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int j = 0; j < var_columns; j++)
	{
		fprintf (TEX_output_file, "%c & ",array_matrix[output_row][j]); 
	}
	fprintf (TEX_output_file, "\\\\ \n \\end{pmatrix}$$ \n");
}

void func_TEX_column_output_int (FILE *TEX_output_file, int **array_matrix, int var_columns, int var_rows, int output_column){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++)
	{
		fprintf (TEX_output_file, "%d \\\\ \n",array_matrix[i][output_column]); 
	}
	fprintf (TEX_output_file, " \\end{pmatrix}$$ \n");
}

void func_TEX_column_output_double (FILE *TEX_output_file, double **array_matrix, int var_columns, int var_rows, int output_column){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++)
	{
		fprintf (TEX_output_file, "%0.2lf \\\\ \n",array_matrix[i][output_column]); 
	}
	fprintf (TEX_output_file, " \\end{pmatrix}$$ \n");
}

void func_TEX_column_output_char (FILE *TEX_output_file, char **array_matrix, int var_columns, int var_rows, int output_column){
	fprintf (TEX_output_file, "\n");
	fprintf (TEX_output_file, "$$\\begin{pmatrix}\n");
	for (int i = 0; i < var_rows; i++)
	{
		fprintf (TEX_output_file, "%c \\\\ \n",array_matrix[i][output_column]); 
	}
	fprintf (TEX_output_file, " \\end{pmatrix}$$ \n");
}